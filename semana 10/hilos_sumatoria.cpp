
#include <iostream>
#include <vector>
#include <thread>
#include <numeric>

using namespace std;

//Sumatoria 2
template<typename Iterator>
int sumar_rango_iterador(int& resultado, Iterator start, Iterator stop){
    resultado = accumulate(start,stop, 0);
    return resultado;

}


//Sumatoria 2
void sumatoria_vector_iteradores(){
    int nhilos = 4;
    vector<int> v1 = {1, 7,8 , 20 , 3 , -5, 4 , 2 , 10 , 11, 20, 21};
    //Resultados:
    vector<int> resultado(nhilos);
    //Hilos
    vector<thread> vhilos(nhilos); //1. Crear los hilos
    //
    int rango = v1.size()/nhilos;

    //Para asignar la tarea a cada hilo
    for(int j = 0; j< vhilos.size(); ++j){
        //Crear el lambda
        auto res_lambda = [j, &resultado, &v1, rango](){
            sumar_rango_iterador(
                    resultado[j],
                    next(begin(v1),j*rango),
                    next(begin(v1),(j+1)*rango)
                    );
        };

        vhilos[j] = thread(res_lambda);
    }

    //El hilo principal espera el resultado de los otros
    for(int j = 0; j <vhilos.size(); ++j){
        vhilos[j].join();
    }
    auto total = accumulate(begin(resultado),end(resultado), 0 );
    cout << total << endl;
}
//Los hilos trabajan con funciones fijas, no con templates
//Para solucionar eso, usamos un lambda

void sumar_rangos(vector<int>& vdatos, int& resultado, int start, int stop){
    for (int i = start; i < stop; i++){
        resultado += vdatos[i];
    }
}


//Sumatoria 1
void sumatoria_vector(){
    int nhilos = 4;
    vector<int> v1 = {1, 7,8 , 20 , 3 , -5, 4 , 2 , 10 , 11, 20, 21};
    //Resultados:
    vector<int> resultado(nhilos);
    //Hilos
    vector<thread> vhilos(nhilos); //1. Crear los hilos
    //
    int rango = v1.size()/nhilos;

    //Para asignar la tarea a cada hilo
    for(int j = 0; j< vhilos.size(); ++j){
        vhilos[j] = thread(sumar_rangos,ref(v1),ref(resultado[j]),j*rango,(j+1)*rango); //2. Asignarle la tarea o funcion
    }
    for(int j = 0; j <vhilos.size(); ++j){
        vhilos[j].join();
    }

    auto total = accumulate(begin(resultado),end(resultado), 0 );
    cout << total << endl;
}

//Complejidad algoritmica -> n


int main(){
    //1. Crear hilo
    sumatoria_vector();
    sumatoria_vector_iteradores();
    //2. Asignar el hilo
    //3. Unir el hilo

    return 0;

}

