void remdiv (long long x, long long y, long long *qp, long long *rp)
{
    long long q = x/y;
    long long r = x%y;
    *qp = q;
    *rp = r;
}