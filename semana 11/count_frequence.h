//
// Created by MacBookPro on 9/06/23.
//

#ifndef UNTITLED1_COUNT_FREQUENCE_H
#define UNTITLED1_COUNT_FREQUENCE_H
#include <iostream>
#include <iterator>
#include <thread>
#include <mutex>
#include <vector>
#include <map>

using namespace std;


mutex mtx;

template<typename Iterator, typename T = typename Iterator::value_type>
void frequence(Iterator start, Iterator stop, map<T,int>& results){
    while (start != stop){

        results[*start]++;
        ++start;
    }
}


template<typename Iterator>
auto count_frequence(Iterator start, Iterator stop){
    auto n = distance(start,stop);
    auto nh = n < thread::hardware_concurrency()? 1 : thread::hardware_concurrency();
    auto rango = n / nh;
    // Creamos los repositorios
    vector<thread> vh(nh);
    using T = typename Iterator::value_type; //Esto nos da el tipo que representa el iterador
    map<T, int> results;

    // Asignar tarea al hilo
    for (int i = 0; i < nh; i++){
        //Calculo de subrangos
        auto r_start = next(start, (i*rango));
        //Cualquiera anterior al ultimo rango, en caso del ultimo rango: se pone en end
        auto r_stop = i < nh - 1 ? next(start,(i+1)*rango):stop;
        //Asignamos la tarea:
        //vh[i] = thread(...,r_start,r_stop,ref(results));
        //thread(...,donde inicia, donde termina,donde se graba )
        //Asignar la tarea
        vh[i] = thread(frequence<Iterator>,r_start,r_stop,ref(results));
    }
    for (int i = 0; i < nh; i++){
        vh[i].join();
    }
    return results;

}

#endif //UNTITLED1_COUNT_FREQUENCE_H
