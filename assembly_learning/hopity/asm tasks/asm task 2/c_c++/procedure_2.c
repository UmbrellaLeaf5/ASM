#include <stdbool.h>

void procedure_2(char* string_pointer)
{
        if(!string_pointer)
            return;
        char* end_ptr = string_pointer;
        while(*end_ptr != '\0')
            ++end_ptr;
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
                ++second_itr_ptr;
            }
            if(duplicate_flag == false)
            {
                string_pointer[current_index] = *first_itr_ptr;
                ++current_index;
            }
            else
            {
                if(*first_itr_ptr != '\0')
                {
                    char duplicate_value = *first_itr_ptr;
                    second_itr_ptr = string_pointer;
                    while(second_itr_ptr != end_ptr)
                    {
                        if(*second_itr_ptr == duplicate_value)
                            *second_itr_ptr = '\0';
                        ++second_itr_ptr;
                    }
                }
            }
            ++first_itr_ptr;
        }
        string_pointer[current_index] = '\0';
}