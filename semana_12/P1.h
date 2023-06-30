//
// Created by MacBookPro on 13/06/23.
//


#include <stack>
#include <queue>
//#include <priority_queue>
#include <iostream>
#include <deque>
#include <type_traits>
#include <list>


using namespace std;

template <template<typename...> class Adapter, typename T,typename ...Params, typename callable>
void recorrer_adaptor(Adapter<T,Params...>& adap,callable func){
    while(!adap.empty()){
        if constexpr(is_same_v<queue<T,Params...>,Adapter<T,Params...>>){
            func(adap.front());
        }
        else{
            func(adap.top());
        }
        adap.pop();
    }
}

template <template<typename...> class Adapter, typename T>
Adapter<T> merge_adaptor(Adapter<T>& ad1,Adapter<T> ad2){
    int size1 = ad1.size();
    int size2 = ad2.size();

    deque<T> deq;

    if(size1>size2){
        while(!ad2.empty()){
            deq.push_back(ad1.top());
            ad1.pop();
            deq.push_back(ad2.top());
            ad2.pop();
        }
        while(!ad1.empty()){
            deq.push_back(ad1.top());
            ad1.pop();
        }
    }
    if(size2>size1){
        while(!ad1.empty()){
            deq.push_back(ad1.top());
            ad1.pop();
            deq.push_back(ad2.top());
            ad2.pop();
        }
        while(!ad2.empty()){
            deq.push_back(ad2.top());
            ad2.pop();
        }
    }
    reverse(begin(deq),end(deq));
    Adapter<T> resp(deq);
    return resp;
}
//
//void question_1(){
//    deque<int> deq = {100,200,300,400,500};
//    stack<int> s2(deq);
//
//    deque<int> deq2 = {10, 10, 10, 10, 10, 10, 10,10};
//    //Otra forma de inicializar stack usando vector
//    stack<int> s3(deq2);
//
//    stack<int> resp = merge_adaptor(s2,s3);
//
//    recorrer_adaptor(resp,[](auto item){cout << item << endl;});
//}
//
//int main(){
//    question_1();
//}