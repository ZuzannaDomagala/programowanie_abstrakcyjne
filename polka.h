#include <iostream>
#include <vector>
#include <algorithm>
#include "dziedziczenie.h"
#include "metaprogramowanie.h"
using namespace::std;

//symulator biblioteki
//są książki, podzielone na : Literatura, Podręcznik, Słownik, sa też gry

template <typename T>
class Polka{
    private:
        vector<T*> przedmioty;
        string typObiektow;
        string searchTitle;
        string numerPolki;
    
    public:
    
        Polka(string t, string numer){
            numerPolki = numer;
            typObiektow = t;
        }

        string identyfikator(){
            return numerPolki;
        }

        bool polkaPelna(){
            return przedmioty.size() > 19;
        }


        void pokazPrzedmioty(){
            cout << typObiektow << " na półce:" << endl;
            typename vector<T*>::iterator it;
            for(it=przedmioty.begin(); it!=przedmioty.end(); it++){
                (*it)->wyswietlSzczegoly();
            }
        }

        void sortuj(){
            sort(begin(przedmioty), end(przedmioty), [](T* a, T* b){return (*a).tytul[0] < (*b).tytul[0];});
        }

        void dodajObiekt(T* obiekt){
           
            if(przedmioty.size() > 19){
                cout << "Ta półka jest już pełna" <<endl;
                return;
            }
            przedmioty.push_back(obiekt);
        }

    
        bool wypozyczObiekt(string title){
            typename vector<T*>::iterator it;
            it = find_if(przedmioty.begin(), przedmioty.end(), [title] (const T* a) {return a->tytul == title;});
            if(it != przedmioty.end()){
                (*it)->wypozycz();
                return true;
            }
            //cout << "Nie ma takiego tytulu" << endl;
            return false;

        }

        bool zwrocObiekt(string title){
            typename vector<T*>::iterator it;
            it = find_if(przedmioty.begin(), przedmioty.end(), [title] (const T* a) {return a->tytul == title;});
            (*it)->zwroc();
            if(it != przedmioty.end()){
                (*it)->zwroc();
                return true;
            }
            //cout << "Nie ma takiego tytulu" << endl;
            return false;
        }

        void wyswietlStatystyki(){
            int *tabA = new int[przedmioty.size() + 1];
            typename vector<T*>::iterator it;
            tabA[0] = przedmioty.size();
            for(int i = 1; i <= przedmioty.size(); i++){
                tabA[i] = przedmioty[i-1]->wypozyczenia;
            }
            cout << "####Statystyki półki####" << endl;
            cout << "Obiektów na półce: " << przedmioty.size() << endl;
            

            
            int *tmpTab = tabA;
            int i = sum<20>(++tmpTab, przedmioty.size());
            cout <<"Suma wypozyczeń: " <<  i << endl;
            int srednia = i/przedmioty.size();
            tmpTab = tabA;
            ++tmpTab;
            int maxValue = (*tmpTab);
            int j = najwiecej<20>(tmpTab, 0, maxValue, 0,  przedmioty.size()-1);
            cout << "Najczesciej wypozyczany tytuł: " << przedmioty[j]->tytul 
                 <<", ma " << przedmioty[j]->wypozyczenia << " wypożyczenia" << endl;
            tmpTab = tabA;
            int var = variancja<20>(++tmpTab, srednia, przedmioty.size(), przedmioty.size());
            cout << "Wariancja wypożyczeń: " << var << endl;
            cout << "##############" << endl;
            
        }
};