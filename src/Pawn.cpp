#include "Pawn.hh"


//sprawdzamy czy mieści polecenie mieści się na planszy
int Pawn::Keep_in_bounds(int a,int b,int c,int d){
  //a
  if(i < 0 && ROWS <= a){
    cout << "Row is out of bounds" << endl;
    return -1;
  }
  else
    return 0;
  
  //b
  if(j < 0 && COLS <= b){
    cout << "Column is out of bound" << endl;
    return -1;
  }
  else
    return 0;
  
  //c
  if(k < 0 && ROWS <= k){
    cout << "Row is out of bounds" << endl;
    return -1;
  }
  else
    return 0;
  
  //d
  if(l < 0 && COLS<= l){
    cout << "Column is out of bounds" << endl;
    return -1;
  }
  else
   return 0;
}

//pilnowanie, by gracz kożystał ze swojego pionka
int Pawn::is_it_your_pawn(int player){
  if(player == WHITE){
    if(d[a][b] != WHITE){
      cout << "move your own pawn!" << endl;
      return -1;
    }
    else
      return 0;
  }
  else {
    if(d[a][b] != BLACK){
      cout << "move your own pawn!" << endl;
      return -1;
    }
    else
      return 0;
  }
}

//czy, gracz przesuwa pionek na puste pole
int Pawn::is_empty(int c,int d){
  if(board[c][d] != EMPTY){
    printf("You must move to a empty location");
    return -1;
  }
  else
    return 0;
}

int Pawn::check_moves(int player,int a,int c){
  if(damka==false){
  if(player == WHITE){
    //make sure he moves down
    if(a >= c){
      printf("WHITE player must move down\n");
      return -1;
      else
	return 0;
    }
  }
  else { //BLACK
    // make sure player moves up
    if(a <= c){
      printf("BLACK player must move up\n");   
      return -1;
    }
    else
      return 0;
  }
  }
  else
    return 0;
}

int Pawn::is_jump(int a,int b, int c,int d){
  int jump1,jump2;
    if(a - c == -2 || a - c == 2){
        if(b - d == -2 || c - d == 2){
            //sprawdzamy, czy wybrana pozycja to przeciwnik
            if(i < k){ // move down
                jump1 = a + 1;
            } else { // do góry
                jump1 = a - 1;
            }
            if(j < l){ // do dołu
                jump2 = b + 1;
            } else { // do góry
                jump2 = b - 1;
            }
            
            if(player==WHITE && d[jump1][jump2]!=BLACK)
            {
	      cout << "there is no enemy at:" <<jump1 <<","<< jump2 << endl;
                return -1;
            }
            if(player==BLACK && d[jump1][jump2] != WHITE){
	      cout << "you can only jump over an enemy player" << endl;
                return -1;
            }
            
            // we are sure the move is valid:
            board[jump1][jump2] = 1;
            swap(a,b,c,d);
            return 0;
        }
    }
    cout << "You can only move diagnally" << endl;
    return -1;
}

int Pawn::Do_your_turn(int player, int a,int b, int c,int d){
  if(player == WHITE)
    {
      cout << "WHITE move from: " << a << "," << b << " to " << c << "," << d << endl;
    }
  else
    {
      cout <<"BLACK move from: "  << a << "," << b << " to " << c << "," << d << endl;
    }
  if(Keep_in_bounds(a,b,c,d)==0)
    {
      if(is_it_your_pawn(player)==0)
	{
	  if(is_empty(player,a,c)==0)
	    return is_jump(a,b,c,d);
	  else
	    return -1;
	}
      else
	return -1;
    }
  else
    return -1;
}
