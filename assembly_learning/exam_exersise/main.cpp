extern "C" __attribute__((sysv_abi)) int is_pow2(unsigned int N);
extern "C" __attribute__((sysv_abi)) int is_pow2_compiler(unsigned int N);

#include <iostream>

extern "C" int is_pow2_loop(unsigned int N);
extern "C" int is_pow2_formula(unsigned int N);
extern "C" int is_pow2_closest(unsigned int N);
extern "C" int is_pow2_counter(unsigned int N);

int main() {
  struct {
    int N;
  } cases[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    bigger_cases[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
                      22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33};

  for (auto c : cases) {
    std::cout << c.N << "| ";

    std::cout << is_pow2(c.N) << " ";
    std::cout << is_pow2_compiler(c.N) << " ";

    std::cout << is_pow2_loop(c.N) << " ";
    std::cout << is_pow2_formula(c.N) << " ";
    std::cout << is_pow2_closest(c.N) << " ";
    std::cout << is_pow2_counter(c.N) << std::endl;
  }

  std::cout << std::endl;

  for (auto c : bigger_cases) {
    std::cout << c.N << "| ";

    std::cout << is_pow2(c.N) << " ";
    std::cout << is_pow2_compiler(c.N) << " ";

    std::cout << is_pow2_loop(c.N) << " ";
    std::cout << is_pow2_formula(c.N) << " ";
    std::cout << is_pow2_closest(c.N) << " ";
    std::cout << is_pow2_counter(c.N) << std::endl;
  }

  return 0;
}
