//
// Created by MacBookPro on 9/05/23.
//
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include "point.cpp"
using namespace std;

template<typename T>
void bubblesort(T& input) {

    int n = input.size();
    if (n == 0 or n == 1){
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (auto it = input.begin(); next(it) != input.end(); ++it) {
            if (*it > *(next(it))) {
                swap(*it, *(next(it)));
            }
        }
    }
}

int main(){

    vector<int> myvec = {};
    array<int,5> arr = {1,3,10,5,4};
    list<float> lst = {1.5,2.5,0.5};
    deque<string> deq = {"a", "c", "b"};

    bubblesort(myvec);
    bubblesort(arr);
    bubblesort(lst);
    bubblesort(deq);

    for (const auto& element : arr){
        cout << element << " ";
    }
    cout << endl;

    for (const auto& element : arr){
        cout << element << " ";
    }
    cout << endl;

    for(const auto& element : myvec){
        cout << element <<" ";
    }
    cout << endl;

    for(const auto& element : deq){
        cout << element <<" ";
    }
    cout << endl;
    Point p1(3,4);
    Point p2(5,4);
    Point p3(1,2);


    array<Point,3> arr3 ={p1,p2,p3};

    bubblesort(arr3);

    for(const auto& element : arr3){
        cout << element ;
    }

}