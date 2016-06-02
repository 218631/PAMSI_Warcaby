#include "Board.hh"

void Board::printBoard()
{
  int row, column;
    
  cout << "  +---+---+---+---+---+---+---+---+" << endl;
  
  for (rows=0; rows<ROWS; ++rows)
    {
      cout << "|" << rows+1;
      for (column=0; column<COLS; ++column)
        {
	  cout << "|" <<  value2symbol(board[rows][column]);
        }
      cout << endl;
      cout  <<"  +---+---+---+---+---+---+---+---+" << endl;
    }
  
  cout << "    a   b   c   d   e   f   g   h" << endl;
}

char Board::value2symbol(int i) 
{
  switch(i)
    {
    case 0:
      return ' ';
    case 1:
      return 'E';  
    case 2:
      return 'W';
    case 3:
      return 'B';     
    }
  return ('?');
}

void Board::swap(int board[ROWS][COLS], int a, int b, int c, int d)
{
  int temp;
  
  cout << "SWAP:" << a << "," << b << " to " << c << "," << d << endl;
  
  temp = board[a][b];
  board[a][b] = board[c][d];
  board[c][d] = temp;
    
}
