//
// Created by Azusa on 2022/3/12.
//
#include <iostream>
#include <cstdio>

using namespace std;

class nauticalmile_kilometer {
private:
    double kilometer;
    double meter;
public:
    nauticalmile_kilometer(double kilometer, double meter);

    nauticalmile_kilometer();

    operator double() const;
};

nauticalmile_kilometer::nauticalmile_kilometer(double kilometer, double meter) : kilometer(kilometer), meter(meter) {}

nauticalmile_kilometer::nauticalmile_kilometer() {}

nauticalmile_kilometer::operator double() const {
    return (kilometer + meter * 0.001) / 1.852;
}


int main() {
    double k, m;
    bool flag = false;
    while (std::cin >> k >> m) {
        if (!flag) flag = true;
        else cout << endl;
        nauticalmile_kilometer n(k, m);
        printf("%.4f", double(n));
    }
    return 0;
}