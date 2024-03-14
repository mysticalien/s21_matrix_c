#ifndef TEST_S21_MATRIX_H
#define TEST_S21_MATRIX_H

#include <check.h>
#include <time.h>
#include <unistd.h>

#include "s21_matrix.h"

Suite *s21_create_matrix_suite(void);
Suite *s21_remove_matrix(void);
Suite *s21_eq_matrix(void);
Suite *s21_sum_matrix(void);
Suite *s21_sub_matrix(void);
Suite *s21_mult_number(void);
Suite *s21_mult_matrix(void);
Suite *s21_transpose(void);
Suite *s21_calc_complements(void);
Suite *s21_determinant(void);
Suite *s21_inverse_matrix(void);
Suite *s21_valid_struct(void);
Suite *s21_minor(void);

#endif
