#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../src/sort.hpp"
#include "../src/utils.hpp"

std::vector<int> tableauVide ={} ;
std::vector<int> tableauUnElement ={3} ;
std::vector<int> tableauBase = {3, 2, 1, 5, 4};
std::vector<int> tableauBaseDeux = {3, 2, 1, 5, 4, 12, 5};
std::vector<float> tableauFloat = {2.3, 4.5, 9.2, -1.0, 1.4};
std::vector<char> tableauChar = {'b', 'z', 'a', 'x'};

TEST_CASE("Test du tri a bulle")
{
    SECTION("Cas de base")
    {
        std::vector<int> tableauAttendu = {1, 2, 3, 4, 5};
        tableauBase = tri_a_bulle(tableauBase, tableauBase.size());
        REQUIRE(isEqual(tableauBase, tableauAttendu) == true);
    }

    SECTION("Cas de base 2")
    {
        std::vector<int> tableauAttendu = {1, 2, 3, 4, 5, 5, 12};
        tableauBaseDeux = tri_a_bulle(tableauBaseDeux, tableauBaseDeux.size());
        REQUIRE(isEqual(tableauBaseDeux, tableauAttendu) == true);
    }

    SECTION("Cas vide")
    {
        std::vector<int> tableauAttendu = {};
        tableauVide = tri_a_bulle(tableauVide, tableauVide.size());
        REQUIRE(isEqual(tableauVide, tableauAttendu) == true);
    }

    SECTION("Cas 1 element")
    {
        std::vector<int> tableauAttendu = {3};
        tableauUnElement = tri_a_bulle(tableauUnElement, tableauUnElement.size());
        REQUIRE(isEqual(tableauUnElement, tableauAttendu) == true);
    }

    SECTION("Cas type float")
    {
        std::vector<float> tableauAttendu = {-1.0, 1.4, 2.3, 4.5, 9.2};
        tableauFloat = tri_a_bulle(tableauFloat, tableauFloat.size());
        REQUIRE(isEqual(tableauFloat, tableauAttendu) == true);
    }

    SECTION("Cas type char")
    {
        std::vector<char> tableauAttendu = {'a', 'b', 'x', 'z'};
        tableauChar = tri_a_bulle(tableauChar, tableauChar.size());
        REQUIRE(isEqual(tableauChar, tableauAttendu) == true);
    }
}
