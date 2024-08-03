#include <iostream>

#include "mpi.h"
#include "utils.hpp"
#include "sort_common.hpp"
#include "sort_versionB.hpp"

int main(int argc, char *argv[])
{
    // setup
    int rank, nprocs;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Barrier(MPI_COMM_WORLD);

    // create vector
    std::vector<int> v = {
        3,  2,  1,  5,  4,  12, 32, 3,  4,  9,  10, 11,
        2,  8,  58, 39, 24, 98, 0,  45, 12, 57, 55, 2
    };

    // compute sorting
    tri_parallele_b(v, rank, nprocs, 24);

    // check results
    MPI_Barrier(MPI_COMM_WORLD);
    std::vector<int> trueData = {
        0,  1,  2,  2,  2,  3,  3,  4,  4,  5,  8,  9,
        10, 11, 12, 12, 24, 32, 39, 45, 55, 57, 58, 98
    };
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
