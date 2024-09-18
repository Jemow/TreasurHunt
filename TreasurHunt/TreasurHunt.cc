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
    bool hasWin = false;

    // Creating the matrice
    MakeMap(matrice);

    // Put a treasure in the map
    GenerateTreasure(matrice);

    for(int i = 0; i < MAXIMUM_TRY; i++)
    {
        // Displaye the map
        ShowMap(matrice);

        // Player choices
        int choiceX;
        int choiceY;

        // Save the player choice in choiceX and choiceY
        MakeChoice(choiceX, choiceY);

        // Dig where the specific case and update the map
        hasWin = Dig(matrice, choiceX, choiceY);
    }
}
