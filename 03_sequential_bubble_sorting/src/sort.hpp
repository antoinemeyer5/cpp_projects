#include <vector>

/**
 * Entrée:
 *   vec : tableau à afficher
 * Sortie :
 *   std::cout : affichage du vecteur dans le terminal
*/
template <typename T>
void affiche_vector(const std::vector<T> &vec) {
    std::cout << "{ ";
    for (auto &i : vec) {
        std::cout << i << "; ";
    }
    std::cout << "}" << std::endl;
}

/**
 * Entrées:
 *   tab : tableau de n éléments non trié
 *   n : taille du tableau
 * Sortie :
 *   tab : tableau de n éléments trié
*/
template <typename T>
std::vector<T> tri_a_bulle(std::vector<T> &tab, int const n)
{
    if (n != 0)
    {
        for(size_t i=0; i<n-1; ++i)
        {
            for (size_t j=0; j<n-i-1; ++j)
            {
                if (tab.at(j) > tab.at(j + 1))
                {
                    std::swap(tab.at(j), tab.at(j + 1));
                }
            }
        }
    }
    return tab;
}
