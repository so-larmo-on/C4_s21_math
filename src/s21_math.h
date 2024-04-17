#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <limits.h>
// #include <stdio.h>
// #include <stdlib.h>

#define S21_PI 3.14159265358979323846264338327950288
#define S21_PI_2 1.57079632679489661923132169163975144
#define S21_NAN 0.0 / 0.0
#define S21_IS_NAN(x) x != x
#define S21_INF_POSITIVE +1.0 / 0.0L
#define S21_INF_NEGATIVE -1.0 / 0.0L
#define S21_EXP 1e-9L
#define S21_EPS 1e-35
#define S21_E 2.71828182845904523536028747
#define S21_IS_NAN(x) x != x
#define S21_PI_NEG -3.14159265358979323846264338327950288
#define S21_DOUBLE_MAX 1.7976931348623157e308
#define S21_M_LN10 2.30258509299404568402

#define true 1
#define false 0

typedef int bool;

// вычисляет абсолютное значение целого числа
int s21_abs(int x);

// вычисляет абсолютное значение целого числа
int s21_abs(int x);

// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x);

// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x);

// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x);

// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y);

// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x);

// вычисляет натуральный логарифм
long double s21_log(double x);

long double fast_pow(double base, int degree);

long double pow_extra(double base, double exp, bool *flag);

// возводит число в заданную степень
long double s21_pow(double base, double exp);

// вычисляет квадратный корень
long double s21_sqrt(double x);

// вычисляет синус
long double s21_sin(double x);

// вычисляет косинус
long double s21_cos(double x);

// вычисляет тангенс
long double s21_tan(double x);

// вычисляет арксинус
long double s21_asin(double x);

// вычисляет арккосинус
long double s21_acos(double x);

// вычисляет арктангенс
long double s21_atan(double x);

// округляет
long double s21_roundl(long double a);

#endif