#include <array>
#include <iostream>
#include <map>

#include "Map.h"

/**
 * @jemoelablay
 *
 * TreasurHunt.cc
 *
 * 18.09.2024
 *
 * Description :
 */

int main()
{
    // Generate the random seed by time
    srand(time(NULL));

    // Initialize the matrice
    std::array<std::array<Case, COL>, ROW> matrice;
    
    MakeMap(matrice);
    GenerateTreasure(matrice);

    while (true)
    {
        ShowMap(matrice);
        int choiceX;
        int choiceY;

        MakeChoice(choiceX, choiceY);
        Dig(matrice, choiceX, choiceY);
    }

}
