//
// Created by MacBookPro on 16/05/23.
//
/////Si una funcion (callable) tiene mas de cinco lineas, es mejor hacer una funcion
////lambda es usable solo para funciones inline

#include <iostream>
#include <cmath>
#include <vector>
#include<set>
#include <set>
using namespace std;
//class power_functor{
//
//};
////
////
////void ejemplo_power_functor(){
////    power_functor p3(3);
////    power_functor p3(7);
////    cout << p3(2) << endl;
////    cout << p7(3) << endl;
////    cout << power_functor(2)(3) << endl;
////}
//
//void ejemplo_power_lambda(){
//    auto p3 = [exp=3.0f](float base){return pow(base,exp);};
//    auto p6 = [exp=3.0f](float base){return pow(base,exp);};
//    cout << p3(3) << endl;
//    cout << p6(3) << endl;
//    cout << [exp=2](float base){return pow(base,exp);}(3)<<endl;
//};
//
//void ejemplo_for_each(){
//    vector<int> v(10);
//    int i = 1;
//    for_each(next(begin(v),5), end(v), [&i](auto item){
//        item+= i;
//        i += 10;
//    })
//}

int main(){
//    ejemplo_for_each();
//    ejemplo_power_lambda();
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(2);
    set<int> oldSet;
    oldSet.insert(1);
    oldSet.insert(1);
    auto s = set(v1.begin(),v1.end());

    for (const auto& elem : s){
        cout << elem << endl;
    }
}