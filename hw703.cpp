//
// Created by Azusa on 2022/3/12.
//
#include <iostream>

using namespace std;

class Vector {
private:
    double *data;
    int length;
public:
    Vector();

    Vector(int l);

    Vector operator+(Vector &v);

    Vector operator-(Vector &v);

    double operator*(Vector &v);

    Vector &operator=(Vector v);

    friend istream &operator>>(istream &i, Vector &v);

    friend ostream &operator<<(ostream &o, Vector &v);

    double *&get_data();

    int getLength() const;

    ~Vector();
};

Vector::Vector() : length(0), data(NULL) {

}

Vector::Vector(int l) : length(l) {
    data = new double[l];
}

Vector Vector::operator+(Vector &v) {
    if (this->length != v.getLength()) return Vector();
    Vector tmp(this->length);
    double *tmp_data = tmp.get_data();
    for (int i = 0; i < this->length; ++i) {
        tmp_data[i] = this->data[i] + v.get_data()[i];
    }
    return tmp;
}

Vector Vector::operator-(Vector &v) {
    if (this->length != v.getLength()) return Vector();
    Vector tmp(this->length);
    double *tmp_data = tmp.get_data();
    for (int i = 0; i < this->length; ++i) {
        tmp_data[i] = this->data[i] - v.get_data()[i];
    }
    return tmp;
}

double Vector::operator*(Vector &v) {
    Vector tmp(this->length);
    double result = 0;
    for (int i = 0; i < this->length; ++i) {
        result += this->data[i] * v.get_data()[i];
    }
    return result;
}


Vector &Vector::operator=(Vector v) {
    this->length = v.getLength();
    double *d = v.get_data();
    this->data = new double[this->length];
    for (int i = 0; i < v.getLength(); ++i) {
        this->data[i] = d[i];
    }
    return *this;
}

istream &operator>>(istream &i, Vector &v) {
    if (v.data == NULL) v.data = new double[v.length];
    for (int j = 0; j < v.getLength(); ++j) {
        i >> (v.get_data()[j]);
    }
    return i;
}

ostream &operator<<(ostream &o, Vector &v) {
    o << '(';
    for (int i = 0; i < v.getLength(); ++i) {
        o << (v.get_data()[i]);
        if (i < v.getLength() - 1) o << ',';
        else o << ')';
    }
    return o;
}

double *&Vector::get_data() {
    return this->data;
}

int Vector::getLength() const {
    return length;
}

Vector::~Vector() {
    if (this->data != NULL) {
        delete[]this->data;
    }
}


int main() {
    int a, b;
    bool flag = false;
    while (std::cin >> a) {
        if (!flag) flag = true;
        else cout << endl;
        Vector X(a);
        cin >> X;
        cin >> b;
        Vector Y(b);
        cin >> Y;
        Vector tmp = X + Y;
        if (tmp.getLength() == 0) {
            cout << "error";
            continue;
        }
        cout << "X=" << X << endl << "Y=" << Y << endl;
        cout << "X+Y=" << tmp << endl;
        tmp = X - Y;
        cout << "X-Y=" << tmp << endl;
        cout << "X*Y=" << (X * Y);
    }
}

