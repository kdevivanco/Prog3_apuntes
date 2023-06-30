-//
// Created by MacBookPro on 6/06/23.
//
#include <thread>
#include <vector>
#include <iostream>

using namespace std;



template <typename Iterator>
auto sumatoria_paralela(Iterator start, Iterator stop ){
    int nhilos = thread::hardware_concurrency();
    int rango - distance(Start,stop)/nhilos;
    //Definimos contenedores
    Using T = typename Iterator::value_type;
    vector<T> resultado(nhilos);
    vector<thread> vhilos(nhilos);

    //Para asignar la area a cada hilo

    for(int j = 0; j <vhilos.size(); ++j){
        auto rstart = next(start, j*rango);
        auto rstop = j < vhilos.size() - 1 ? //Sgino de pregunta es como if else
                next(start,(j+1)*rango):
                stop;
        vhilos[j] = thread(
                sumar_rango_iterador<vector<int>::iterator>,
                        ref(resultado[j]),

                )
    }


    //en el for: calculo de rangos usando iteradores
}