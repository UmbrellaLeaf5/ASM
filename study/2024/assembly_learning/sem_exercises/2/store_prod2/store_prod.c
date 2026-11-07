#include <inttypes.h>

typedef __int128 int128_t;

void store_prod(int128_t *dest, int64_t x, int64_t y) {
  *dest = x * (int128_t)y;
}