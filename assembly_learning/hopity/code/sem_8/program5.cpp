#include <iostream>

class A
{
    public:
        int x;
        A();
        A(int xx, int yy);
        void print();
    private:
        int y;

};

void A::print() { std::cout << x << ' ' << y << std::endl; }
A::A(): x{1}, y{2} {}
A::A(int xx, int yy) { x = xx; y = yy; }

void some_func(int n)
{
    A a;
    a.print();
    a.x = 50;
    a.print();
}