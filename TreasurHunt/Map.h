#ifndef Map_h
#define Map_h
#include <array>
#include <iostream>

const int ROW = 3;
const int COL = 3;
const int MAXIMUM_TRY = 10;

enum class Case
{
  Digged,
  Treasure,
  HideTreasure,
  Nothing
};

void MakeChoice(int& x, int& y)
{
  do
  {
    std::cout << "Put the line : ";
    std::cin >> x;
    std::cout << "Put the column : ";
    std::cin >> y;
    std::cout << '\n';
    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore();
    }
  } while ((x < 0 || x >= ROW)
      && (y < 0 || y >= COL));
}

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

void ShowMap(std::array<std::array<Case, COL>, ROW> map)
{
  for (int i = 0; i < ROW; i++)
  {
    for (int j = 0; j < COL; j++)
    {
      switch (map[i][j])
      {
        case Case::Digged: std::cout << 'x'; break;
        case Case::HideTreasure: std::cout << 'o'; break;
        case Case::Treasure: std::cout << '+'; break;
        case Case::Nothing: std::cout << 'o'; break;
      }
      std::cout << ' ';
    }
    std::cout << '\n';
  }
}

void GenerateTreasure2(std::array<std::array<Case, COL>, ROW>& map)
{
  int positionX = rand() % COL;
  int positionY = rand() % ROW;

  map[positionX][positionY] = Case::HideTreasure;
}

bool Dig(std::array<std::array<Case, COL>, ROW>& map ,int x, int y)
{
  if(map[x][y] == Case::HideTreasure)
  {
    map[x][y] = Case::Treasure;
    return true;
  }
  map[x][y] = Case::Digged;
  return false;
}

#endif

