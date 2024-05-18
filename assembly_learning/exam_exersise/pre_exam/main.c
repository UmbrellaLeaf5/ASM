long long f(long long x, long long *dest) {
  long long val = 0;

  switch (x) {
    case 1:
      val += 5;
      break;

    case 2:
      val *= 9;
      break;

    case 10:
      val = 8;
    case 20:
      val += 8;
    case 11:
      val += 8;
    case 12:
      val += 8;

    case 15:
    default:
      break;
  }

  *dest = val;
  return *dest;
}

int main() {
  long long y = 0;
  long long x = 9;

  y = f(5, &y);

  return 0;
}