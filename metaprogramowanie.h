#include <iostream>
#include <vector>
#include <algorithm>

//obliczanie sumy z wypozyczen na polce;
template<int N> int sum(int *x, int size){
    if(size<=0) return 0;
    return (*x) + sum<N-1>(++x, size-1);
};
template<> int sum<0>(int *x, int size){
    return 0;
};

//wariancja z  wypożyczeń
template<int N> int sumVar(int *x, int srednia, int size){
    //cout << (*x) << endl;
    if(size<=0) return 0;
    return ((*x) - srednia)*((*x) - srednia) + sumVar<N-1>(++x, srednia, size-1);
};
template<> int sumVar<0>(int *x, int srednia, int size){
    return 0;
};


template<int N> int variancja(int *x, int srednia, int size, int n){
    
    return sumVar<N>(x, srednia, size)/float(n);
};


//obliczanie indeksu ksiazki z najwieksza liczba wypozyczen
//////////////////////////////tablica/aktualny indeks/maks value/max index
template<size_t N> int najwiecej(int *x, int n, int max, int maxInd, int size){
    //cout << "x: " << (*x) << " n: " << n << " max: " << max << " maxind: " << maxInd << " size: " << size << endl;
    if(size <= 0) return (*x > max) ? n : maxInd;
    return (*x > max) ? najwiecej<N-1>(++x, n+1, *x, n, size-1) : najwiecej<N-1>(++x, n+1, max, maxInd, size-1);
};
template<> int najwiecej<1>(int *x, int n, int max, int maxInd, int size){
    return (*x > max) ? n : maxInd;
};