#include <stdbool.h>

bool check_property(char* string_pointer);
void procedure_1(char* string_pointer);
void procedure_2(char* string_pointer);

void string_changer(char* string_pointer)
{
    if(check_property(string_pointer))
        procedure_1(string_pointer);
    else
        procedure_2(string_pointer);
}