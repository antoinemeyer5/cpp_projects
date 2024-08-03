#include "mpi.h"
#include <vector>

void display_and_stop(int rank, std::string message, MPI_Comm comm)
{
    if(rank == 0) std::cout << "USER ERROR: " << message << std::endl;
    MPI_Barrier(comm);
    MPI_Abort(comm, 1);
}

std::vector<int> random_vector(int size)
{
    std::vector<int> v(size);
    for (int a=0; a<size; a++) {
        v[a] = std::rand()%100; // value between 0 and 99
    }
    return v;
}

// print the vector in terminal
void display_vector(int a, std::vector<int> v)
{
    if(a == 0){
        std::cout << "Before -> [";
    } else {
        std::cout << "After -> [";
    }
    if(v.size() > 20){
        for(int i=0; i<5; i++) {
            std::cout << v[i] << ", ";
        }
        std::cout << " ... ";
        for(int i=v.size()-5; i<v.size()-1; i++) {
            std::cout << v[i] << ", ";
        }
    }else{
        for(int i=0; i<v.size()-1; i++) {
            std::cout << v[i] << ", ";
        }
    }
    std::cout << v[v.size()-1] << "]" << std::endl;
}

// compare values and switch if necessary
void compare_values(int &a, int &b)
{
    if(a < b){
        int temp = a;
        a = b;
        b = temp;
    }
}

template<typename T>
bool isEqual(std::vector<T> &first, std::vector<T> &second)
{
    if (first.size() != second.size()) {
        return false;
    }
    else{
        for(int i = 0; i < first.size(); i++){
            if(first[i] !=  second[i]){
                return false;
            }
        }
    }
    return true;
}
