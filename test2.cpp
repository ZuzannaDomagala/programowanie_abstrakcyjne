#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "polka.h"
using namespace::std;

int main(){

    Ksiazka *l = new Literatura("Wladca Pierscieni", "J.R.R. Tolkien", "fantasy");
    Ksiazka *s = new Slownik("polski", "angielski", "Grzegorz", "Slownik angielski");
    Ksiazka *p = new Podrecznik("historia", "Jan Kazimierz", "Sladami przeszlosci");
    Ksiazka *al = new Literatura("Alicja w Krainie czarow", "Lewis Carroll", "fantasy");
    
    Polka<Ksiazka> polka("Książki", "A1");
    

    polka.dodajObiekt(l);
    polka.dodajObiekt(p);
    polka.dodajObiekt(s);
    polka.dodajObiekt(al);

    polka.wyswietlStatystyki();
    polka.pokazPrzedmioty();
    polka.sortuj();

    polka.pokazPrzedmioty();
    polka.wypozyczObiekt("Wladca Pierscieni");
    polka.pokazPrzedmioty();
    

    return 0;   

}
//co już jest:
//dziedziczenie: rodzaje książek
//szablony: klasa szablonowa pólka, funkcje szablonowe  w półce
//pojemniki: vector
//stl przeglądanie obiektów: iterator vectora, find_if, sort
//metaprogramowanie



