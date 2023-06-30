//
// Created by MacBookPro on 20/06/23.
//

#ifndef EJERCICIOS_EN_CLASE_PRIORITY_QUEUE_IMPLEMENTATION_H
#define EJERCICIOS_EN_CLASE_PRIORITY_QUEUE_IMPLEMENTATION_H

#include <deque>
#include <vector>
#include <iostream>

using namespace std;

namespace utec{
    template <typename T, typename Container = vector<T>, typename Compare = less<typename Container::value_type> >
    class priority_queue {
        Container cnt;
        Compare cmp;
    public:
        priority_queue() = default;

        explicit priority_queue(const Container &other) : cnt(other) {}
        explicit priority_queue(const Compare &other) : cmp(other) {}
        explicit priority_queue(const Container &other, const Compare &other2) : cnt(other), cmp(other2) {}

        //pop()
        void pop() {
            cnt.pop_back();
        }

        //push()
        void push(const T &value) {
            cnt.push_back(value);
        }

        //top
        const T &top() {
            return cnt.back();
        }

        //size
        size_t size() const {
            return cnt.size();
        }

        //empty
        bool empty() const {
            return cnt.empty();
        }

        //emplace
        template<typename... Param>
        void emplace(Param &&... param) {
            cnt.emplace_back(param...);
        }

        //size
        size_t size() {
            return cnt.size();
        }

    };

}


//HEAP ES UN ARBOL BINARIO COMPLETO:
//- TODOS LOS NIVELES ESTAN LLENOS
//- EL NODO PADRE ES MAYOR QUE LOS NODOS HIJOS (root)
//En el caso de un arbol binario soslo se tienen dos nodos -> left child, right child
//        En el caso de un arbol binario completo, el ultimo nivel puede no estar lleno, pero si lo esta, los nodos se llenan de izquierda a derecha
//        El nodo parent es cualquiera que tenga hijos
//
//        En el heap el cero se descarta en cuanto a indicies (se empieza en 1)
//El indice del nodo padre es i/2
//Se utilizan tres equaciones:





#endif //EJERCICIOS_EN_CLASE_PRIORITY_QUEUE_IMPLEMENTATION_H
