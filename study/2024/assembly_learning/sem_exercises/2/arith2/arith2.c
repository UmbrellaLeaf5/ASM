long long arith2(long long x, long long y, long long z) {
  long long t1 = x | y;
  long long t2 = t1 >> 3;
  long long t3 = ~t2;
  long long t4 = z - t3;
  return t4;
}