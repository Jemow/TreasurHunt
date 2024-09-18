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
    int numberTry = 0;

    // Creating the matrice
    MakeMap(matrice);

    // Put a treasure in the map
    GenerateTreasure2(matrice);

    // -- Game --

    std::cout << "You are a treasure hunter, your goal is to find the treasure"
                 " to become rich. But your time is limited you will have " << numberTry
              << " tries to find it. The map size is [" << ROW << "/" << COL << "]\n";

    for(int i = 0; i < MAXIMUM_TRY; i++)
    {
        numberTry++;
        
        // Displaye the map
        ShowMap(matrice);
        if(hasWin) break;

        // Player choices
        int choiceX;
        int choiceY;

        // Save the player choice in choiceX and choiceY
        std::cout << "Where do you want to dig ?\n";
        MakeChoice(choiceX, choiceY);

        // Dig where the specific case and update the map
        hasWin = Dig(matrice, choiceX, choiceY);
    }
    std::cout << '\n';
    
    // Display if the player won
    if(hasWin) std::cout << "You won with " << numberTry << " tries" << '\n';
    else std::cout << "You lost bro!\n";
}
