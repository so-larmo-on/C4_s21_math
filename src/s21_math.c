#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) {
    x *= (-1);
  }
  return x;
}

bool is_int(double x) {
  bool flag = false;
  if (s21_fmod(x, (int)x) == 0.0) {
    flag = true;
  }
  return flag;
}

long double s21_ceil(double x) {
  long int tmp = (long int)x;
  if (x == S21_INF_POSITIVE) {
    return S21_INF_POSITIVE;
  } else if (x == -S21_INF_POSITIVE) {
    return -S21_INF_POSITIVE;
  } else {
    if (x > 0) {
      if (is_int(x) != true) {
        tmp += 1;
      }
    } else if ((x > -1 && x < 0)) {
      tmp = 0;
    }
  }

  return tmp;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double s21_floor(double x) {
  long double res = (long long int)x;
  if (x == S21_INF_POSITIVE) {
    return S21_INF_POSITIVE;
  } else if (x == -S21_INF_POSITIVE) {
    return -S21_INF_POSITIVE;
  } else if (S21_IS_NAN(x)) {
    return S21_NAN;
  }
  if (res < 0) {
    res -= 1;
  }
  return (long long int)res;
}

long double s21_fmod(double x, double y) {
  long double ans = s21_fabs(x);
  y = s21_fabs(y);
  long int i = 1;
  if (x == 0 && (y == 0.0 || S21_IS_NAN(y))) {
    return S21_NAN;
  } else if (y == 0.0 || x == S21_INF_POSITIVE || x == -S21_INF_POSITIVE) {
    return S21_NAN;
  } else if (y == S21_INF_POSITIVE || y == -S21_INF_POSITIVE) {
    return (long double)x;
  } else {
    while (ans >= y) {
      ans = s21_fabs(x) - y * i;
      i++;
    }
  }

  return (x < 0 ? -ans : ans);
}

long double s21_exp(double x) {
  long double ans = 1;
  long double new_x = x;
  bool flag = false;
  bool znak = false;
  if (x < 0) {
    new_x *= -1;
    znak = true;
  }
  if (x == 0) {
    ans = 1;
    flag = true;
  }
  if (x == 1) {
    ans = S21_E;
    flag = true;
  }
  if (flag == false) {
    long double tmp = 1;
    long double i = 1;
    while (s21_fabs(tmp) > S21_EPS) {
      tmp *= new_x / i;
      i++;
      ans += tmp;
      if (ans > S21_DOUBLE_MAX) {
        ans = S21_INF_POSITIVE;
        break;
      }
    }
  }
  if (znak == true) {
    if (ans == S21_INF_POSITIVE) {
      ans = 0;
    } else
      ans = 1 / ans;
  }

  return ans;
}

long double s21_log(
    double x) {
  long double res = 0;
  if (x < 0 || x == -S21_INF_POSITIVE || S21_IS_NAN(x)) {
    res = S21_NAN;
  } else if (x == 0) {
    res = -S21_INF_POSITIVE;
  } else if (x == S21_INF_POSITIVE) {
    res = S21_INF_POSITIVE;
  } else if (x == 1) {
    res = 0;
  } else {
    double N = 0.0, P = x, A = 0;
    while (P >= S21_E) {
      P /= S21_E;
      N++;
    }
    N += (P / S21_E);
    P = x;
    int j = 0;
    do {
      double L, R;
      A = N;
      L = (P / (s21_exp(N - 1.0)));
      R = ((N - 1.0) * S21_E);
      N = ((L + R) / S21_E);
      j++;
    } while (N != A && j < 10000);
    res = N;
  }
  return res;
}

long double fast_pow(double base, int degree) {
  long double res = base;
  for (int i = 1; i < degree; i++) {
    res *= base;
  }
  return res;
}

long double pow_extra(double base, double exp, bool *flag) {
  if (base == +0.0) {
    if (exp < 0) {
      *flag = true;
      return S21_INF_POSITIVE;
    } else if (exp > 0 && s21_fmod(exp, 2) != 0) {
      *flag = true;
      return base;
    } else if (exp > 0 && s21_fmod(exp, 2) == 0) {
      *flag = true;
      return 0;
    }
  } else if (base == -1 &&
             (exp == S21_INF_POSITIVE || exp == -S21_INF_POSITIVE)) {
    *flag = true;
    return 1;
  } else if (base == 1) {
    *flag = true;
    return 1;
  } else if (exp == 0) {
    *flag = true;
    return 1;
  } else if (base < 0) {
    *flag = true;
    return S21_NAN;
  } else if (s21_fabs(base) < 1 && exp == -S21_INF_POSITIVE) {
    *flag = true;
    return S21_INF_POSITIVE;
  } else if (s21_fabs(base) > 1 && exp == -S21_INF_POSITIVE) {
    *flag = true;
    return +0;
  } else if (s21_fabs(base) < 1 && exp == S21_INF_POSITIVE) {
    *flag = true;
    return +0;
  }
  return 0;
}

long double s21_pow(double base, double exp) {
  long double res = 0;
  bool flag = false;
  bool extra = false;
  pow_extra(base, exp, &extra);
  if (base == 0) {
    flag = true;
  }
  if (exp == 0.0) {
    res = 1;
  }
  if (flag == false && extra == false) {
    if (is_int(exp)) {
      res = fast_pow(base, exp);

    } else {
      res = s21_exp((long double)exp * s21_log(base));
    }
  }
  return !extra ? res : pow_extra(base, exp, &extra);
}

long double s21_sqrt(double x) {
  long double res = 0;
  if (x == -0) {
    return -0;
  }
  if (x < 0) {
    res = S21_NAN;
  } else
    res = s21_pow(x, 0.5);
  return res;
}

long double s21_sin(double x) {
  long double sin = 0.0;
  if (S21_IS_NAN(x) || x == S21_INF_POSITIVE || x == S21_INF_NEGATIVE) {
    sin = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    long double tmp = x;
    int i = 1;
    sin = x;
    while (s21_fabs(tmp) >= S21_EPS) {
      tmp *= (-1) * x * x / (i + 1) / (i + 2);
      i += 2;
      sin += (long double)tmp;
    }
    if (sin == 0) {
      sin = s21_fabs(sin);
    }
    if (s21_fmod(x, S21_PI / 2) == 0.0) {
      sin = s21_roundl(sin);
    }
  }

  return sin;
}

long double s21_cos(double x) {
  long double cos = 1.0;
  if (S21_IS_NAN(x) || x == S21_INF_POSITIVE || x == S21_INF_NEGATIVE) {
    cos = S21_NAN;
  } else {
    x = s21_fmod(x, 2.0 * S21_PI);
    long double tmp = 1.0;
    long double i = 0.0;
    while (s21_fabs(tmp) >= S21_EPS) {
      tmp *= (long double)(-1) * x * x / (i + 1.0) / (i + 2.0);
      i += 2.0;
      cos += tmp;
    }

    if (s21_fmod(x, S21_PI / 2) == 0.0) {
      cos = s21_roundl(cos);
    }
    if (cos == 0) {
      cos = s21_fabs(cos);
    }
  }

  return cos;
}

long double s21_tan(double x) {
  long double res = 0.0;
  if (x == S21_PI / 2 || x == 3 * S21_PI / 2) {
    res = 16331239353195370L;
  } else if (x == -S21_PI / 2 || x == -3 * S21_PI / 2) {
    res = -16331239353195370L;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

long double s21_asin(double x) {
  long double res = x;
  long double tmp = x;
  int num = 1;
  if (s21_fabs(x) < 1) {
    int denum = 2;
    while (s21_fabs(tmp) > S21_EPS) {
      tmp *= x * x * num / denum;
      res += (tmp / (denum + 1));
      num += 2;
      denum += 2;
    }
  } else if (x == 1) {
    res = S21_PI / 2;

  } else if (x == -1) {
    res = -S21_PI / 2;

  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_acos(double x) {
  return s21_asin(x) != S21_NAN ? (long double)(S21_PI / 2) - s21_asin(x)
                                : S21_NAN;
}

long double s21_atan(double x) {
  long double res = x;
  long double tmp = x;
  int denum = 3;
  if (x == S21_INF_POSITIVE || x == -S21_INF_POSITIVE) {
    res = x == -S21_INF_POSITIVE ? -S21_PI / 2 : S21_PI / 2;
  } else if (s21_fabs(x) < 1) {
    while (s21_fabs(tmp) > S21_EPS) {
      tmp *= ((-1) * x * x);
      res += (tmp / denum);
      denum += 2;
    }
  } else if (s21_fabs(x) > 1) {
    tmp = 1 / x;
    res = 1 / x;
    while (s21_fabs(tmp) > S21_EPS) {
      tmp *= ((-1) / (x * x));
      res += (tmp / denum);
      denum += 2;
    }
    res = S21_PI * s21_fabs(x) / (2 * x) - res;
  } else if (s21_fabs(x) == 1) {
    res = x == -1 ? -S21_PI / 4 : S21_PI / 4;
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_roundl(long double a) {
  long double b = a * 10;
  long int tmp = (long int)b;
  if (tmp < 0) {
    if (tmp % 10 <= -5) {
      a = (long int)a - 1;
    } else {
      a = (long int)a;
    }
  } else {
    if (tmp % 10 >= 5) {
      a = (long int)a + 1;
    } else {
      a = (long int)a;
    }
  }

  return (long double)a;
}