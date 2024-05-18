#include <iostream>

extern "C" __attribute__((sysv_abi)) long long* array();


int main()
{
    long long* arr = array();
    for(int i = 0; i < 0; ++i)
    {
        std::cout << arr[0] << ' ';
    }
    std::cout << '\n';
}