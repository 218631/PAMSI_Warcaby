#include "warcaby.hh"
#include <iostream>
#include <climits>
#include <string>
using namespace std;

warcaby::warcaby()
{
int stanStartowy[8][8]=
  {{0,-1,0,-1,0,-1,0,-1},
   {-1,0,-1,0,-1,0,-1,0},
   {0,-1,0,-1,0,-1,0,-1},
   {0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0},
   {1,0,1,0,1,0,1,0},
   {0,1,0,1,0,1,0,1},
   {1,0,1,0,1,0,1,0}};
 for(int i=0;i<8;i++)
   for(int j=0;j<8;j++)
     plansza[i][j]=stanStartowy[i][j];
}

void warcaby::wypiszPlansze()
{
  string default_console = "\033[0m";
  string colorB = "\033[1;36m";
  string colorW = "\033[1;97m";
  cout<<"   0   1   2   3   4   5   6   7 "<<endl<<" |--------------------------------|"<<endl;
  for(int i=0;i<8;i++)
    {
      cout<<i;
      for(int j=0;j<8;j++)
	{
	  cout<<"|";
	  switch(plansza[i][j])
	    {
	    case 0:
	      cout<<" . ";
	      break;
	    case -1:
	      cout << colorB <<" B ";
	      cout << default_console;
	      break;
	    case 1:
	      cout << colorW <<" W ";
	      cout << default_console;
	      break;
	    case -2:
	      cout << colorB <<" BK";
	      cout << default_console;
	      break;
	    case 2:
	      cout << colorW <<" WK";
	      cout << default_console;
	      break;

	      }
	}
      cout<<" |"<<i;
      cout<<endl;;
      cout<<" |--------------------------------|"<<endl;
    }
  cout<<"   0   1   2   3   4   5   6   7 "<<endl;
}
bool warcaby::sprawdzRuchy(warcaby p, int gracz, int x, int y, int k, int l)
{
    if(x>=0 && y>=0 && k>=0 && l>=0 && x<=7 && y<=7 && k<=7 && l<=7)
      {
	//dla damki gracza
        if(gracz==1 && p.plansza[y][x]==2)
        {
	  //ruch w lewo do tylu
            if(k>x && l<y)
            {
                if( (k==x+1 && l==y-1) || (k==x+2 && l==y-2) ||
                        (k==x+3 && l==y-3) || (k==x+4 && l==y-4) || (k==x+5 && l==y-5) ||
                        (k==x+6 && l==y-6) || (k==x+7 && l==y-7) )
                {
                    int temp=y-1;
                    for(int i=x+1; i<=k; i++)
                    {
                        if(p.plansza[temp][i]!=0)
                        {
                            if(p.plansza[temp][i]!=1 && p.plansza[temp][i]!=2)
                            {
                                if(temp!=0 || i!=7)
                                {
                                    if(p.plansza[temp-1][i+1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp--;
                    }
                    return true;
                }
                return false;
            }
	    //ruch w prawo do tylu
            if (k>x && l>y)
            {
                if( (k==x+1 && l==y+1) || (k==x+2 && l==y+2) ||
                        (k==x+3 && l==y+3) || (k==x+4 && l==y+4) || (k==x+5 && l==y+5) ||
                        (k==x+6 && l==y+6) || (k==x+7 && l==y+7) )
                {
                    int temp=y+1;
                    for(int i=x+1; i<=k; i++)
                    {
                        if(p.plansza[temp][i]!=0)
                        {
                            if(p.plansza[temp][i]!=1 && p.plansza[temp][i]!=2)
                            {
                                if(temp!=7 || i!=7)
                                {
                                    if(p.plansza[temp+1][i+1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp++;
                    }
                    return true;
                }
                return false;
            }
	    //ruch w lewo do przodu
            if(k<x && l<y)
            {
                if( (k==x-1 && l==y-1) || (k==x-2 && l==y-2) ||
                        (k==x-3 && l==y-3) || (k==x-4 && l==y-4) || (k==x-5 && l==y-5) ||
                        (k==x-6 && l==y-6) || (k==x-7 && l==y-7) )
                {
                    int temp=y-1;
                    for(int i=x-1; i>=k; i--)
                    {
                        if(p.plansza[temp][i]!=0)
                        {
                            if(p.plansza[temp][i]!=1 && p.plansza[temp][i]!=2)
                            {
                                if(temp!=0 || i!=0)
                                {
                                    if(p.plansza[temp-1][i-1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp--;
                    }
                    return true;
                }
                return false;
            }
	    //ruch w prawo do przodu
            if (k<x && l>y)
            {
                if( (k==x-1 && l==y+1) || (k==x-2 && l==y+2) ||
                        (k==x-3 && l==y+3) || (k==x-4 && l==y+4) || (k==x-5 && l==y+5) ||
                        (k==x-6 && l==y+6) || (k==x-7 && l==y+7) )
                {
                    int temp=y+1;
                    for(int i=x-1; i>=k; i--)
                    {
                        if(p.plansza[temp][i]!=0)
                        {
                            if(p.plansza[temp][i]!=1 && p.plansza[temp][i]!=2)
                            {
                                if(temp!=7 || i!=0)
                                {
                                    if(p.plansza[temp+1][i-1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp++;
                    }
                    return true;
                }
                return false;
            }        ;
        }
        //damka komputera
        if(gracz==-1 && p.plansza[y][x]==-2)
        {
	  //ruch do przodu w lewo
            if(k>x && l<y)
            {
                if( (k==x+1 && l==y-1) || (k==x+2 && l==y-2) ||
                        (k==x+3 && l==y-3) || (k==x+4 && l==y-4)
 || (k==x+5 && l==y-5) ||
                        (k==x+6 && l==y-6) || (k==x+7 && l==y-7) )
                {
                    int temp=y-1;
                    for(int i=x+1; i<=k; i++)
                    {
                        if(p.plansza[temp][i]!=0)
                        {
                            if(p.plansza[temp][i]!=-1 && p.plansza[temp][i]!=-2)
                            {
                                if(temp!=0 || i!=7)
                                {
                                    if(p.plansza[temp-1][i+1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp--;
                    }
                    return true;
                }
                return false;
            }
	    //ruch w prawo do przodu
            if (k>x && l>y)
            {
                if( (k==x+1 && l==y+1) || (k==x+2 && l==y+2) ||
                        (k==x+3 && l==y+3) || (k==x+4 && l==y+4) || (k==x+5 && l==y+5) ||
                        (k==x+6 && l==y+6) || (k==x+7 && l==y+7) )
                {
                    int temp=y+1;
                    for(int i=x+1; i<=k; i++)
                    {
                        if(p.plansza[temp][i]!=0)
                        {
                            if(p.plansza[temp][i]!=-1 && p.plansza[temp][i]!=-2)
                            {
                                if(temp!=7 || i!=7)
                                {
                                    if(p.plansza[temp+1][i+1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp++;
                    }
                    return true;
                }
                return false;
            }
	    //ruch w lewo do tylu
            if(k<x && l<y)
            {
                if( (k==x-1 && l==y-1) || (k==x-2 && l==y-2) ||
                        (k==x-3 && l==y-3) || (k==x-4 && l==y-4) || (k==x-5 && l==y-5) ||
                        (k==x-6 && l==y-6) || (k==x-7 && l==y-7) )
                {
                    int temp=y-1;
                    for(int i=x-1; i>=k; i--)
                    {
                        if(p.plansza[temp][i]!=0)
                        {
                            if(p.plansza[temp][i]!=-1 && p.plansza[temp][i]!=-2 )
                            {
                                if(temp!=0 || i!=0)
                                {
                                    if(p.plansza[temp-1][i-1]!=0)
                                    {
                                        return false;
                                    };
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp--;
                    }
                    return true;
                }
                return false;
            }
	    //ruch do tylu w prawo
            if (k<x && l>y)
            {
                if( (k==x-1 && l==y+1) || (k==x-2 && l==y+2) ||
                        (k==x-3 && l==y+3) || (k==x-4 && l==y+4) || (k==x-5 && l==y+5) ||
                        (k==x-6 && l==y+6) || (k==x-7 && l==y+7) )
                {
                    int temp=y+1;
                    for(int i=x-1; i>=k; i--)
                    {
                        if(p.plansza[temp][i]!=0)
                        {
                            if(p.plansza[temp][i]!=-1 && p.plansza[temp][i]!=-2)
                            {
                                if(temp!=7 || i!=0)
                                {
                                    if(p.plansza[temp+1][i-1]!=0)
                                    {
                                        return false;
                                    }
                                }
                                else
                                {
                                    return false;
                                }
                            }
                            else
                            {
                                return false;
                            }
                        }
                        temp++;
                    }
                    return true;
                }
                return false;
            }
        }
	//ruch komputera
        if(gracz==-1)
        {
	  //zwykly pionek komputera
            if(p.plansza[y][x]==-1)
            {
	      //jezeli pole jest wolne
                if(p.plansza[l][k]==0)
                {
		  //ruch w przod
                    if(l==y+1)
                    {
		      //lewo lub prawo
                        if(k==x+1||k==x-1)
                        {
                            return true;
                        }
                    }
                }
		//ruch z biciem
                if(l==y+2)
                {
		  //bicie w prawo
                    if(k==x+2)
                    {
		      //miejsce za pionkiem wolne
                        if(p.plansza[l][k]==0)
                        {
			  //bity pionek jest gracza
                            if(p.plansza[y+1][x+1]>0)
                            {
                                return true;
                            }
                        }
                    }
		    //bicie w lewo
                    if(k==x-2)
                    {
		      //miejsce za bitym pionkiem wolne
                        if(p.plansza[l][k]==0)
                        {
			  //bity jest pionek gracza
                            if(p.plansza[y+1][x-1]>0)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
	//analogicznie jak wyzej, tylko z perspektywy dolu planszy
        else if(gracz==1)
        {
            if(p.plansza[y][x]==1)
            {
                if(p.plansza[l][k]==0)
                {
                    if(l==y-1)
                    {
                        if(k==x+1||k==x-1)
                        {
                            return true;
                        }
                    }
                    if(l==y-2)
                    {
                        if(k==x+2)
                        {
                            if(p.plansza[y-1][x+1]<0)
                            {
                                return true;
                            }
                        }
                        if(k==x-2)
                        {
                            if(p.plansza[y-1][x-1]<0)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool warcaby::koniecGry(warcaby p)
{
    int r=0;
    int b=0;
    for(int x=0; x<8; x++)
    {
        for(int y=0; y<8; y++)
        {
            if(p.plansza[y][x]>0)
                r++;
            if(p.plansza[y][x]<0)
                b++;
        }
    }
    if(!(r*b))
        return true;
    else
        return false;
}

warcaby warcaby::wykonajRuch(const warcaby p, int gracz, int x, int y, int k, int l)
{

    warcaby wynik;
    wynik=p;

    if(wynik.plansza[y][x]==2 || wynik.plansza[y][x]==-2)
    {
        if(gracz==1)
	  {
            if(k>x && l<y)
            {
                int temp=y-1;
                for(int i=x+1; i<=k; i++)
                {
                    if(p.plansza[temp][i]!=0)
                    {
                        wynik.plansza[temp][i]=0;
                    }
                    temp--;
                }
                wynik.plansza[l][k]=2;
                wynik.plansza[y][x]=0;
            }
	    ////////
            if(k>x && l>y)
            {
                int temp=y+1;
                for(int i=x+1; i<=k; i++)
                {
                    if(p.plansza[temp][i]!=0)
                    {
                        wynik.plansza[temp][i]=0;
                    }
                    temp++;
                }
                wynik.plansza[l][k]=2;
                wynik.plansza[y][x]=0;
            }
	    /////////////
            if(k<x && l<y)
            {
                int temp=y-1;
                for(int i=x-1; i>=k; i--)
                {
                    if(p.plansza[temp][i]!=0)
                    {
                        wynik.plansza[temp][i]=0;
                    }
                    temp--;
                }
                wynik.plansza[l][k]=2;
                wynik.plansza[y][x]=0;
            }
            if(k<x && l>y)
            {
                int temp=y+1;
                for(int i=x-1; i>=k; i--)
                {
                    if(p.plansza[temp][i]!=0)
                    {
                        wynik.plansza[temp][i]=0;
                    }
                    temp++;
                }
                wynik.plansza[l][k]=2;
                wynik.plansza[y][x]=0;
            }
        }




        if(gracz==-1)
        {
            if(k>x && l<y)
            {
                int temp=y-1;
                for(int i=x+1; i<=k; i++)
                {
                    if(p.plansza[temp][i]!=0)
                    {
                        wynik.plansza[temp][i]=0;
                    }
                    temp--;
                }
                wynik.plansza[l][k]=-2;
                wynik.plansza[y][x]=0;
            }
            if(k>x && l>y)
            {
                int temp=y+1;
                for(int i=x+1; i<=k; i++)
                {
                    if(p.plansza[temp][i]!=0)
		      wynik.plansza[temp][i]=0;
                    temp++;
                }
                wynik.plansza[l][k]=-2;
                wynik.plansza[y][x]=0;
            }
            if(k<x && l<y)
            {
                int temp=y-1;
                for(int i=x-1; i>=k; i--)
                {
                    if(p.plansza[temp][i]!=0)
		      wynik.plansza[temp][i]=0;
                    temp--;
                }
                wynik.plansza[l][k]=-2;
                wynik.plansza[y][x]=0;
            }
            if(k<x && l>y)
            {
                int temp=y+1;
                for(int i=x-1; i>=k; i--)
                {
                    if(p.plansza[temp][i]!=0)
		      wynik.plansza[temp][i]=0;
                    temp++;
                }
                wynik.plansza[l][k]=-2;
                wynik.plansza[y][x]=0;
            }
        }
    }
    if(gracz==1 &&( (l==0) || (l==2) || (l==4) || (l==6)))
      wynik.plansza[l][k]=2;
    if(gracz==-1)
    {
        if(p.plansza[y][x]==-1)
	  {
            if(l==y+1)
            {
                if(k==x+1||k==x-1)
                {
                    wynik.plansza[l][k]=wynik.plansza[y][x];
                    wynik.plansza[y][x]=0;
                }
            }
            if(l==y+2)
            {
                if(k==x+2)
                {
                    if(wynik.plansza[y+1][x+1]>0)
                    {
                        wynik.plansza[y+1][x+1]=0;
                        wynik.plansza[l][k]=wynik.plansza[y][x];
                        wynik.plansza[y][x]=0;
                    }
                }
                if(k==x-2)
                {
                    if(p.plansza[y+1][x-1]>0)
                    {
                        wynik.plansza[y+1][x-1]=0;
                        wynik.plansza[l][k]=wynik.plansza[y][x];
                        wynik.plansza[y][x]=0;
                    }
                }
            }
        }
    }
    else if(gracz==1)
    {
        if(p.plansza[y][x]==1)
        {
            if(l==y-1)
            {
                if(k==x+1||k==x-1)
                {
                    wynik.plansza[l][k]=wynik.plansza[y][x];
                    wynik.plansza[y][x]=0;
                }
            }
            if(l==y-2)
            {
                if(k==x+2)
                {
                    if(p.plansza[y-1][x+1]<0)
                    {
                        wynik.plansza[y-1][x+1]=0;
                        wynik.plansza[l][k]=p.plansza[y][x];
                        wynik.plansza[y][x]=0;
                    }
                }
                if(k==x-2)
                {
                    if(p.plansza[y-1][x-1]<0)
                    {
                        wynik.plansza[y-1][x-1]=0;
                        wynik.plansza[l][k]=wynik.plansza[y][x];
                        wynik.plansza[y][x]=0;
                    }
                }
            }
        }
    }
    if((l==0 || l==7))
    {
        if (gracz ==1)
        {
            wynik.plansza[l][k]=2;
        }
        else
        {
            wynik.plansza[l][k]=-2;
        }
    }
    return wynik;
}

int warcaby::ocenaSytuacji(warcaby p)
{
  int AI=0,G=0,x=0;
    for(int i=0;i<8;i++)
      {
	switch(p.plansza[i][x])
	  {
	  case 0:
	    break;
	  case 1:
	    G+=4;
	    break;
	  case 2:
	    G+=15;
	    break;
	  case -1:
	    AI+=4;
	    break;
	  case -2:
	    AI+=15;
	    break;
	  }
	if(i==7 && x==0)
	  {
	    i=0;
	    x=7;
	  }
      }

    for(int i=1;i<7;i++)
      {
	switch(p.plansza[x][i])
	  {
	  case 0:
	    break;
	  case 1:
	    G+=4;
	    break;
	  case 2:
	    G+=15;
	    break;
	  case -1:
	    AI+=4;
	    break;
	  case -2:
	    AI+=15;
	    break;
	  }
	if(i==6 && x==0)
	  {
	    i=0;
	    x=1;
	  }
      }
    for(int i=1;i<7;i++)
      {
      for(int j=1;j<7;j++)
	{
	 switch(p.plansza[j][i])
	   {
	   case 0:
	     break;
 	   case 1:
 	     G+=2;
	     break;
	   case 2:
	     G+=7;
	     break;
	   case -1:
	     AI+=2;
	     break;
	   case -2:
	     AI+=7;
	     break;
	   }
	}
      }
	AI=AI-G;
	return AI;
}

int warcaby::minimax(warcaby w, int gracz, int glebokosc, ruch &wybor)
{
    if (glebokosc == 0)
        return ocenaSytuacji(w);

    int najlepszy;

    if (gracz == -1) najlepszy = INT_MIN;
    else najlepszy = INT_MAX;

    ruch zestaw;

    for (int a = 0; a < 8; a++)
        for (int b = 0; b < 8; b++)
            for (int c = 0; c < 8; c++)
                for (int d = 0; d < 8; d++)
                {
                    if (sprawdzRuchy(w, gracz, a, b, c, d))
                    {
                        warcaby temp;
                        temp=wykonajRuch(w, gracz, a,b,c,d);
                        int ocena = minimax(temp, -gracz, glebokosc-1, wybor);
                        if (gracz == -1)
                        {
                            if (ocena > najlepszy)
                            {
                                najlepszy = ocena;
                                zestaw.i=a;
                                zestaw.j=b;
                                zestaw.k=c;
                                zestaw.l=d;
                            }
                        }
                        else
                        {
                            if (ocena < najlepszy)
                            {
                                najlepszy = ocena;
                                zestaw.i=a;
                                zestaw.j=b;
                                zestaw.k=c;
                                zestaw.l=d;
                            }
                        }
                    }
                }
    wybor=zestaw;
    return najlepszy;
}

warcaby::ruch warcaby::ruchAI(warcaby w, int trudnosc)
{
    ruch x;
    minimax(w, -1, trudnosc, x);
    return x;
}
warcaby::ruch warcaby::ruchGracza(warcaby w)
{
  ruch r;
  cout<<"Twoj ruch ! "<<endl;
  int a,b,c,d;
  a=b=c=d=0;
  while(!sprawdzRuchy(w,1,a,b,c,d))
    {
      cout<<"Podaj swoj ruch(kolumna wiersz kolumna wiersz)"<<endl;
      cin>>a;
      cin>>b;
      cin>>c;
      cin>>d;
      if(a>=0 && a<=7)
	if(b>=0 && b<=7)
	  if(c>=0 && c<=7)
	    if(d>=0 && d<=7)
	      if(sprawdzRuchy(w,1,a,b,c,d))
		{
		  r.i=a;r.j=b;r.k=c;r.l=d;
		}else
		{
		cout<<"Ten ruch jest niedozwolony, sprobuj ponownie"<<endl;
		continue;
		}
    }
  return r;
}
