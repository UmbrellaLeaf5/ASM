#include <iostream>
#include <cstring>
#include <string>
#include <initializer_list>

extern "C" __attribute__((sysv_abi)) void string_changer(char* string_pointer);


int main()
{
    for(std::string cstr : {" ", "blabla", "hello_lol_what_TTT", "aaaaaaaaaa", "aaahhheeelllppp", "aaoobhlzb", "salas",
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghi", "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijAAA",
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghiAAAACCCDDLMNOP"})
    {
        char* ptr = &cstr[0];
        string_changer(ptr);

        std::cout << ptr << std::endl;
    }
    return 0;
}