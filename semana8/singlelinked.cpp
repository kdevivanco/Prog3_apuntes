//
// Created by MacBookPro on 18/05/23.
//

#include <iostream>
#include <initializer_list>
#include <forward_list>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
namespace utec {

//Nodo
    template<class T>
    struct Node {
            T data;
            Node<T>* next = nullptr;

            Node() = default;

            Node(T data_) : data(data_) {}

            Node(T data_, Node<T>* next_) : data(data_), next(next_) {}

            Node<T>& operator*=(T var){
                data = data * var;
                return *this;
            }

            friend ostream& operator<<(ostream& os, const Node<T>& node){
                cout << node.data;
                return os;
            }

    };


    template<class T>
    class single_linked_list {
        Node<T>* head = nullptr;

    public:
        single_linked_list() = default;
        single_linked_list(const initializer_list<T>& ls) {
            for (const auto& element : ls) {
                push_front(element);
            }
        }
        ~single_linked_list() {
            while (head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void push_front(T val) {
            head = new Node<T>(val, head);
        }

        void pop_front() {
            if (head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }

        T front() const {
            return head ? head->data : T();
        }

        auto begin()  {
            sll_iterator iter;
            iter.current = head;
            return iter;
        }

        auto end() const {
            sll_iterator iter;
            return iter;
        }

        friend ostream& operator<<(ostream& os, const single_linked_list& sll){
            Node<T>* current = sll.head;
            while (current) {
                os << current->data << " ";
                current = current->next;
            }
            return os;
        }

        single_linked_list(const single_linked_list& other) {
            if (other.head == nullptr) {
                head = nullptr;
                return;
            }

            head = new Node<T>(other.head->data);

            Node<T>* current = head;
            Node<T>* otherCurrent = other.head->next;

            while (otherCurrent != nullptr) {
                current->next = new Node<T>(otherCurrent->data);
                current = current->next;
                otherCurrent = otherCurrent->next;
            }
        }

    private:
        struct sll_iterator{
            //Tiene que ser un iterador forward
            Node<T> *current = nullptr;


        public:
            bool operator==(const sll_iterator& other){
                return this->current == other.current;
            }

            bool operator!=(const sll_iterator& other){
                return this->current != other.current;
            }


            bool operator>(const sll_iterator& other){
                return this->current > other.current;
            }

            bool operator<(const sll_iterator& other){
                return this->current < other.current;
            }

            sll_iterator& operator++(){
                current = current->next;
                return *this;
            }

            T operator*(){
                return current->data;
            }

            T* operator->() const {
                return &(current->data);
            }

            friend ostream& operator<<(ostream& os, const sll_iterator& sli){
                cout << sli->data;
                return os;
            }


            //Sobrecarga operador *
            //Sobrecarga operador ->
            //Sobrecarga operador ++
            //Sobrecarga operator <<
        };


    };

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

int main(){
    cout << endl;
    cout << "test case 1" <<endl;
    utec::single_linked_list<int> sll;
    sll.push_front(10);
    sll.push_front(20);
    sll.push_front(30);
    sll.push_front(40);
    sll.push_front(50);
    cout << sll; // 50 40 30 20 10

    cout << endl << endl;
    cout << "test case 2" <<endl;
    utec::single_linked_list<double> sl1 = {10.5, 20.3, 30.2, 40.1, 50.4};
    cout << sl1; // 50.4 40.1 30.2 20.3 10.5
    cout << endl << endl;

    cout << "test case 3"<<endl;
    utec::single_linked_list<int> sl0 = {10, 20, 30, 40, 50};
    auto tota1l = accumulate(begin(sl0), end(sl0), 0); // 150
    cout << tota1l << endl;

    cout << endl;
    cout << "test case 4" <<endl;
    utec::single_linked_list<int> sl4 = {10, 20, 30, 40, 50};
    auto total = accumulate(begin(sl4), end(sl4), 0); // 150
    cout << total << endl;

    cout << endl ;
    cout << "test case 5" <<endl;
    utec::single_linked_list<int> sll5 = {10, 20, 30, 40, 50};
    auto sll6 = sll5;
    for (utec::Node<int> item: sll5){ // cambie auto& por utec::Node<int> porque no funcionaba el loop
        item *= 10;
        cout << item << " ";
    }
    cout << endl; //Funciona el loop pero no se asigna
    cout << sll5 << endl; // 500 400 300 200 100
    cout << sll6 << endl; // 50 40 30 20 10
}