#include "check_s21_atrig.h"

START_TEST(test_s21_atan) {
  double value1 = 0.43;
  ck_assert_int_eq(s21_atan(value1), atan(value1));
  double value2 = 0.12;
  ck_assert_int_eq(s21_atan(value2), atan(value2));
  double value3 = 1;
  ck_assert_int_eq(s21_atan(value3), atan(value3));
  double value4 = -1;
  ck_assert_int_eq(s21_atan(value4), atan(value4));
  double value5 = 0;
  ck_assert_int_eq(s21_atan(value5), atan(value5));
  double value6 = 12345;
  ck_assert_int_eq(s21_atan(value6), atan(value6));
  double value7 = 0.001;
  ck_assert_int_eq(s21_atan(value7), atan(value7));
  double value8 = -12345;
  ck_assert_int_eq(s21_atan(value8), atan(value8));
  for (double i = -1; i <= 1; i += 0.01) {
    ck_assert_int_eq(s21_atan(i), atan(i));
  }

  double x = 0 / 1;
  ck_assert_int_eq(s21_atan(x), atan(x));
  ck_assert_int_eq(s21_atan(S21_NAN), atan(S21_NAN));
  ck_assert_int_eq(s21_atan(S21_INF_POSITIVE), atan(S21_INF_POSITIVE));
  ck_assert_int_eq(s21_atan(S21_INF_NEGATIVE), atan(S21_INF_NEGATIVE));
}
END_TEST

START_TEST(test_s21_acos) {
  double value1 = 0.43;
  ck_assert_int_eq(s21_acos(value1), acos(value1));
  double value2 = -1;
  ck_assert_int_eq(s21_acos(value2), acos(value2));
  double value3 = -0.999;
  ck_assert_int_eq(s21_acos(value3), acos(value3));
  for (double i = -10.; i < 10.; i += 1.) {
    ck_assert_int_eq(s21_acos(i), acos(i));
  }
  for (double i = -1; i < 1; i += 0.01) {
    ck_assert_int_eq(s21_acos(i), acos(i));
  }

  double x = 0 / 1;
  ck_assert_int_eq(s21_acos(x), acos(x));
  ck_assert_int_eq(s21_acos(S21_NAN), acos(S21_NAN));
  ck_assert_int_eq(s21_acos(S21_INF_POSITIVE), acos(S21_INF_POSITIVE));
  ck_assert_int_eq(s21_acos(S21_INF_NEGATIVE), acos(S21_INF_NEGATIVE));
}
END_TEST

START_TEST(test_s21_asin) {
  double value1 = 0.43;
  ck_assert_int_eq(s21_asin(value1), asin(value1));
  double value2 = 0.12;
  ck_assert_int_eq(s21_asin(value2), asin(value2));
  for (double i = 0.; i < 2; i += 1) {
    ck_assert_int_eq(s21_asin(i), asin(i));
  }
  for (double i = -1; i < 5; i += 0.01) {
    ck_assert_int_eq(s21_asin(i), asin(i));
  }

  double x = 0 / 1;
  ck_assert_int_eq(s21_asin(x), asin(x));
  ck_assert_int_eq(s21_asin(S21_NAN), asin(S21_NAN));
  ck_assert_int_eq(s21_asin(S21_INF_POSITIVE), asin(S21_INF_POSITIVE));
  ck_assert_int_eq(s21_asin(S21_INF_NEGATIVE), asin(S21_INF_NEGATIVE));
}
END_TEST

Suite *s21_atrig_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Atrig");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_atan);
  tcase_add_test(tc_core, test_s21_acos);
  tcase_add_test(tc_core, test_s21_asin);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_atrig() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = s21_atrig_suite();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
