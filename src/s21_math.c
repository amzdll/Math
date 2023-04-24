#include "s21_math.h"

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_acos(double x) { return s21_PI / 2 - s21_asin(x); }

long double s21_asin(double x) {
  double temp_result = x;
  double result = x;
  if (x < -1 || x > 1) {
    return s21_NAN;
  } else if (x == -1 || x == 1) {
    return s21_PI / 2 * x;
  }
  for (long double count = 1; s21_fabs(temp_result) > s21_EPS; count++) {
    temp_result *= ((x * x) * (2 * count - 1) * (2 * count - 1)) /
                   ((2 * count) * (2 * count + 1));
    result += temp_result;
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  if (x < 1 && x > -1 && x != 0)
    result = atan_calc(x);
  else if (x == 0)
    result = 0;
  else if (x == 1)
    result = s21_PI / 4;
  else if (x == -1)
    result = -s21_PI / 4;
  else if (x > 1)
    result = s21_PI / 2 - atan_calc(1 / x);
  else
    result = -s21_PI / 2 - atan_calc(1 / x);
  return result;
}

long double s21_ceil(double x) {
  return (int)x != x
             ? ((x < 0) ? (long double)((int)x) : (long double)((int)x + 1))
             : (double)((int)x);
}

long double s21_cos(double x) {
  if (x > 2 * s21_PI || x < -2 * s21_PI)
    x = s21_fmod(x, 2 * s21_PI);
  return s21_sin(s21_PI / 2 - x);
}

long double s21_exp(double x) {
  long double temp_result = 1;
  long double result = 1;
  int i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(temp_result) > s21_EPS) {
    temp_result *= x / i;
    i += 1;
    result += temp_result;
    if (result > s21_MAX_double) {
      result = s21_INF;
      break;
    }
  }
  (result = flag == 1 ? (result > s21_MAX_double ? 0 : 1. / result) : result);
  return result > s21_MAX_double ? s21_INF : result;
}

long double s21_fabs(double x) { return (x < 0) ? -x : x; }

long double s21_floor(double x) {
  return (int)x != x
             ? ((x < 0) ? (long double)((int)x - 1) : (long double)((int)x))
             : (long double)((int)x);
}

long double s21_fmod(double x, double y) {
  return y != 0 ? (x - ((long double)((int)(x / y))) * y) : s21_NAN;
}

long double s21_log(double x) {
  long double sign = 1;
  long double degree = 0;
  long double count = 2;
  long double result;
  long double temp_result;
  x < 0 ? (x *= -1, sign *= -1) : (x *= 1, sign *= 1);
  while ((x >= 10) || (x < 1 && x > 0))
    x < 1 && x > 0 ? (x *= 10, degree -= 1) : (x *= 0.1, degree += 1);
  x = sign * x / 10;
  if (x < 0) {
    result = -s21_NAN;
  } else if (x == 0) {
    result = -s21_INF;
  } else {
    x--;
    result = x;
    temp_result = x;
    while (s21_fabs(result) > s21_EPS) {
      result *= -x * (count - 1) / count;
      count += 1;
      temp_result += result;
    }
    result = temp_result + (degree + 1) * s21_LN10;
  }
  return result;
}

long double s21_pow(double base, double exp) {
  return exp ? (long double)s21_exp(exp * s21_log(base)) : 1.0L;
}

long double s21_sin(double x) {
  if (x > 2 * s21_PI || x < -2 * s21_PI)
    x = s21_fmod(x, 2 * s21_PI);
  long double res = 0, pow = x, fact = 1;
  for (int i = 0; s21_fabs(pow / fact) > s21_EPS; i++) {
    res += pow / fact;
    pow *= -1 * x * x;
    fact *= (2 * (i + 1)) * (2 * (i + 1) + 1);
  }
  return res;
}

long double s21_sqrt(double x) {
  long double result = 4;
  if (x < 0) {
    result = -s21_NAN;
  } else {
    long double temp = 0;
    while (s21_fabs(result - temp) > s21_EPS) {
      temp = result;
      result = (temp + x / temp) / 2;
    }
  }
  return result;
}

long double s21_tan(double x) { return (long double)(s21_sin(x) / s21_cos(x)); }

long double atan_calc(double x) {
  long double result = x, temp = x, i = 1;
  while (s21_fabs(result) > s21_EPS) {
    result = -1 * result * x * x * (2 * i - 1) / (2 * i + 1);
    i += 1;
    temp += result;
  }
  return temp;
}