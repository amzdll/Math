#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_EPS 1e-17
#define s21_MAX_double 1.7976931348623158e308
#define s21_INF 1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define S21_E 2.71828182845904523536028747135266250
#define s21_PI 3.14159265358979323846264338327950288
#define s21_LN10 2.30258509299404590109

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double atan_calc(double x);

#endif  //  SRC_S21_MATH_H_
