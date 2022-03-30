//
// Created by Azusa on 2022/3/19.
//
#include <cstdio>
#include <iostream>

using namespace std;

class Integer {
protected:
    int number;
public:
    Integer(int number) : number(number) {}

    Integer pl(Integer i) const;

    Integer mi(Integer i) const;
};

Integer Integer::pl(Integer i) const {
    return Integer(this->number + i.number);
}

Integer Integer::mi(Integer i) const {
    return Integer(this->number - i.number);
}

class Real {
protected:
    double number;
public:
    Real(double number) : number(number) {}

    Real pl(Real i) const;

    Real mi(Real i) const;
};

Real Real::pl(Real i) const {
    return Real(this->number + i.number);
}

Real Real::mi(Real i) const {
    return Real(this->number - i.number);
}

class IntReal : public Integer, public Real {
};


int main() {
    char sign;
    int type;
    bool flag = false;
    while (std::cin >> sign >> type) {
        if (!flag) flag = true;
        else cout << endl;
        switch (type) {
            case 0:
                int a, b;
                cin >> a >> b;
                cout << (sign == '+' ? a + b : a - b);
                break;
            case 1:
                double c, d;
                cin >> c >> d;
                printf("%.2f",(sign == '+' ? c + d : c - d));
                break;
            default:
                break;
        }

    }
    return 0;
}