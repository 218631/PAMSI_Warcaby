#include "warcaby.hh"
#include <iostream>
using namespace std;
int main()
{
  warcaby gra;
  int trudnosc;
  int kolej;
  kolej=1;
  cout<<"Witaj w grze warcaby!"<<"Prosze o wybranie poziomu trudnosci"<<endl;
  cout<<"1.Latwy(sredni czas trwania ruchu komputera - sekunda)"<<endl<<"2.Sredni(sredni czas trwania ruchu komputera - 2 sekundy)"<<endl<<"3.Trudny(sredni czas trwania ruchu komputera - 40 sekund"<<endl;
  cin>>trudnosc;
  switch(trudnosc)
    {
    case 1:
      cout<<"Wybrano poziom latwy!"<<endl<<endl;
      trudnosc=2;
      break;
    case 2:
      cout<<"Wybrano poziom sredni!"<<endl<<endl;
      trudnosc=5;
      break;
    case 3:
      cout<<"Wybrano poziom trudny!"<<endl<<endl;
      trudnosc=7;
      break;
    default:
      cout<<"Bledny wybor! Poziom trudnosci zostanie ustawiony na sredni"<<endl<<endl;
      break;
    }
  while(!gra.koniecGry(gra))
    {
      warcaby::ruch r;
      if(kolej==1)
	{
	  gra.wypiszPlansze();
	  r=gra.ruchGracza(gra);
	  gra=gra.wykonajRuch(gra,1,r.i,r.j,r.k,r.l);
	}
      if(kolej==-1)
	{
	  r=gra.ruchAI(gra,trudnosc);
	  gra=gra.wykonajRuch(gra,-1,r.i,r.j,r.k,r.l);
	}
      kolej=-kolej;
    }
}
