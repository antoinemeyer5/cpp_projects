#include "mpi.h"

void phase_without_comparaison_2(std::vector<int> &local, int r)
{
    // envoie vector
    MPI_Send(&local[0], local.size(), MPI_INT, r+1, 0, MPI_COMM_WORLD);
    // recupere nouveau vector
    MPI_Recv(&local[0], local.size(), MPI_INT, r+1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}

void phase_with_comparaison_2(std::vector<int> &local, std::vector<int> &external, int r)
{
    if (r != 0) {
        MPI_Recv(&external[0], local.size(), MPI_INT, r-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        tri_fusion_des_sous_listes(local, external);
        MPI_Send(&external[0], local.size(), MPI_INT, r-1, 0, MPI_COMM_WORLD);
    }
}

void tri_parallele_b(std::vector<int>& v, int rank, int nprocs, int nelems)
{
    if(nprocs % 2 == 1) display_and_stop(rank, "Even number of process expected", MPI_COMM_WORLD);
    if((nelems % nprocs) != 0) display_and_stop(rank, "Cannot divide elements into processes", MPI_COMM_WORLD);

    int nelems_per_proc = nelems / nprocs;
    if(rank == 0)
        std::cout << "Compute -> b. Tri pair/impair d’un tableau de " << nelems_per_proc << " éléments " << nprocs << " processus, avec " << nelems << "=" << nelems_per_proc << "*" << nprocs << std::endl;

    // étape de distribution
    std::vector<int> local_rank_data(nelems_per_proc);

    // distribute for others ranks
    MPI_Scatter(v.data(),               nelems_per_proc, MPI_INT,
                local_rank_data.data(), nelems_per_proc, MPI_INT,
                0,  MPI_COMM_WORLD);

    // tri de l’algorithme parallèle
    for(int k=0; k<=nprocs/2-1; k++)
    {
        // comprendre : valeurs qui vient d'un autre que l'actuel (example: rank+1 ou rank-1)
        std::vector<int> external_rank_data(nelems_per_proc);

        if(rank%2 == 0) // even
        {
            // PHASE 1 WITHOUT COMPA (see above)
            phase_without_comparaison_2(local_rank_data, rank);
            // PHASE 2 WITH COMPA
            phase_with_comparaison_2(local_rank_data, external_rank_data, rank);
        }

        if(rank%2 == 1) // odd
        {
            // PHASE 1 WITH COMPA
            phase_with_comparaison_2(local_rank_data, external_rank_data, rank);
            // PHASE 2 WITHOUT COMPA
            if(rank != nprocs-1)
                phase_without_comparaison_2(local_rank_data, rank);
        }
    }

    // retrieve and display results
    MPI_Gather( local_rank_data.data(), nelems_per_proc, MPI_INT,
                v.data(),               nelems_per_proc, MPI_INT,
                0,  MPI_COMM_WORLD);
}
