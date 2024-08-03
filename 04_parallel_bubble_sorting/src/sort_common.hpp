#include "mpi.h"
#include <algorithm>

// send one vector value to one process
void distribute_vector(int n, std::vector<int> v)
{
    for (int i=1; i<n; i++) {
        MPI_Send(&v[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
    }
}

void retrieve_vector(int n, std::vector<int> &v)
{
    for (int i=1; i<n; i++) {
        MPI_Recv(&v[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
}

void tri_fusion_des_sous_listes(std::vector<int> &local, std::vector<int> &external)
{
    std::vector<int> localPLUSexternal = local;
    localPLUSexternal.insert(localPLUSexternal.end(), external.begin(), external.end());

    std::sort(localPLUSexternal.begin(), localPLUSexternal.end());

    // fill local and external with new datas
    for(int i=0; i<local.size(); i++) {
        external[i] = localPLUSexternal[i];
        local[i] = localPLUSexternal[i+local.size()];
    }
}
