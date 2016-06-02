#ifndef PAWN_HH
#define PAWN_HH
#include "Board.hh"
#include <iostream>

struct Pawn{
  bool Damka=false;
  
  friend class Board;
  
  int Pawn::is_jump(int a,int b, int c,int d);
  int Pawn::Do_your_turn(int player, int a,int b, int c,int d);
  int Pawn::is_jump(int a,int b, int c,int d);
  int Pawn::is_empty(int c,int d);
  int Pawn::check_moves(int player,int a,int c);
};

#endif
