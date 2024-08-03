#include <iostream>

#include "mpi.h"
#include "utils.hpp"
#include "sort_common.hpp"
#include "sort_versionA.hpp"

int main(int argc, char *argv[])
{
    // setup
    int rank, nprocs;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Barrier(MPI_COMM_WORLD);

    // create vector
    std::vector<int> v = {3, 2, 1, 5};

    // compute sorting
    tri_parallele_a(v, rank, nprocs);

    // check results
    MPI_Barrier(MPI_COMM_WORLD);
    std::vector<int> trueData = {1, 2, 3, 5};
    if(rank==0){
        bool equal = isEqual(v, trueData);
        if (!equal)
        {
            // end fail
            MPI_Finalize();
            return EXIT_FAILURE;
        }   
        // end success
        MPI_Finalize();
        return EXIT_SUCCESS; 
    }
}
