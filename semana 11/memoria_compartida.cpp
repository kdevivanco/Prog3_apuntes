//
// Created by MacBookPro on 9/06/23.
//

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <algorithm>
#include <numeric>
#include "count_frequence.h"

using namespace std;
//
//void incremento(int& x){
//    ++x;
//}

//Como fallaria:
class guardia{
    //mutex no es copiable
    mutex& mtx;
public:
    guardia(mutex& mtx_):mtx(mtx_){
        mtx.lock();
    }
    ~guardia(){
        mtx.unlock();
    }
};
 mutex mtx;

////MUTEX SE USA PARA RACE CONDITIONS
void incremento(int& x){
    //Esta linea:
    //basicamente hace un sleep
    //deja de hacer la operacion por 5 segundos
    this_thread::sleep_for(chrono::microseconds(5));
    //inicio de la sincronizacion:
    //guardia g(mtx); //Se crea y cuando sale de su contexto, siempre se destrute -> unlock
    //Esto es lo mimso que hacer:
    //lock_guard g(mtx);
    //El mas flexible es:
    unique_lock un(mtx);
    ++x;

    un.unlock();
    un.lock();
    ++x;
}


void ejemplo_variable_compartida(){

    int nh = 100;
    int rep = 100;

    for (int i = 0; i<rep; i++){
        int x = 0;
        //    int nh = thread::hardware_concurrency();
        //1. Crear los hilos
        vector<thread> vh(nh);
        //2. Asignar la tarea que tiene que hacer
        //Para este caso en particular, no necesitamos subindices
        //los hilos no son copiables, por eso tenemos que hacerlo por referencia:
        for (auto& h : vh) {
            h = thread(incremento, ref(x));
        }
        //3.
        for (auto& h : vh) {
            h.join();
        }
        cout << x << " ";
    }


}

auto generar_vector(int n,int first, int last){
    vector<int> vec;
    random_device rd;
    uniform_int_distribution<int> uid(first,last);
    for(auto& item:vec){
        item = uid(rd);
    }
    return vec;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& vec){
    for(const auto& elem : vec){
        cout << elem << " ";
    }
    return out;
}

template<typename KeyT, typename ValT>
ostream& operator<<(ostream& out, const map<KeyT,ValT>& map){
    for(const auto& [key,value] : map){
        cout << "{" << key << ":" << value << "}" << "\n";
    }
    return out;
}

void ejemplo_frecuencia(){
    auto vec = generar_vector(100,1,20);
    auto res = count_frequence(begin(vec), end(vec));
    cout << res << endl;

    //Acumulate en caso de un mapa: se agrega un lambda
    auto freq = accumulate((begin(res)),end(res),0,
                           [](auto sum, auto item){
        sum+=item.second;
        return sum;
    });
    cout << size(vec) << "==" << freq << endl;
}

int main(){
//    ejemplo_variable_compartida();
    ejemplo_frecuencia();
}