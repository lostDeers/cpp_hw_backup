//
// Created by Azusa on 2022/3/12.
//

#include <iostream>

#define MAX 32767
#define MIN -32768
#define ERR 32768

using namespace std;

class Integer {

public:
    int data;

    Integer operator+(Integer &i) const;

    Integer operator-(Integer &i) const;

    Integer operator*(Integer &i) const;

    Integer operator/(Integer &i) const;

    explicit Integer(int d);
};

Integer::Integer(int d) : data(d) {

}

Integer Integer::operator+(Integer &i) const {
    int result = this->data + i.data;
    if (result >= MIN && result <= MAX) return Integer(result);
    return Integer(ERR);
}

Integer Integer::operator-(Integer &i) const {
    int result = this->data - i.data;
    if (result >= MIN && result <= MAX) return Integer(result);
    return Integer(ERR);
}

Integer Integer::operator*(Integer &i) const {
    int result = this->data * i.data;
    if (result >= MIN && result <= MAX) return Integer(result);
    return Integer(ERR);
}

Integer Integer::operator/(Integer &i) const {
    int result = this->data / i.data;
    if (result >= MIN && result <= MAX) return Integer(result);
    return Integer(ERR);
}

int main() {
    int a, b;
    char c;
    bool flag = false;
    while (std::cin >> a >> b >> c) {
        if (!flag) flag = true;
        else cout << endl;
        Integer _a(a), _b(b);
        Integer r(0);
        switch (c) {
            case '+':
                r=_a+_b;
                if (r.data == ERR) cout << "Data Overflow!";
                else cout << r.data;
                break;
            case '-':
                r=_a-_b;
                if (r.data == ERR) cout << "Data Overflow!";
                else cout << r.data;
                break;
            case '*':
                r = _a*_b;
                if (r.data == ERR) cout << "Data Overflow!";
                else cout << r.data;
                break;
            case '/':
                r=_a/_b;
                if (r.data == ERR) cout << "Data Overflow!";
                else cout << r.data;
                break;
        }
    }
    return 0;
}