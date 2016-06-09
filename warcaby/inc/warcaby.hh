#ifndef WARCABY_HH
#define WARCABY_HH


class warcaby
{
  //plansza gry
  int plansza[8][8];
public:
  //struktura ruchu ulatwiajaca jego przenoszenie miedzy metodami
struct ruch
{
//i,j-pozycja przemieszczanego pionka
//k,l-pozycja docelowa
  int i,j,k,l;
};
  // 
  warcaby();
  // sprawdzanie czy podany ruch jest legalny(i,j-pozycja pionka, k,l-pozycja docelowa)
  bool sprawdzRuchy(warcaby w,int kolej,int i,int j,int k,int l);
  //rysowanie aktualnego stanu planszy
  void wypiszPlansze();
  //funkcja oceny stanu planszy potrzebna do algorytmu minimax, w tym przypadku funkcja krawedziowa
  int ocenaSytuacji(warcaby);
  //funkcja wyboru najlepszego ruchu
  int minimax(warcaby,int gracz,int glebokosc,ruch&);
  //sprawdzanie czy gra sie skonczyla
  bool koniecGry(warcaby);
  //funkcja zwracajaca najlepszy ruch wybrany przez algorytm minimax
  ruch ruchAI(warcaby,int);
  //funkcja pobierajaca i zwracajaca ruch gracza, ponadto sprawdza czy ruch jest legalny
  ruch ruchGracza(warcaby);
  //funkcja wykonujaca ruch i gdy trzeba tworzaca damke
  warcaby wykonajRuch(warcaby,int, int i,int j,int k,int l);


};

#endif
