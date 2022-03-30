//
// Created by Azusa on 2022/3/3.
//

#include <iostream>

using namespace std;

class Box{
private:
    int length;
    int width;
    int height;
public:
    Box(int length, int width, int height) : length(length), width(width), height(height) {}
    void setBox(int length, int width, int height);
    int volume() const;
};

void Box::setBox(int length, int width, int height) {
    this->length=length;
    this->width=width;
    this->height=height;
}

int Box::volume() const {
    return this->length* this->height* this->width;
}

int main(){
    bool flag = false;
    int l,w,h;
    while (cin >> l >> w >> h){
        if (!flag)flag= true;
        else cout << endl;
        cout << Box(l,w,h).volume();
    }

    return 0;
}