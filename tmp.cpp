//
// Created by Azusa on 2022/3/30.
//

#include <iostream>

using namespace std;

int main() {
    int type;
    bool flag = false;
    while (std::cin >> type) {
        if (!flag) flag = true;
        else cout << endl;
        if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << (a * b);
        } else {
            int a, b, c;
            cin >> a >> b >> c;
            cout << (a * b * c);
        }
    }
    return 0;
}