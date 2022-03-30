//
// Created by Azusa on 2022/3/21.
//
#include <iostream>

using namespace std;

class Integer {
protected:
    int n;
public:
    explicit Integer(int n) : n(n) {}

};

class Vector : public Integer {
protected:
    int *v;
public:
    Vector(int n, int *v) : Integer(n), v(v) {}
    Vector(): Integer(0),v(NULL){}
    friend Vector operator+(Vector &v1, Vector &v2) {
        int *p = new int[v1.n];
        for (int i = 0; i < v1.n; ++i) {
            p[i] = 0;
            p[i] = v1.v[i] + v2.v[i];
        }
        return Vector(v1.n, p);
    }

    friend Vector operator-(Vector &v1, Vector &v2) {
        int *p = new int[v1.n];
        for (int i = 0; i < v1.n; ++i) {
            p[i] = 0;
            p[i] = v1.v[i] - v2.v[i];
        }
        return Vector(v1.n, p);
    }

    friend int operator*(Vector &v1, Vector &v2) {
        int result = 0;
        for (int i = 0; i < v1.n; ++i) {
            result += v1.v[i] * v2.v[i];
        }
        return result;
    }

    friend ostream& operator<<(ostream &o,const Vector &v){
        for (int i = 0; i < v.n; ++i) {
            cout << v.v[i];
            if (i!=v.n-1) cout << ' ';
        }
        return o;
    }
    
};

int main() {
    char sign;
    int l;
    bool flag = false;
    while (std::cin >> sign >> l) {
        if (!flag) flag = true;
        else cout << endl;
        int *p = new int[l];
        for (int i = 0; i < l; ++i) {
            cin >> p[i];
        }
        Vector v1(l,p);
        p = new int[l];
        for (int i = 0; i < l; ++i) {
            cin >> p[i];
        }
        Vector v2(l,p);
        Vector vt;
        switch (sign) {
            case '+':
                vt = v1+v2;
                cout << vt;
                break;
            case '-':
                vt=v1-v2;
                cout << vt;
                break;
            case '*':
                cout << (v1*v2);
                break;
        }
    }

    return 0;
}