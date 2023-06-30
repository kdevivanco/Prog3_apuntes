//
// Created by MacBookPro on 18/05/23.
//

#include <iostream>
#include <map>

using namespace std;
template<typename T, template<typename...> class Container>
void print_map(Container<T, T> m) {
    for (const auto& item : m) {
        cout << item.first << ": " << item.second << endl;
    }
}

class Persona{
        string nombre;

    public:
        //CONSTRUIR EN UNA SOLA LINEA
        //Persona(string n):nombre(n){};
        explicit Persona(string nombre):nombre(move(nombre)){};

        friend ostream& operator<<(ostream& os, const Persona& p){
            cout << p.nombre ;
            return os;
        }

        string get_name(){
            return nombre;
        }

        friend bool nombre_mayor(const Persona& a, const Persona& b);

        string get_nombre();
    };

bool nombre_mayor(const Persona& a, const Persona& b){
    return a.nombre>b.nombre;
}
void ejemplo_map_objetos(){
    Persona p("Jorge");
    map<int,Persona> m1;
    // Esto es solo posible si la clase tiene un parametro:
    m1.insert({1,Persona{"Joaquin"}});

    // Esto no se puede hacer no tiene orden...
    //m1.insert({Persona{"Joaquin"},1});
    //map<Persona,string> m2= {{Persona{"Ariana"},"hola"},{Persona{"Carolina"},"chau"}}; // Esto es solo posible si la clase tiene un parametro
    for (const auto& item : m1) {
        cout << item.first << ": " << item.second << endl;
    }


    map<Persona,string,function<bool(const Persona&, const Persona&)>>
    m2 ({{Persona{"Jose"}, "Jose"},
         {Persona{"Ana"},"Ana"}},nombre_mayor);

    for (const auto& item : m2) {
        cout << item.first << ": " << item.second << endl;
    }


}

void ejemplo_map(){
    cout<<endl;
    map<int,string> m1 = {{2, "Dos"}, {9,"nueve"}, {7, "siete"}};
    for (const auto& item : m1) {
        cout << item.first << ": " << item.second << endl;
    }
    map<int,string, less<>> m2(less<>{});
    m2.insert({2, "Dos"});
    m2.insert({1,"Uno"});
    m2.insert({3,"Dos"});

    cout<<endl;
    for (const auto& item : m2) {
        cout << item.first << ": " << item.second << endl;
    };
}
int main(){
    ejemplo_map();
    ejemplo_map_objetos();

}