//
// Created by MacBookPro on 1/06/23.
//
#include <iostream>
#include <thread>
using namespace std;


void f1(){
    cout << "hola hilo" << endl;

}

int main(){
    //1. Crear hilo
    thread t1;

    cout << "hola main " <<endl;

    //2. Asignar el hilo
    t1 = thread(f1);
    //3. Unir el hilo
    t1.join();

    //t1.detach();
    //Se ejecuta en paralelo  // No se puede hacer a la vez (si ya estas haciendo join)

    return 0;

}
