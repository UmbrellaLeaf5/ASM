int procprob(int a, char b, long long* u, char* v)
{
    *u += a;
    *v += b;
    return sizeof(a) + sizeof(b);
}