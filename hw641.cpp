//
// Created by Azusa on 2022/3/3.
//

#include <iostream>
#include <string>

using namespace std;

class Book{
private:
    string bookname;
    int price;
    int number;
public:
    Book(const string &bookname, int price, int number) : bookname(bookname), price(price), number(number) {
        if (price<50) borrow();
        else restore();
    }
    void display() {
        cout << this->bookname << endl << this->price <<endl<< this->number;
    }

    void borrow() {
        this->number--;
    }

    void restore() {
        this->number++;
    }
};


int main (){
    bool flag= false;
    string s;
    int p,n;
    while (cin >> s>>p>>n){
        if (!flag)flag= true;
        else cout << endl;
        Book(s,p,n).display();
    }
    return 0;
}