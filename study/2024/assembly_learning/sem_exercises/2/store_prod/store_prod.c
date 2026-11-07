#include <inttypes.h>

typedef unsigned __int128 uint128_t;

void store_prod(uint128_t *dest, uint64_t x, uint64_t y) {
  *dest = x * (uint128_t)y;
}

// записано в обратном порядке, так как так устроено в компе

// -mabi=sysv