#include <iostream>

#include "sort.hpp"

template <typename T>
void sort_n_display(std::vector<T> &v)
{
    std::cout << "before:";
    affiche_vector(v);

    v = tri_a_bulle(v, v.size());

    std::cout << "after:";
    affiche_vector(v);
    std::cout << "" << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> v = {3, 5, 1, 0, -2, 10};
    sort_n_display<int>(v);

    std::vector<float> v2 = {3.3, 5.2, 1.1, 0.9, -2.9, 10.4};
    sort_n_display<float>(v2);

    std::vector<char> v3 = {'a', 'z', 's', 'e', 'y', 'o'};
    sort_n_display<char>(v3);

    return 0;
}
