#include <iostream>

unsigned int CountBetweenFT(int n, int* m) {
  int counter = 0;
  for (int i = 0; i < n; i++)
    if (m[i] > m[0])
      if (m[i] < m[1]) counter++;
  return counter;
}

extern "C" __attribute__((sysv_abi)) unsigned int CBFT(int n, int* m);

int main() {
  int m[5];
  m[0] = 4;
  m[1] = 10;

  m[2] = 0;
  m[3] = 5;
  m[4] = 10;

  std::cout << CountBetweenFT(5, m) << std::endl;
  std::cout << CBFT(5, m) << std::endl;

  return 0;
}