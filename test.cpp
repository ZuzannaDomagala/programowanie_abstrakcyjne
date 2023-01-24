#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "polka.h"
using namespace::std;

int main(){

    Polka<Gra> polkaNaGry("Gry", "A2");
    Gra *g = new Gra("Minecraft", "Mohjang");
    Gra *g2 = new Gra("Sims 3", "EA");
    Gra *g3 = new Gra("Sims 4", "EA");

    polkaNaGry.dodajObiekt(g2);
    polkaNaGry.dodajObiekt(g3);
    polkaNaGry.dodajObiekt(g);
    polkaNaGry.pokazPrzedmioty();
    polkaNaGry.wypozyczObiekt("Minecraft");
    polkaNaGry.pokazPrzedmioty();
    polkaNaGry.wyswietlStatystyki();
    polkaNaGry.sortuj();
    polkaNaGry.pokazPrzedmioty();

    return 0;   

}
//co już jest:
//dziedziczenie: rodzaje książek
//szablony: klasa szablonowa pólka, funkcje szablonowe  w półce
//pojemniki: vector
//stl przeglądanie obiektów: iterator vectora, find_if, sort
//metaprogramowanie



