#include <cstring>
#include <initializer_list>
#include <iostream>

// для сборки в консоли:
// gcc -Og -c str_len.c
// gcc -Og -c str_len.s
// g++ -Og -o test str_len.o main.cpp

extern "C" __attribute__((sysv_abi)) unsigned long StrLenNiyaz(char const* str);
extern "C" __attribute__((sysv_abi)) unsigned long StrLenHopity(
    char const* str);
extern "C" unsigned long StrLenC(char const* str);

int main() {
  for (auto s : {"123", "ab", "", "0", "\t", "\n"}) {
    std::cout << "CASE: " << s << std::endl;
    // проверка нашей функции на C
    std::cout << "C:" << std::endl;
    if (strlen(s) != StrLenC(s))
      std::cout << strlen(s) << " != " << StrLenC(s) << std::endl;
    else
      std::cout << strlen(s) << " == " << StrLenC(s) << std::endl;

    // проверка функции, которую написал Нияз
    std::cout << "Niyaz:" << std::endl;
    if (strlen(s) != StrLenNiyaz(s))
      std::cout << strlen(s) << " != " << StrLenNiyaz(s) << std::endl;
    else
      std::cout << strlen(s) << " == " << StrLenNiyaz(s) << std::endl;

    // проверка функции, которую написал Никита Бучилкин
    std::cout << "Hopity:" << std::endl;
    if (strlen(s) != StrLenHopity(s))
      std::cout << strlen(s) << " != " << StrLenHopity(s) << std::endl;
    else
      std::cout << strlen(s) << " == " << StrLenHopity(s) << std::endl;

    std::cout << std::endl;
  }

  return 0;
}