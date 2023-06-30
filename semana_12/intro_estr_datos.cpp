
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

void ejemplo_stack(){
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    //Para visualizarlos tienes que retirarlos

    while(!s1.empty()){
        cout << s1.top() << endl;
        s1.pop();
    }

    // Se puede hacer con un for pero es mejor usar un while, ya que en un for usa una variable i que no vamos a usar
    // No tiene iteradores - Estructura compacta
    //Para la implementacion, se utiliza un deque en lugar de un vector
    deque<int> deq = {100,200,300,400,500};
    stack<int> s2(deq);
    for(int i = s2.size(); i !=0; --i){
        cout << s2.top() << endl;
        s2.pop();
    }
    //Segmentation fault
    vector<int> vec = {1,2,3,4,5,6,7};
    //Otra forma de inicializar stack usando vector
    stack<int,vector<int>> s3(vec);
//    recorrer_adaptor(s3);


}

void ejemplo_queue(){
    deque<int> deq = {10,20,30,40,50};
    queue<int> q1(deq);

    deque<int> newdeq;

    while(!q1.empty()){
        newdeq.push_back(q1.front());
        q1.pop();
    }

    for(const auto& elem : newdeq){
        cout << elem << " ";
    }

}

int main(){
//    ejemplo_stack();
    ejemplo_queue();
    return 0;

}