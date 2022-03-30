//
// Created by Azusa on 2022/3/3.
//

#include <iostream>

using namespace std;

class Student {
private:
    double score;
    static double total;
    static int count;
public:
    void scoretotalcount(double s);
    static double sum();
    static double average();
};

double Student::total = 0;
int Student::count = 0;

void Student::scoretotalcount(double s) {
    this->score = s;
    count++;
    total += s;
}

double Student::sum() {
    return Student::total;
}

double Student::average() {
    return Student::total / Student::count;
}

int main() {
    int score;
    while (std::cin >> score) {
        Student().scoretotalcount(score);
    }
    cout << Student::sum() << endl << Student::average();
    return 0;
}