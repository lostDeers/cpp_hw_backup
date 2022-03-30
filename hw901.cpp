//
// Created by Azusa on 2022/3/26.
//
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

class Circle {
protected:
    double radius;
public:
    virtual double area() = 0;

    virtual double volume() = 0;

    virtual ~Circle();

};

Circle::~Circle() {}

class Sphere : virtual public Circle {
public:
    Sphere(double r) { this->radius = r; }

    double area();

    double volume();
};

double Sphere::area() {
    return 4 * 3.14 * radius * radius;
}

double Sphere::volume() {
    return 4.0 / 3 * 3.14 * pow(radius, 3);
}

class Column : virtual public Circle {
protected:
    double h;
public:
    Column(double r, double h) : h(h) { radius = r; }

    virtual double area() {
        return 2 * 3.14 * radius * h + 2 * 3.14 * pow(radius, 2);
    }

    virtual double volume() {
        return h * 3.14 * pow(radius, 2);
    }
};

int main() {
    int type;
    bool flag = false;
    while (std::cin >> type) {
        if (!flag) flag = true;
        else cout << endl;
        if (type==0){
            double r;
            cin >> r;
            Sphere s(r);
            printf("%.3f\n%.3f",s.area(),s.volume());
        } else{
            double r,h;
            cin >> r >> h;
            Column c(r,h);
            printf("%.3f\n%.3f",c.area(),c.volume());
        }
    }
}