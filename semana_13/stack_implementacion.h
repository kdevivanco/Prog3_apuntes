//
// Created by MacBookPro on 20/06/23.
//

#ifndef EJERCICIOS_EN_CLASE_STACK_IMPLEMENTACION_H
#define EJERCICIOS_EN_CLASE_STACK_IMPLEMENTACION_H

#include <deque>

using namespace std;

namespace utec{

    template<typename T, typename Container = std::deque<T> >
            class stack{
                Container cnt;
            public:
                using value_type = typename Container::value_type;
                using reference = typename Container::reference;
                using const_ref = const T&;
                using size_type = typename Container::size_type;
                using container_type = Container;

                stack() = default;
                explicit  stack (const Container& other): cnt(other){}
                //Evitar utilizar asignacion
                //stack s1;
                // stack s2 = s1; <- Evitar

                size_t size() const{
                    return cnt.size();
                }

                bool empty() const{
                    return size(cnt) == 0;
                }

                void push(const T& value){
                    cnt.push_back(value);
                }

                void pop(){
                    cnt.pop_back();
                }

                const_ref top(){
                    return cnt.back();
                }

                template<typename... Param>
                void emplace(Param&&... param){
                    cnt.emplace_back(param...);
//                    cnt.emplace_back(forward<Param>(param)...);
                }
            };
}

#endif //EJERCICIOS_EN_CLASE_STACK_IMPLEMENTACION_H
