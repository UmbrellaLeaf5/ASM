long long f(long long x);
char* g(long long a1, long long a2, long long a3, long long a4, long long a5,
        long long a6, char c, long long x);

long long f(long long x) {
  x += 1;
  char* c = g(x + 1, x + 2, x + 3, x + 4, x + 5, x + 6, 1, x);
  return x + 2 + *c;
}

char* g(long long a1, long long a2, long long a3, long long a4, long long a5,
        long long a6, char c, long long x) {
  char z = a1 ^ a2 ^ a3 ^ a4 ^ a5 ^ a6 ^ c ^ x;
  return 0;
}

int main() {
  long long i = f(1);
  return 0;
}