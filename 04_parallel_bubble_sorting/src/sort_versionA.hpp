#include "mpi.h"
#include <vector>

// equivalent phase 1 for even and phase 2 for odd
void phase_without_comparaison(int &local, int r)
{
    // envoie
    MPI_Send(&local, 1, MPI_INT, r+1, 0, MPI_COMM_WORLD);
    // récupere nouvelle valeur
    MPI_Recv(&local, 1, MPI_INT, r+1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}

// equivalent phase 2 for even and phase 1 for odd
void phase_with_comparaison(int &local, int &external, int r)
{
    if (r != 0) {
        MPI_Recv(&external, 1, MPI_INT, r-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        compare_values(local, external);
        MPI_Send(&external, 1, MPI_INT, r-1, 0, MPI_COMM_WORLD);
    }
}

/*  Cas où n=p, i.e. chaque processus a un élément du tableau à trier
    en mémoire après l’étape de distribution.   */
void tri_parallele_a(std::vector<int>& v, int rank, int nprocs)
{
    if(nprocs % 2 == 1) display_and_stop(rank, "Even number of process expected", MPI_COMM_WORLD);

    if(rank == 0)
        std::cout << "Compute -> a. Tri pair/impair d’un tableau de " << nprocs << " éléments sur " << nprocs <<" processus" << std::endl;

    // étape de distribution
    int local_rank_data;
    // if root process, send our data to everyone
    if(rank == 0) {
        // process root has the first value
        local_rank_data = v[0];
        // send one value of the vector to one process
        distribute_vector(nprocs, v);
    } else {
        // if receiver process, receive the data from the root
        MPI_Recv(&local_rank_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // tri de l’algorithme parallèle
    for(int k=0; k<=nprocs/2-1; k++)
    {
        int external_rank_data; // comprendre : valeur qui vient d'un autre que l'actuel (example: rank+1 ou rank-1)

        if(rank%2 == 0) // even
        {
            // PHASE 1
            phase_without_comparaison(local_rank_data, rank);
            // PHASE 2 : recois, attend message de process rank - 1, sauf si rank 0
            phase_with_comparaison(local_rank_data, external_rank_data, rank);
        }

        if(rank%2 == 1) // odd
        {
            // PHASE 1 : attend message de process rank - 1
            phase_with_comparaison(local_rank_data, external_rank_data, rank);
            // PHASE 2
            if(rank != nprocs-1)
                phase_without_comparaison(local_rank_data, rank);
        }
    }

    // retrieve and display results
    if(rank == 0){
        //std::vector<int> v2(nprocs);
        v[0] = local_rank_data;
        retrieve_vector(nprocs, v); // aggregate values into a vector
    } else {
        // send local result to root to accumulate all result!
        MPI_Send(&local_rank_data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

}
