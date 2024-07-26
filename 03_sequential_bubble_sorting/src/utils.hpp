#include <vector>

/**
 * Entrée:
 *   first : vector numéro 1
 *   second : vector numéro 2
 * Sortie :
 *   bool : résultat du test
*/
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
