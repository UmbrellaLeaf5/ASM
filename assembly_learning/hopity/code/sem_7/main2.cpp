#include <cstring>
#include <initializer_list>
#include <iostream>
#include <stdio.h>
extern "C" __attribute__((sysv_abi)) unsigned long str_len(const char* str);


int main()
{
    for(const char* s : {"123", "ab", "", "0"})
    {
        auto r1 = str_len(s);
        auto r2 = strlen(s);
        std::cout << s << std::endl;
        if(r1 != r2)
            std::cout << r1 << " != " << r2 << std::endl;
    }
}

// gcc -Og -c task2.c main2.cpp
// g++ -Og -o test task2.o main2.cpp