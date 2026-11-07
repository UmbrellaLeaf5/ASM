#include <stdbool.h>

bool check_property(char* string_pointer)
{
    if(!string_pointer)
        return false;
    char* itr_ptr = string_pointer;
    int counter = 0;
    int size = 1;
    while(*itr_ptr != '\0')
    {
        if(*itr_ptr >= 'a' && *itr_ptr <= 'z')
        {
            ++counter;
        }
        ++size;
        ++itr_ptr;
    }
    if(counter >= 10)
        return true;
    return false;
}