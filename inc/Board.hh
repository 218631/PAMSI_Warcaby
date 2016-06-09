#ifndef Board_HH
#define Board_HH

#include <iostream>
#include "Pawn.hh"
#include "Interface.hh"

using namespace std;

class Board{
  int board[ROWS][COLS]={
    {0,2,0,2,0,2,0,2},
    {2,0,2,0,2,0,2,0}, 
    {0,2,0,2,0,2,0,2}, 
    {1,0,1,0,1,0,1,0}, 
    {0,1,0,1,0,1,0,1}, 
    {3,0,3,0,3,0,3,0},
    {0,3,0,3,0,3,0,3},
    {3,0,3,0,3,0,3,0}};
public:
  friend struct Pawn;
  void printBoard();
  char value_symbol(int i);
  void swap(int a, int b, int c, int d);
};

#endif
