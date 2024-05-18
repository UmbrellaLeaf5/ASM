
// long _Z5mult2ll(long, long);
long mult2(long, long);

void multstore(long x, long y, long* dest) {
  long t = mult2(x, y);
  *dest = t;
}

// commands:

// создание ".s" файла:
// gcc -Og -S -fno-asynchronous-unwind-tables mstore.c
// gcc -Og -S mstore.c

// привязка команды на простое слово:
// alias asmlst="gcc -Og -S -fno-asynchronous-unwind-tables"
// asmlst mstore.c

// создание ".o" файла:
// gcc -Og -c mstore.c

// команды отладчика (может помочь следить за регистрами):

// запуск
// gdb mstore.o

// просмотр 14 байтов (gdb):
// x/14xb multstore

// дизассемблер:
// objdump -d mstore.o

// команды, которые чаще попадаются - стараются весить меньше