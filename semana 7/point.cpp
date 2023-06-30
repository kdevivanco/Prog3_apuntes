//
// Created by MacBookPro on 9/05/23.
//
#include <iostream>
#include <cmath>

using namespace std;


class Point{
private:
    int _x;
    int _y;
    float distance;

public:
    Point(int x,int y){
        _x = x;
        _y = y;
        distance = sqrt(x*x + y*y); // sqrt(suma de cuadrados)
    }

    friend bool operator>(const Point& pt1, const Point& pt2){
        return pt1.distance > pt2.distance;
    }

    friend ostream& operator<<(ostream& os, const Point& p){
        cout << "(" << p._x << "," << p._y << ") ";
        //cout << "distancia: "<< p.distance  << endl;
        return os;
    }

};