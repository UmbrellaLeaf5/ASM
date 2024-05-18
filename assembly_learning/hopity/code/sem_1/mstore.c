int a = 1;
char var2 = 'a';
char var3;

long mult2(long, long );
void multstore(long x, long y, long *dest)
{
    long t = mult2(x, y);
    *dest = t;
}