//
// Created by MacBookPro on 4/05/23.
//


#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <forward_list>

using namespace std;

int main(){
    array arr = {10,20,30};

    auto it = arr.begin();
    cout << *it << endl; //obtener el valor
    cout << it[1] << endl; //se puede acceder con subindice

    it = arr.end();
    cout << *it << endl; // NO HACER ESTO

    //Para acceder al ultimo valor:
    auto rit = arr.rbegin();
    //esto es lo mismo que decir:
    array<int,3>::iterator it2 = arr.begin();
    cout << *rit << endl;
    cout << *it2 <<endl;
    int valor = *rit;
    cout << valor << endl;

}