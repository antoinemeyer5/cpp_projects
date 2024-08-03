#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring>

#include "mpi.h"
#include "utils.hpp"
#include "sort_common.hpp"
#include "sort_versionA.hpp"
#include "sort_versionB.hpp"

double starttime, endtime;

int main(int argc, char* argv[])
{
    std::srand(time(NULL));

    int rank, nprocs;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    if(argc > 3) display_and_stop(rank, "Too many arguments (two or three expected)", MPI_COMM_WORLD);
    if(argc < 2) display_and_stop(rank, "Too few arguments (two or three expected)", MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    starttime = MPI_Wtime();

    std::vector<int> v_before;
    std::vector<int> v_after;

    if(strcmp(argv[1], "version_A") == 0) {
        if(argc != 2) display_and_stop(rank, "Too many arguments (two expected)", MPI_COMM_WORLD);
        v_before = random_vector(nprocs);
        v_after = v_before;
        tri_parallele_a(v_after, rank, nprocs);

    } else if(strcmp(argv[1], "version_B") == 0) {
        if(argc != 3) display_and_stop(rank, "Too few arguments (three expected)", MPI_COMM_WORLD);
        int nelems = atoi(argv[2]);
        v_before = random_vector(nelems);
        v_after = v_before;
        tri_parallele_b(v_after, rank, nprocs, nelems);

    } else display_and_stop(rank, "Bad argument ([version_A] or [version_B] expected)", MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    endtime = MPI_Wtime();

    MPI_Finalize();

    if(rank==0) {
        display_vector(0, v_before);
        display_vector(1, v_after);
        std::cout << "Runtime -> " << endtime-starttime << " seconds" << std::endl;
    }

    return 0;
}
