#include "tests/check_s21_atrig.h"
#include "tests/check_s21_math.h"
#include "tests/check_s21_trig.h"

int main() {
  int no_failed = 0;

  no_failed |= test_atrig();
  no_failed |= test_math();
  no_failed |= test_trig();

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}