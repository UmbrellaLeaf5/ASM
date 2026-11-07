long long shift_left4_rightn (long long x, long long n)
{
    x <<= 4;
    x >>= n;
    return x;
}

// $ gcc -c file.s
// $ objdump -d file.o