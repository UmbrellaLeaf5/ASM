void switcher(long long a, long long b, long long c, long long *dest) {
  long long val;

  switch (a) {
    case 5: /* Case A */
      c = b ^ 15;
      /* Fall through */
    case 0: /* Case B */
      val = 112 + c;
      break;

    case 2: /* Case C */
    case 7: /* Case D */
      val = (b + c) << 2;
      break;

    case 4: /* Case E */
      val = a;
      break;

    default:
      val = b;
  }

  *dest = val;
}