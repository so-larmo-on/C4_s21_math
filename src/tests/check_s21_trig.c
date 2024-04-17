#include "check_s21_trig.h"

START_TEST(test_s21_tan) {
  double value1 = 0.23;
  ck_assert_int_eq(s21_tan(value1), tan(value1));
  double value2 = 1234567;
  ck_assert_int_eq(s21_tan(value2), tan(value2));
  double value3 = -1234567;
  ck_assert_int_eq(s21_tan(value3), tan(value3));
  for (double i = -100; i < 100; i += 2) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
  ck_assert_int_eq(s21_tan(S21_PI / 2), tan(S21_PI / 2));

  double x = 0 / 1;
  ck_assert_int_eq(s21_tan(x), tan(x));
  ck_assert_int_eq(s21_tan(S21_NAN), tan(S21_NAN));
  ck_assert_int_eq(s21_tan(S21_INF_POSITIVE), tan(S21_INF_POSITIVE));
  ck_assert_int_eq(s21_tan(S21_INF_NEGATIVE), tan(S21_INF_NEGATIVE));

  ck_assert_int_eq(s21_tan(-S21_PI / 2), tan(-S21_PI / 2));
}
END_TEST

START_TEST(test_s21_cos) {
  double value1 = 0;
  ck_assert_int_eq(s21_cos(value1), cos(value1));
  double value2 = 112343;
  ck_assert_int_eq(s21_cos(value2), cos(value2));
  double value3 = -312345;
  ck_assert_int_eq(s21_cos(value3), cos(value3));
  // for (double i = S21_INF_NEGATIVE; i < S21_PI; i += 0.01) {
  //   ck_assert_int_eq(s21_cos(i), cos(i));
  // }
  ck_assert_int_eq(s21_cos(S21_PI / 2), cos(-S21_PI / 2));
  ck_assert_int_eq(s21_cos(S21_PI), cos(-S21_PI));
  ck_assert_int_eq(s21_cos(3 * S21_PI / 2), cos(-3 * S21_PI / 2));
  ck_assert_int_eq(s21_cos(2 * S21_PI), cos(-2 * S21_PI));

  ck_assert_int_eq(s21_cos(-S21_PI / 2), cos(-S21_PI / 2));
  ck_assert_int_eq(s21_cos(-S21_PI), cos(-S21_PI));
  ck_assert_int_eq(s21_cos(-3 * S21_PI / 2), cos(-3 * S21_PI / 2));
  ck_assert_int_eq(s21_cos(-2 * S21_PI), cos(-2 * S21_PI));

  double x = 0 / 1;
  ck_assert_int_eq(s21_cos(x), cos(x));
  ck_assert_int_eq(s21_cos(S21_NAN), cos(S21_NAN));
  ck_assert_int_eq(s21_cos(S21_INF_POSITIVE), cos(S21_INF_POSITIVE));
  ck_assert_int_eq(s21_cos(S21_INF_NEGATIVE), cos(S21_INF_NEGATIVE));
}
END_TEST

START_TEST(test_s21_sin) {
  double value1 = 0;
  ck_assert_int_eq(s21_sin(value1), sin(value1));
  double value2 = 1234567;
  ck_assert_int_eq(s21_sin(value2), sin(value2));
  double value3 = -3234567;
  ck_assert_int_eq(s21_sin(value3), sin(value3));
  for (double i = -S21_PI; i < S21_PI; i += 0.01) {
    ck_assert_int_eq(s21_sin(i), sin(i));
  }

  ck_assert_int_eq(s21_sin(S21_PI / 2), sin(S21_PI / 2));
  ck_assert_int_eq(s21_sin(S21_PI), sin(S21_PI));
  ck_assert_int_eq(s21_sin(3 * S21_PI / 2), sin(3 * S21_PI / 2));
  ck_assert_int_eq(s21_sin(2 * S21_PI), sin(2 * S21_PI));

  ck_assert_int_eq(s21_sin(-S21_PI / 2), sin(-S21_PI / 2));
  ck_assert_int_eq(s21_sin(-S21_PI), sin(-S21_PI));
  ck_assert_int_eq(s21_sin(-3 * S21_PI / 2), sin(-3 * S21_PI / 2));
  ck_assert_int_eq(s21_sin(-2 * S21_PI), sin(-2 * S21_PI));

  double x = 0 / 1;
  ck_assert_int_eq(s21_sin(x), sin(x));
  ck_assert_int_eq(s21_sin(S21_NAN), sin(S21_NAN));
  ck_assert_int_eq(s21_sin(S21_INF_POSITIVE), sin(S21_INF_POSITIVE));
  ck_assert_int_eq(s21_sin(S21_INF_NEGATIVE), sin(S21_INF_NEGATIVE));
}
END_TEST

Suite *s21_trig_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("S21 Ttrig");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_tan);
  tcase_add_test(tc_core, test_s21_cos);
  tcase_add_test(tc_core, test_s21_sin);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_trig() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = s21_trig_suite();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}