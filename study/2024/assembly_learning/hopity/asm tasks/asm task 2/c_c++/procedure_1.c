void procedure_1(char* string_pointer)
{
    char* itr_ptr = string_pointer;
    while(*itr_ptr != '\0')
    {
        if(*itr_ptr >= 'a' && *itr_ptr <= 'z')
            *itr_ptr -= 32;
        ++itr_ptr;
    }
}