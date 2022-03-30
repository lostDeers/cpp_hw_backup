//
// Created by Azusa on 2022/3/12.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;




class RMB {
private:
    int yuan;
    int jiao;
    int fen;
    bool mark;
public:
    RMB(int yuan, int jiao, int fen, bool mark) : yuan(yuan), jiao(jiao), fen(fen), mark(mark) {}

    explicit RMB(double m);

    RMB();



    friend ostream &operator<<(ostream &o, const RMB &r);

    friend istream &operator>>(istream &i,RMB &r);

    friend RMB operator+(const RMB &a,const RMB &b);

    friend RMB operator-(const RMB &a,const RMB &b);
    friend RMB operator*(const RMB &a,const RMB &b);
    friend RMB operator/(const RMB &a,const RMB &b);

    operator double() const;
};

RMB operator+(const RMB &a, const RMB &b) {
    return RMB(double (a)+double (b));
}

RMB operator-(const RMB &a, const RMB &b) {
    return RMB(double (a)-double (b));
}

RMB operator*(const RMB &a, const RMB &b) {
    return RMB(double (a)*double (b));
}

RMB operator/(const RMB &a, const RMB &b) {
    return RMB(double (a)/double (b));
}

RMB::RMB(double m) {
    this->yuan = int(m);
    this->jiao = int(m * 10) % 10;
    this->fen = int(m * 100) % 10;
    if (m >= 0) this->mark = true;
    else mark = false;
    this->yuan = abs(this->yuan);
    this->fen = abs(this->fen);
    this->jiao = abs(this->jiao);
    if (abs(int(m*1000)%10)>5)this->fen++;
}

RMB::RMB() : yuan(0), jiao(0), fen(0), mark(true) {

}

RMB::operator double() const {
    return (this->mark?1:-1)*(this->yuan + this->jiao * 0.1 + this->fen * 0.01);
}

ostream &operator<<(ostream &o, const RMB &r) {
    if (!r.mark)cout << '-';
    o << r.yuan << 'Y' << r.jiao << 'J' << r.fen << 'F';
    return o;
}

istream &operator>>(istream &i, RMB &r) {
    int yuan,jiao,fen;
    i >> yuan >> jiao >> fen;
    r = RMB(yuan+jiao*0.1+fen*0.01);
    return i;
}


int main() {
    RMB a, b;
    double c;
    while (cin >> a) {
        //cout <<"b:\n";
        cin >> b;
        //cout <<"c:\n";
        cin >> c;
        cout << "a = " << a <<endl << "b = " << b <<endl << "c = " << RMB(c);
        cout <<endl;
        cout << "a + c = " << RMB(a + c);
        cout <<endl;
        cout << "a - b = " << RMB(a - b);
        cout <<endl;
        cout << "b * 2 = " << RMB(b * 2);
        cout <<endl;
        cout << "a * 0.5 = " << RMB(a * 0.5);
        cout << endl;
    }
    return 0;
}
