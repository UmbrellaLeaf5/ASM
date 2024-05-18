#include <iostream>
#include <cstring>
#include <string>
#include <initializer_list>

// extern "C" __attribute__((sysv_abi)) void string_changer(char* string_pointer);
extern "C" __attribute__((sysv_abi)) bool check_property(const char* string_pointer);
extern "C" __attribute__((sysv_abi)) void procedure_1(char* string_pointer);
extern "C" __attribute__((sysv_abi)) void procedure_2(char* string_pointer);

int main()
{
    for(std::string cstr : {" ", "blabla", "hello_lol_what_TTT", "aaaaaaaaaa", "aaahhheeelllppp","aaoobhlzb", "salas",
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghi", "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijAAA",
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghiAAAACCCDDLMNOP"})
    {
        char* ptr = &cstr[0];
        std::cout << "\"" << ptr << "\"" << " => ";
        bool decider = check_property(ptr);
        if (decider)
            procedure_1(ptr);
        else
            procedure_2(ptr);

        std::cout << "\"" << ptr << "\"" << std::endl;
    }
    return 0;
}