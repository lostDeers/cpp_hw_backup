//
// Created by Azusa on 2022/3/19.
//
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Employee {
protected:
    string name;
    double salary;
public:
    Employee(const string name) : name(name) {}
};

class Salesman : public Employee {
protected:
    static double commrate;
    double sales;
public:
    Salesman(const string name, double sales) : Employee(name), sales(sales) {}

    Salesman pay();

    void print() const;
};

double Salesman::commrate = 5.0 / 1000;

Salesman Salesman::pay() {
    this->salary = sales * Salesman::commrate;
    return *this;
}

void Salesman::print() const {
    printf("%.2f", this->salary);
}

class Salesmanager : public Salesman {
protected:
    static double monthlypay;
public:
    Salesmanager(const string &name, double sales) : Salesman(name, sales) {}

    Salesmanager pay();
};

double Salesmanager::monthlypay = 8000;

Salesmanager Salesmanager::pay() {
    Salesman::pay();
    this->salary += Salesmanager::monthlypay;
    return *this;
}


int main() {
    string n;
    int type;
    double s;
    bool flag = false;
    while (std::cin >> n >> type >> s) {
        if (!flag) flag = true;
        else cout << endl;
        switch (type) {
            case 0:
                Salesman(n, s).pay().print();
                break;
            case 1:
                Salesmanager(n, s).pay().print();
                break;
            default:
                break;
        }
    }
}