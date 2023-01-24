#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "polka.h"
using namespace::std;

bool IdentyfikatorZajety(vector<Polka<Ksiazka>> polkiNaKsiazki, vector<Polka<Gra>> polkiNaGry, string id){
    for(int i = 0; i < polkiNaKsiazki.size(); i++){
        if(polkiNaKsiazki[i].identyfikator() == id) return true;
    }
    for(int i = 0; i < polkiNaGry.size(); i++){
        if(polkiNaGry[i].identyfikator() == id) return true;
    }
    return false;
}


int main(){
    string polecenie = "";
    vector<Polka<Ksiazka>> polkiNaKsiazki;
    vector<Polka<Gra>> polkiNaGry;
    while(polecenie != "S"){
        cout << "wpisz polecenie:" << endl;
        cout << "DPK - dodaj półkę z książkami" << endl;
        cout << "DPG - dodaj półkę z grami" << endl;
        cout << "WSP - wyswietl wszystkie półki" << endl;
        cout << "DK - utwórz książkę i dodaj ją na półkę" << endl;
        cout << "DG - utwórz grę i dodaj ją na półkę" << endl;
        cout << "W - wypożycz książkę lub grę" << endl;
        cout << "Z - zwróć książkę lub grę" << endl;
        cout << "SP - posortuj obiekty na półce" << endl;
        cout << "WS - wyswietl statystyki półki" << endl;
        cout << "PP - pokaż przedmioty na półce" << endl; 
        cout << "S - stop " << endl;
        cin >> polecenie;

        if(polecenie == "DPK"){
            string identyfikator = "";
            cout << "Podaj identyfikator dla półki:" << endl;
            cin >> identyfikator;
            while(IdentyfikatorZajety(polkiNaKsiazki, polkiNaGry, identyfikator)){
                cout << "Identyfikator jest zajęty, wybierz inny:" << endl;
                cin >> identyfikator;
            }

            Polka<Ksiazka> polka("Ksiażki", identyfikator);
            polkiNaKsiazki.push_back(polka);
            cout << "Dodano półkę z książkami" << endl;
        }

        else if(polecenie == "DPG"){
            string identyfikator = "";
            cout << "Podaj identyfikator dla półki:" << endl;
            cin >> identyfikator;
            while(IdentyfikatorZajety(polkiNaKsiazki, polkiNaGry, identyfikator)){
                cout << "Identyfikator jest zajęty, wybierz inny:" << endl;
                cin >> identyfikator;
            }

            Polka<Gra> polka("Gry", identyfikator);
            polkiNaGry.push_back(polka);
            cout << "Dodano półkę z grami" << endl;
        }

        else if(polecenie == "WSP"){
            for(int i = 0; i < polkiNaGry.size(); i++){
                cout << "Gry: " << polkiNaGry[i].identyfikator() << endl;
            }
            for(int i = 0; i < polkiNaKsiazki.size(); i++){
                cout << "Ksiazki: " << polkiNaKsiazki[i].identyfikator() << endl;
            }
        }

        else if(polecenie == "DK"){

            if(polkiNaKsiazki.size() == 0){
                cout << "Niestety nie ma jeszcze żadnych półek na książki" << endl;
            }
            else{

                cout << "Wpisz numer, aby wybrać półkę:" << endl;
                for(int i = 0; i < polkiNaKsiazki.size(); i++){
                    cout << i<< ": " << polkiNaKsiazki[i].identyfikator() << endl;
                }
                int numer;
                cin >> numer;
                while(numer >= polkiNaKsiazki.size() || numer < 0){
                    cout << "Ten numer jest nieprawidłowy, spróbuj jeszcze raz" << endl;
                    cin >> numer;
                }
                Ksiazka *newBook;
                cout << "Jaki rodzaj książki chcesz dodać? " << endl;
                cout << "1 - literatura" << endl;
                cout << "2 - podręcznik" << endl;
                cout << "3 - słownik" << endl;
                int wybor;
                cin >> wybor;
                if(wybor == 1){
                    string gatunek;
                    string autor;
                    string tytul;
                    getline(cin, tytul);
                    cout << "Podaj tytuł:" << endl;
                    getline(cin, tytul);
                    cout << "Podaj autora:" << endl;
                    getline(cin, autor);
                    cout << "Podaj gatunek:" << endl;
                    getline(cin, gatunek);
                    newBook = new Literatura(tytul, autor, gatunek);
                }
                else if(wybor == 2){
                    string przedmiot;
                    string autor;
                    string tytul;
                    getline(cin, tytul);
                    cout << "Podaj tytuł:" << endl;
                    getline(cin, tytul);
                    cout << "Podaj autora:" << endl;
                    getline(cin, autor);
                    cout << "Podaj przedmiot:" << endl;
                    getline(cin, przedmiot);
                    newBook = new Podrecznik(przedmiot, autor, tytul);
                }
                else if(wybor == 3){
                    string autor;
                    string tytul;
                    string jezyk1;
                    string jezyk2;
                    getline(cin, tytul);
                    cout << "Podaj tytuł:" << endl;
                    getline(cin, tytul);
                    cout << "Podaj autora:" << endl;
                    getline(cin, autor);
                    cout << "Podaj jezyk 1:"<< endl;
                    getline(cin, jezyk1);
                    cout << "Podaj jezyk 2:" << endl;
                    getline(cin, jezyk2);
                    newBook = new Slownik(jezyk1, jezyk2, autor, tytul);
                }
                polkiNaKsiazki[numer].dodajObiekt(newBook);
                cout << "Dodano książkę" << endl;
                
            }
        
            
        }
        else if(polecenie == "DG"){
            if(polkiNaGry.size() == 0){
                cout << "Niestety nie ma jeszcze żadnych półek na gry" << endl;
            }
            else{
                cout << "Wpisz numer, aby wybrać półkę:" << endl;
                for(int i = 0; i < polkiNaGry.size(); i++){
                    cout << i<< ": " << polkiNaGry[i].identyfikator() << endl;
                }
                int numer;
                cin >> numer;
                while(numer >= polkiNaGry.size() || numer < 0){
                    cout << "Ten numer jest nieprawidłowy, spróbuj jeszcze raz" << endl;
                    cin >> numer;
                }

                string tytul;
                string wydawca;
                getline(cin, tytul);
                cout << "Podaj tytuł: " << endl;
                getline(cin, tytul);
                cout << "Podaj wydawcę: " << endl;
                getline(cin, wydawca);
                Gra *newGra = new Gra(tytul, wydawca);
                polkiNaGry[numer].dodajObiekt(newGra);
                cout << "Dodano grę" << endl;
            }
            
        }
        else if(polecenie == "W"){
            cout << "Podaj tytuł:" << endl;
            string tytul;
            getline(cin, tytul);
            getline(cin, tytul);
            bool done = false;
            for(int i = 0; i < polkiNaGry.size() && !done; i++){
                if(polkiNaGry[i].wypozyczObiekt(tytul)) done = true;
            }
            for(int i = 0; i < polkiNaKsiazki.size() && !done; i++){
                if(polkiNaKsiazki[i].wypozyczObiekt(tytul)) done = true;
            }
            if(!done) cout << "niestety nie ma takiego tytułu" << endl;
            //else cout << "Wypożyczono książkę " << tytul << endl;

        }
        else if(polecenie == "Z"){
            cout << "Podaj tytuł:" << endl;
            string tytul;
            getline(cin, tytul);
            getline(cin, tytul);
            bool done = false;
            for(int i = 0; i < polkiNaGry.size() && !done; i++){
                if(polkiNaGry[i].zwrocObiekt(tytul)) done = true;
            }
            for(int i = 0; i < polkiNaKsiazki.size() && !done; i++){
                if(polkiNaKsiazki[i].zwrocObiekt(tytul)) done = true;
            }
            if(!done) cout << "niestety nie ma takiego tytułu" << endl;
            //else cout << "Zwrócono książkę " << tytul << endl;
        }
        else if(polecenie == "SP" || polecenie == "WS" || polecenie == "PP"){
            if(polkiNaGry.size() == 0 && polkiNaKsiazki.size() == 0){
                cout << "Niestety nie ma jeszcze żadnych półek" << endl;
            }
            else{
                cout << "Wpisz numer, aby wybrać półkę:" << endl;
                for(int i = 0; i < polkiNaGry.size(); i++){
                    cout << i<< ": " << polkiNaGry[i].identyfikator() << endl;
                }
                for(int i = 0; i < polkiNaKsiazki.size(); i++){
                    cout << i + polkiNaGry.size()<< ": " << polkiNaKsiazki[i].identyfikator() << endl;
                }

                int numer;
                cin >> numer;
                while(numer >= (polkiNaGry.size() + polkiNaKsiazki.size())|| numer < 0){
                    cout << "Ten numer jest nieprawidłowy, spróbuj jeszcze raz" << endl;
                    cin >> numer;
                }

                string polkaType = "g";
                if(numer >= polkiNaGry.size()){
                    polkaType = "k";
                    numer -= polkiNaGry.size();
                }

                if(polecenie == "SP"){
                    if(polkaType == "g"){
                        polkiNaGry[numer].sortuj();
                    }
                    else if(polkaType == "k"){
                        polkiNaKsiazki[numer].sortuj();
                    }
                }
                else if(polecenie == "WS"){
                    if(polkaType == "g"){
                        polkiNaGry[numer].wyswietlStatystyki();
                    }
                    else if(polkaType == "k"){
                        polkiNaKsiazki[numer].wyswietlStatystyki();
                    }
                }
                else if(polecenie == "PP"){
                    if(polkaType == "g"){
                        polkiNaGry[numer].pokazPrzedmioty();
                    }
                    else if(polkaType == "k"){
                        polkiNaKsiazki[numer].pokazPrzedmioty();
                    }
                }
            }
        }
        cout << endl;
    }
}