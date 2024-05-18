long exchange(long *xp, long y)
{
    long x = *xp;
    *xp = y;
    return x;
}

// $ asmlst -mabi = sysv