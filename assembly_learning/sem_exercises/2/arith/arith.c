long long arith(long long x, long long y, long long z) {
  long long t1 = x ^ y;
  long long t2 = z * (4096 + 2);
  long long t3 = t1 & 0x0F0F0F0F;
  long long t4 = t2 - t3;
  return t4;
}

// -mabi=sysv