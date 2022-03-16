#include <iostream>
using namespace std;

class A
{
public:
    int x; int y;
    A() { x = 1; y = 2; }
protected:
    void print() {
        cout <<"X = " << x << "\tY = " << y;
    }
};

class B : public A
{
public:
    int z;
    B() { z = 3; }

    B(int a){
        z = a;
    }

    B(int a, int b, int c) {
        x = a; y = b; z = c;
    }
    void out() {
        print();
        cout << "\tZ = " << z << endl;
    }

    B operator=(const A& other) {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

};

class weapon {
public:
    virtual void use() = 0;
};

class gun : public weapon {
public:
    void use() override {
        cout << "BANG\n";
    }
};

class mashingun : public weapon {
public:
    void use() override 
    {
        cout << "BANG BANG BANG BANG\n";
    }
};

class player {
public:
    void use(weapon *weapon) {
        weapon->use();
    }
};

int main()
{
    A dot;
    B point(10,11,12);

    point.out();
    point = dot;
    point.out();

    gun one;
    mashingun two;
    player man;
    cout << "\nStatic objects:\n";
    man.use(&one);
    man.use(&two);

    gun *onemore = new gun;
    mashingun* twomore = new mashingun;
    player* onemoreman = new player;
    cout << "\nDynamic objects:\n";
    onemoreman->use(onemore);
    onemoreman->use(twomore);

    delete twomore;
    delete onemore;
}