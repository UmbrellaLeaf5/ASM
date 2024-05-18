#include <stdbool.h>
#include <stdlib.h>

void string_changer(char* string_pointer)
{
    if(!string_pointer)
        // .L1:
        return;
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
        // .L2
        ++itr_ptr;
    }
    // 32 - diff between 'A' and 'a'
    // .L3:
    if(counter >= 10)
    {
        // .rule_1:
        itr_ptr = string_pointer;
        while(*itr_ptr != '\0')
        {
            if(*itr_ptr >= 'a' && *itr_ptr <= 'z')
            {
                *itr_ptr -= 32;
            }
            // .L4:
            ++itr_ptr;
        }
    }
    else
    {
        // .rule_2
        char* end_ptr = itr_ptr;
        char* first_itr_ptr = string_pointer;
        int current_index = 0;

        while(first_itr_ptr != end_ptr)
        {
            char* second_itr_ptr = string_pointer;
            bool duplicate_flag = false;
            while(second_itr_ptr != end_ptr)
            {
                if(second_itr_ptr != first_itr_ptr)
                {
                    if(*second_itr_ptr == *first_itr_ptr)
                    {
                        duplicate_flag = true;
                        break;
                    }
                }
                // .L7:
                ++second_itr_ptr;
            }
            // .L8:
            if(duplicate_flag == false)
            {
                string_pointer[current_index] = *first_itr_ptr;
                ++current_index;
            }
            else
            {
                // .L9:
                if(*first_itr_ptr != '\0')
                {
                    char duplicate_value = *first_itr_ptr;
                    second_itr_ptr = string_pointer;
                    while(second_itr_ptr != end_ptr)
                    {
                        if(*second_itr_ptr == duplicate_value)
                            *second_itr_ptr = '\0';
                        // .L10:
                        ++second_itr_ptr;
                    }
                }
            }
            // L6:
            ++first_itr_ptr;
        }
        // L5:
        string_pointer[current_index] = '\0';
    }
}