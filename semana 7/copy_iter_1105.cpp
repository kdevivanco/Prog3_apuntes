//
// Created by MacBookPro on 11/05/23.
//
//
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <algorithm>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include "point.cpp"
using namespace std;

template<typename IterIn, typename IterOut>
void copiar(IterIn start, IterIn stop, IterOut dest){
    while(start!= stop){
        *dest = *start;
        advance(start,1);
        dest = next(dest);

    }
}


//Como usar Callable Copy if....
template<typename IterIn, typename IterOut, typename Callable>
void copiar_si(IterIn start, IterIn stop, IterOut dest, Callable caller){
    while(start!= stop){
        if(caller(*start) == true){
            *dest = *start;
            advance(start,1);
            dest = next(dest);
        }

    }
}

bool is_even(double item){
    return fmod(item,2) == 0;
}




template<typename T, template<class...> class Container>
        ostream& operator<<(ostream& out, const Container<T> cnt){
    for(const auto& item : cnt){
        out << item << " ";
    }
    return out;
}


template<typename Iter>
auto sumar(Iter start,Iter end, typename Iter::value_type initial){
    using T = typename Iter::value_type;
    T suma = initial;
    while(start != end){
        suma += *start;
        advance(start,1);
    }

    return suma;
}

void ejemplo_callable(){
    vector<double> v3 = {1,2,3,4};
    vector<double> v2;
    copy_if(begin(v3), end(v3), back_inserter(v2),is_even);
    cout << v2 << endl;
}


int main(){
    vector<int> v1 = {10,20,30,50,60};
    list<int> l1 = {10,20,30};
    deque<double> d1 = {0.0,1.5,2.0};

    auto total = sumar(begin(v1), end(v1), 0);
    auto total1 = sumar(begin(l1), end(l1), 0);
    auto total2 = sumar(begin(d1), end(d1), 0);

    cout << total << endl;
    cout << total1 << endl;
    cout << total2 << endl;

    ejemplo_callable();
}