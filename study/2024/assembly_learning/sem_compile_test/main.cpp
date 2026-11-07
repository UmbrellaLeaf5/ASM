#include <iostream>

extern "C" void multstore(long, long, long*);

extern "C" long mult2(long a, long b) {
  long s = a * b;
  return s;
}

int main() {
  long d;
  multstore(2, 3, &d);
  std::cout << "2*3 -->" << d << std::endl;
}

// commands:

// попытка скомпилировать оба файла: (заработало после extern "C")
// g++ -Og -oprog main.cpp mstore.o

// посмотрим, что не так:
// создание "main.o":
// g++ -Og -c main.cpp

// просмотр объектного файла:
// objdump -d main.o
// опаньки:
// long _Z5mult2ll(long, long);
// [добавили extern "C"]

// посмотрим, что внутри .exe:
// objdump -d prog.exe | less > obj.txt