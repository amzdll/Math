#include <check.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(s21_abs_Test) {
    ck_assert_int_eq(s21_abs(0), abs(0));
    ck_assert_int_eq(s21_abs(1), abs(1));
    ck_assert_int_eq(s21_abs(123456), abs(123456));
    ck_assert_int_eq(s21_abs(-654321), abs(-654321));
    ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
    ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
    for (int i = -100; i < 100; i++) ck_assert_int_eq(s21_abs(i), abs(i));
}
END_TEST

START_TEST(s21_acos_Test) {
    ck_assert_ldouble_eq_tol(s21_acos(0), acosl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(1), acosl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(-1), acosl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(0.123456), acosl(0.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(0.999999), acosl(0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(0.8548554859569656265265),
                             acosl(0.8548554859569656265265), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(-0.8548554859569656265265),
                             acosl(-0.8548554859569656265265), 1e-7);
}
END_TEST

START_TEST(s21_asin_Test) {
    ck_assert_ldouble_eq_tol(s21_asin(0), asinl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(1), asinl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(-1), asinl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(0.123456), asinl(0.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(0.999999), asinl(0.999999), 1e-7);
    ck_assert_double_eq_tol(s21_acos(0.8548554859569656265265),
                            acos(0.8548554859569656265265), 1e-7);
    ck_assert_double_eq_tol(s21_acos(-0.8548554859569656265265),
                            acos(-0.8548554859569656265265), 1e-7);
    ck_assert_double_eq_tol(s21_acos(0.54879632145874562),
                            acos(0.54879632145874562), 1e-7);
}
END_TEST

START_TEST(s21_atan_Test) {
    ck_assert_ldouble_eq_tol(s21_atan(0), atanl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(1), atanl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-1), atanl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(0.123456), atanl(0.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-0.654321), atanl(-0.654321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(0.999999), atanl(0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(123456), atanl(123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-654321), atanl(-654321), 1e-7);
    for (double i = -1; i <= 1; i += 0.01)
        ck_assert_ldouble_eq_tol(s21_atan(i), atanl(i), 1e-7);
}
END_TEST

START_TEST(s21_ceil_Test) {
    ck_assert_ldouble_eq_tol(s21_ceil(0), ceill(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-0), ceill(-0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(0.000001), ceill(0.000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-0.000001), ceill(-0.000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(0.999999), ceill(0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-0.999999), ceill(-0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(12.123456), ceill(12.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-31.654321), ceill(-31.654321), 1e-7);
}
END_TEST

START_TEST(s21_cos_Test) {
    ck_assert_ldouble_eq_tol(s21_cos(0), cosl(0), 1e76);
    ck_assert_ldouble_eq_tol(s21_cos(1), cosl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(0.123456), cosl(0.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(0.999999), cosl(0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(123456), cosl(123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(-654321), cosl(-654321), 1e-7);
    for (double i = -s21_PI; i < s21_PI; i += 0.001)
        ck_assert_ldouble_eq_tol(s21_cos(i), cosl(i), 1e-7);
}
END_TEST

START_TEST(s21_exp_Test) {
    ck_assert_ldouble_eq_tol(s21_exp(0), expl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(1), expl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(0.123456), expl(0.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(-0.654321), expl(-0.654321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(0.999999), expl(0.999999), 1e-7);
    ck_assert_ldouble_eq(s21_exp(123456), expl(123456));
    ck_assert_ldouble_eq_tol(s21_exp(-654321), expl(-654321), 1e-7);
    for (double i = -10; i < 10; i++)
        ck_assert_ldouble_eq_tol(s21_exp(i), expl(i), 1e-7);
}
END_TEST

START_TEST(s21_fabs_Test) {
    double value = 0;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = 1;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = 123456;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = -654321;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = 0.123456;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    value = -0.654321;
    ck_assert_ldouble_eq_tol(s21_fabs(value), fabs(value), 1e-7);
    for (double i = -100; i < 100; i += 0.1)
        ck_assert_ldouble_eq_tol(s21_fabs(i), fabs(i), 1e-7);
}
END_TEST

START_TEST(s21_floor_Test) {
    ck_assert_ldouble_eq_tol(s21_floor(0), floorl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-0), floorl(-0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(0.000001), floorl(0.000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-0.000001), floorl(-0.000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(0.999999), floorl(0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-0.999999), floorl(-0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(12.123456), floorl(12.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-31.654321), floorl(-31.654321), 1e-7);
}
END_TEST

START_TEST(s21_fmod_Test) {
    ck_assert_ldouble_eq_tol(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7),
                             1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(36677.546546, 4.1),
                             fmod(36677.546546, 4.1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(23.456, -4.355), fmod(23.456, -4.355),
                             1e-7);
}
END_TEST

START_TEST(s21_log_Test) {
    ck_assert_ldouble_eq_tol(s21_log(0.123456), logl(0.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(1), logl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(1.999999), logl(1.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(2), logl(2), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(123456), logl(123456), 1e-7);
}
END_TEST

START_TEST(s21_pow_Test) {
    ck_assert_ldouble_eq_tol(s21_pow(0, 0.), pow(0, 0.), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(2.6, 0.), pow(2.6, 0.), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(1, 2.6), pow(1, 2.6), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(0., 2.6), pow(0., 2.6), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(2.6, 3.45), pow(2.6, 3.45), 1e-7);
    ck_assert_int_eq(s21_pow(-2.6, 3.45) == NAN, pow(-2.6, 3.45) == NAN);
    ck_assert_ldouble_eq_tol(s21_pow(2, 3), pow(2, 3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(-2, 0), pow(-2, 0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(3.0, -14.0), pow(3.0, -14.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(31.456, 4.3), pow(31.456, 4.3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(31.456, 0.3), pow(31.456, 0.3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(4.3, 4.3), pow(4.3, 4.3), 1e-7);
    ck_assert_ldouble_eq(s21_pow(123456, -654321), pow(123456, -654321));
}
END_TEST

START_TEST(s21_sin_Test) {
    ck_assert_ldouble_eq_tol(s21_sin(0), sinl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(1), sinl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(0.123456), sinl(0.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(0.999999), sinl(0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(123456), sinl(123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(-654321), sinl(-654321), 1e-7);
    for (double i = -s21_PI; i < s21_PI; i += 0.001)
        ck_assert_ldouble_eq_tol(s21_sin(i), sinl(i), 1e-7);
}
END_TEST

START_TEST(s21_sqrt_Test) {
    ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrtl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(16.), sqrtl(16.), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(123456), sqrtl(123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.123456), sqrtl(0.123456), 1e-7);
    ck_assert_ldouble_eq(s21_sqrt(0.999999), sqrtl(0.999999));
    for (double i = 0; i <= 1000; i++)
        ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrtl(i), 1e-7);
}
END_TEST

START_TEST(s21_tan_Test) {
    ck_assert_ldouble_eq_tol(s21_tan(0), tanl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(1), tanl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(0.123456), tanl(0.123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(0.999999), tanl(0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(123456), tanl(123456), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(-654321), tanl(-654321), 1e-7);
    for (double i = -s21_PI; i < s21_PI; i += 0.001)
        ck_assert_ldouble_eq_tol(s21_tan(i), tanl(i), 1e-7);
}
END_TEST

int main() {
    Suite *suite = suite_create("S21_Debuger");
    SRunner *srunner = srunner_create(suite);

    TCase *s21_abs_Case = tcase_create("s21_abs_Case");
    suite_add_tcase(suite, s21_abs_Case);
    tcase_add_test(s21_abs_Case, s21_abs_Test);

    TCase *s21_acos_Case = tcase_create("s21_acos_Case");
    suite_add_tcase(suite, s21_acos_Case);
    tcase_add_test(s21_acos_Case, s21_acos_Test);

    TCase *s21_asin_Case = tcase_create("s21_asin_Case");
    suite_add_tcase(suite, s21_asin_Case);
    tcase_add_test(s21_asin_Case, s21_asin_Test);

    TCase *s21_atan_Case = tcase_create("s21_atan_Case");
    suite_add_tcase(suite, s21_atan_Case);
    tcase_add_test(s21_atan_Case, s21_atan_Test);

    TCase *s21_ceil_Case = tcase_create("s21_ceil_Case");
    suite_add_tcase(suite, s21_ceil_Case);
    tcase_add_test(s21_ceil_Case, s21_ceil_Test);

    TCase *s21_cos_Case = tcase_create("s21_cos_Case");
    suite_add_tcase(suite, s21_cos_Case);
    tcase_add_test(s21_cos_Case, s21_cos_Test);

    TCase *s21_exp_Case = tcase_create("s21_exp_Case");
    suite_add_tcase(suite, s21_exp_Case);
    tcase_add_test(s21_exp_Case, s21_exp_Test);

    TCase *s21_fabs_Case = tcase_create("s21_fabs_Case");
    suite_add_tcase(suite, s21_fabs_Case);
    tcase_add_test(s21_fabs_Case, s21_fabs_Test);

    TCase *s21_floor_Case = tcase_create("s21_floor_Case");
    suite_add_tcase(suite, s21_floor_Case);
    tcase_add_test(s21_floor_Case, s21_floor_Test);

    TCase *s21_fmod_Case = tcase_create("s21_fmod_Case");
    suite_add_tcase(suite, s21_fmod_Case);
    tcase_add_test(s21_fmod_Case, s21_fmod_Test);

    TCase *s21_log_Case = tcase_create("s21_log_Case");
    suite_add_tcase(suite, s21_log_Case);
    tcase_add_test(s21_log_Case, s21_log_Test);

    TCase *s21_pow_Case = tcase_create("s21_pow_Case");
    suite_add_tcase(suite, s21_pow_Case);
    tcase_add_test(s21_pow_Case, s21_pow_Test);

    TCase *s21_sin_Case = tcase_create("s21_sin_Case");
    suite_add_tcase(suite, s21_sin_Case);
    tcase_add_test(s21_sin_Case, s21_sin_Test);

    TCase *s21_sqrt_Case = tcase_create("s21_sqrt_Case");
    suite_add_tcase(suite, s21_sqrt_Case);
    tcase_add_test(s21_sqrt_Case, s21_sqrt_Test);

    TCase *s21_tan_Case = tcase_create("s21_tan_Case");
    suite_add_tcase(suite, s21_tan_Case);
    tcase_add_test(s21_tan_Case, s21_tan_Test);

    srunner_run_all(srunner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
