# 0 "swap.c"
# 1 "D:\\Programs\\2023-2024\\ASM\\assembly\\sem_exercises\\7//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "swap.c"
extern int buf[];

int *bufp0 = &buf[0];
int *bufp1;

void swap() {
  bufp1 = &buf[1];

  int tmp = *bufp0;
  *bufp0 = *bufp1;
  *bufp1 = tmp;
}
