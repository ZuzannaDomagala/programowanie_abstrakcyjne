#include <iostream>
using namespace::std;


class Ksiazka{
    public:
        string tytul;
        bool wypozyczona;
        string autor;
        int wypozyczenia;
        Ksiazka(string t, string a){
            tytul = t;
            autor = a;
            wypozyczona = false;
            wypozyczenia = 0;
        }
        bool wypozycz(){
            if(wypozyczona){
                cout << "Komunikat:Ta książka jest już wypożyczona" << endl;
                return false;
            }
            wypozyczona = true;
            wypozyczenia += 1;
            cout << "Wypożyczono " << tytul << endl;
            return true;
        }
        void zwroc(){
            if(!wypozyczona){
                cout << "Komunikat: Nie można zwrócić niewypożyczonej książki" << endl;
                return;
            }
            wypozyczona = false;
            cout << "Zwrócono " << tytul << endl;
        }

        virtual void wyswietlSzczegoly(){
            cout << "####SZCZEGÓŁY KSIĄŻKI#####" << endl;
            cout << "Tytuł: " <<  tytul << endl;
            cout << "Autor: " << autor << endl;
        }
};


class Literatura: public Ksiazka{
    public:
        string gatunek;
        Literatura(string t, string a, string g) : Ksiazka(t, a){
            gatunek = g;
        }
        void wyswietlSzczegoly(){
            Ksiazka::wyswietlSzczegoly();
            cout << "Gatunek: " << gatunek << endl;
            cout << ((wypozyczona) ? "Wypożyczona" : "Niewypożyczona") << endl;
            cout << "####################" << endl;
        }
};


class Slownik : public virtual Ksiazka{
    public:
        string language1;
        string language2;
        Slownik(string l1, string l2, string a, string t) : Ksiazka(t, a){
            language1 = l1;
            language2 = l2;
        }

        void wyswietlSzczegoly(){
            Ksiazka::wyswietlSzczegoly();
            cout << "Tłumaczenie: " << language1 << "-" << language2 << endl;
            cout << ((wypozyczona) ? "Wypożyczona" : "Niewypożyczona") << endl;
            cout << "####################" << endl;
        }
};

class Podrecznik : public virtual Ksiazka{
    public:
        string przedmiot;
        Podrecznik(string p, string a, string t) : Ksiazka(t, a){
            przedmiot = p;
        }
        void wyswietlSzczegoly(){
            Ksiazka::wyswietlSzczegoly();
            cout << "Przedmiot:" << przedmiot << endl;
            cout << ((wypozyczona) ? "Wypożyczona" : "Niewypożyczona") << endl;
            cout << "####################" << endl;
        }
};

class Gra{
    public:
        string tytul;
        bool wypozyczona;
        int wypozyczenia;
        string wydawca;
        Gra(string t, string w){
            tytul = t;
            wydawca = w;
            wypozyczona = false;
        }

        bool wypozycz(){
            if(wypozyczona){
                cout << "Komunikat:Ta gra jest już wypożyczona" << endl;
                return false;
            }
            wypozyczona = true;
            wypozyczenia += 1;
            cout << "Wypożyczono " << tytul << endl;
            return true;
        }
        bool zwroc(){
            if(!wypozyczona){
                cout << "Komunikat: Nie można zwrócić niewypożyczonej gry" << endl;
                return false;
            }
            wypozyczona = false;
            cout << "Zwrócono " << tytul << endl;
            return true;
        }

        void wyswietlSzczegoly(){
            cout << "####SZCZEGÓŁY GRY#####" << endl;
            cout << "Tytuł: " <<  tytul << endl;
            cout << "Wydawca: " << wydawca << endl;
            cout << ((wypozyczona) ? "Wypożyczona" : "Niewypożyczona") << endl;
            cout  << "################" << endl;
        }

};