//
// Created by kayla de vivanco
//   16/06/2023
//
#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

void ejemplo_pq(){
    vector v = {1,2,3,4};
    priority_queue q(less<int>(),std::move(v)); //Copy constructor
    cout << size(v) << endl;
    vector v1 = {1,2,3,4};
    priority_queue q2(begin(v),end(v));
    cout << size(v1) << endl;

    //si trabajas en versiones menores de c++20 :
    priority_queue<int, vector<int>, less<>> q3(less<>(),std::move(v));
}

void ejemplo_pq2(){
    vector v = {4,2,1,3};
    //El priority queue es auto sorting
    priority_queue q(greater<int>(), std::move(v));

    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();

    }
}

struct Persona{
    string nombre;
    string apellido;
    //Para usar less y grater en priority queue
    bool operator>(const Persona& other){
        return nombre>other.nombre;
    }

    bool operator<(const Persona& other){
        return nombre<other.nombre;
    }
};

//ORDENAMIENTO  CLASICO
void ejemplo_4(){
    vector v = {Persona{"ana","zapata"},
                Persona{"victor", "mago"},
                Persona{"kayla", "zooooo"}};
//greater va de menor a mayor

    priority_queue q(greater<>(), move(v));
    while(!q.empty()){
        cout << q.top().nombre << " " << q.top().apellido << endl;
        q.pop();
    }
}

//ORDENAMIENTO CON LAMBDAS
void ejemplo_5(){
    vector v = {Persona{"ana","zapata"},
                Persona{"victor", "mago"},
                Persona{"kayla", "nooooo"}};

    vector v1 = {Persona{"ana","zapata"},
                Persona{"victor", "mago"},
                Persona{"kayla", "nooooo"}};
//greater va de menor a mayor
    auto compare_desc_apellido = [](auto& a, auto& b){return a.apellido < b.apellido;};
    auto compare_asc_apellido = [](auto& a, auto& b){return a.apellido > b.apellido;};


    priority_queue q(compare_desc_apellido, move(v));
    priority_queue q2(compare_asc_apellido, move(v1));

//    while(!q.empty()){
//        cout << q.top().nombre << " " << q.top().apellido << endl;
//        q.pop();
//    }

    while(!q2.empty()){
        cout << q2.top().nombre << " " << q2.top().apellido << endl;
        q2.pop();
    }
}

int main(){
//    ejemplo_pq();
//    ejemplo_pq2();
//
ejemplo_5();

    return 0;
}