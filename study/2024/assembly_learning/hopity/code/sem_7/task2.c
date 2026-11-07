unsigned long str_len(const char* str)
{
    unsigned long len = 0;
    if(str)
    {
        while(*str != '\0')
        {
            ++len;
            ++str;
        }
    }
    return len;
}