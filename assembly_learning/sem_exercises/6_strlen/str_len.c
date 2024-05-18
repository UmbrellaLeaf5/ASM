unsigned long StrLenC(char const* str) {
  unsigned long count = 0;
  if (str)
    while (*str != '\0') {
      ++count;
      ++str;
    }
  return count;
}