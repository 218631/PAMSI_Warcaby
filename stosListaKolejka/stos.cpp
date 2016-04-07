#include "stos.hh"
#include "lista.hh"


void Stos::push(int element)
{
  list.add(element,Size);
}
int Stos::pop()
{
  pomocnicza=list.get(Size);
  list.remove(Size);
  return pomocnicza;
}
int Stos::size()
{
  return list.size();
}
