//
// Created by Azusa on 2022/3/5.
//

#include <iostream>
#include <cstdio>

using namespace std;

struct Point {
    double x;
    double y;
};

class Line {
private:
    double a, b;
public:

    Line(double a, double b);

    void print() const;

    double getA() const;

    double getB() const;

    friend Point setPoint(Line &l1, Line &l2);
};

void Line::print() const {
    printf("y=%fx+%f\n", a, b);
}

Point setPoint(Line &l1, Line &l2) {
    Point p = {};
    p.x = (l2.getB() - l1.getB()) / (l1.getA() - l2.getA());
    p.y = (l2.getB() - l1.getB()) / (l1.getA() - l2.getA()) * l1.getA() + l1.getB();
    return p;
}

Line::Line(double a, double b) : a(a), b(b) {}

double Line::getA() const {
    return a;
}

double Line::getB() const {
    return b;
}

int main() {
    double a1, b1, a2, b2;
    bool flag = false;
    while (std::cin >> a1 >> b1 >> a2 >> b2) {
        if (!flag) flag = true;
        else cout << endl;
        Line l1(a1, b1), l2(a2, b2);
        Point result = setPoint(l1, l2);
        printf("%.2f %.2f", result.x, result.y);
    }
    return 0;
}