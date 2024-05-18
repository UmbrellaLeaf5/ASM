long long shift_left4_right_n(long long x, long long n) {
  x <<= 4;
  x >>= n;
  return x;
}

// -mabi=sysv