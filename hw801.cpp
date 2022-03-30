//
// Created by Azusa on 2022/3/19.
//
#include <iostream>

using namespace std;

class Rectangle{
protected:
    double length;
    double width;
public:
    Rectangle(double length, double width) : length(length), width(width) {}
    double area()const;

};

double Rectangle::area() const {
    return this->length*this->width;
}

class Rectangular:public Rectangle{
protected:
    double height;
public:
    Rectangular(double length, double width, double height) : Rectangle(length, width), height(height) {}
    double volume()const;

};

double Rectangular::volume() const {
    return this->area()*this->height;
}


int main(){
    double l,w,h;
    bool flag = false;
    while(std::cin >> l >> w >> h){
    if(!flag) flag = true;
    else cout << endl;
    cout << (Rectangular(l,w,h).volume());
    }
}
