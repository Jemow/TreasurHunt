#ifndef Map_h
#define Map_h
#include <array>
#include <iostream>

const int ROW = 5;
const int COL = 5;
const int MAXIMUM_TRY = 10;

// Status of each case
enum class Case
{
  Dug,
  Treasure,
  HideTreasure,
  Nothing
};

/**
 * @brief This is where the player put his [row/column] choices
 * 
 * @param x It will represent an x row
 * @param y It will represent a y column
 */
void MakeChoice(int& x, int& y)
{
  do
  {
    std::cout << "Put the line : ";
    std::cin >> x;
    std::cout << "Put the column : ";
    std::cin >> y;
    std::cout << '\n';

    // Check if there is failure with the inputs
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
    }
  }
  // The numbers mustn't be lower than 0 and [greater/equal] [than/to] ROW or COL
  while (x < 0 || x >= ROW
      || y < 0 || y >= COL);
}

/**
 * @brief This function create the map and put each case at the initial one (Case::Nothing)
 * 
 * @param map The reference of the map
 */
void MakeMap(std::array<std::array<Case, COL>, ROW>& map)
{
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      map[i][j] = Case::Nothing;
    }
  }
}

/**
 * @brief Display each case of the map in the console
 * 
 * @param map The map to display
 *
 * Nothing - o : There is nothing in this case, if the player dig it, it becomes a Dug case
 * HideTreasure - o : There is a treasure in this case, if the player dig it, it becomes a Treasure case
 * Dug - x : It means that the player already dug here
 * Treasure - + : This is the treasure, showed when the player dig a HideTreasure
 */
void ShowMap(std::array<std::array<Case, COL>, ROW> map)
{
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      switch (map[i][j])
      {
        case Case::Dug: std::cout << 'x'; break;
        case Case::HideTreasure: std::cout << 'o'; break;
        case Case::Treasure: std::cout << '+'; break;
        case Case::Nothing: std::cout << 'o'; break;
      }
      std::cout << ' ';
    }
    std::cout << '\n';
  }
}

/**
 * @brief Allows to generate a treasure with a random position in the map, so this
 *        will take a random case in the map and transform it into a HideTreasure
 * 
 * @param map 
 */
void GenerateTreasure(std::array<std::array<Case, COL>, ROW>& map)
{
  // Generate random x and y positions
  int positionX = rand() % COL;
  int positionY = rand() % ROW;

  map[positionX][positionY] = Case::HideTreasure;
}

/**
 * @brief Allows the player to dig somewhere in the map. If it's a HideTreasure, it will transform it
 *        into a Treasure. But it is not, it will transform the case into a Dug.
 *      
 * 
 * @param map The map where to dig
 * @param x The row where to dig
 * @param y The column where to dig
 * @return True if the player dug the HideTreasure otherwise false
 */
bool Dig(std::array<std::array<Case, COL>, ROW>& map ,int x, int y)
{
  if(map[x][y] == Case::HideTreasure)
  {
    map[x][y] = Case::Treasure;
    return true;
  }
  map[x][y] = Case::Dug;
  std::cout << "Nothing there...\n";
  return false;
}

#endif

