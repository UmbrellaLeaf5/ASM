#include <iostream>

extern "C" void multstore (long, long, long*);

extern "C" long mult2 (long a, long b)
{
    long s = a*b;
    return s;
}

int main()
{
    long d;
    multstore(2, 3, &d);
    std::cout << "2*3 --> " << d << std::endl;
}