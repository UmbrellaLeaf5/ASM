int is_pow2_loop(unsigned int N) {
  for (; N > 1; N >>= 1)
    if (N & 1 != 0) return 0;

  return 1 && N != 0;
}

int is_pow2_formula(unsigned int N) { return ((N - 1) & N) == 0 && (N != 0); }

int is_pow2_closest(unsigned int N) {
  int closest_pow2 = 1;

  while (closest_pow2 < N) closest_pow2 *= 2;

  return closest_pow2 == N;
}

int is_pow2_counter(unsigned int N) {
  unsigned int ones_counter = 0;

  for (; N > 0; N >>= 1) ones_counter += (N & 1 != 0);

  return ones_counter == 1;
}