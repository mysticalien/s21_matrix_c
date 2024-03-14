#include <check.h>

#include "s21_matrix.h"

// s21_create_matrix
START_TEST(test_s21_create_matrix_1) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(4, 3, &A);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(-10, 0, &A);
  ck_assert_int_eq(res, ERROR_1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(-1, -1, &A);

  ck_assert_int_eq(res, ERROR_1);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(-1, 5, &A);
  ck_assert_int_eq(res, ERROR_1);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_CREATE_MATRIX=-\033[0m");
  tc_core = tcase_create("CreateMatrixCore");

  tcase_add_test(tc_core, test_s21_create_matrix_1);
  tcase_add_test(tc_core, test_s21_create_matrix_2);
  tcase_add_test(tc_core, test_s21_create_matrix_3);
  tcase_add_test(tc_core, test_s21_create_matrix_4);

  suite_add_tcase(s, tc_core);

  return s;
}
// s21_eq_matrix
START_TEST(test_s21_eq_matrix_1) {
  matrix_t A, B;
  int rows = 2;
  int columns = 2;

  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  int result = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
  matrix_t A, B;
  int rows = 2;
  int columns = 2;

  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);

  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 5.0;

  int result = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(result, FAILURE);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
  matrix_t A, B;
  int rows = 2;
  int columns = 2;

  int status_A = s21_create_matrix(rows, columns, &A);

  int rows_b = 3;
  int columns_b = 3;

  int status_B = s21_create_matrix(rows_b, columns_b, &B);

  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[0][2] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 5.0;
  B.matrix[1][2] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 5.0;
  B.matrix[2][2] = 5.0;

  int result = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(result, FAILURE);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_EQ_MATRIX=-\033[0m");
  tc_core = tcase_create("EqMatrixCore");

  tcase_add_test(tc_core, test_s21_eq_matrix_1);
  tcase_add_test(tc_core, test_s21_eq_matrix_2);
  tcase_add_test(tc_core, test_s21_eq_matrix_3);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_sum_matrix

START_TEST(test_s21_sum_matrix_1) {
  matrix_t A, B, result;
  int rows = 2;
  int columns = 2;

  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);
  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;

  int status_sum = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(status_sum, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 6.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 8.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 10.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 12.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_2) {
  matrix_t A, B, result;
  int rows_A = 2;
  int columns_A = 2;
  int rows_B = 3;
  int columns_B = 3;

  int status_A = s21_create_matrix(rows_A, columns_A, &A);
  int status_B = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  int status_sum = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(status_sum, ERROR_2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_sum_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_SUM_MATRIX=-\033[0m");
  tc_core = tcase_create("SumMatrixCore");

  tcase_add_test(tc_core, test_s21_sum_matrix_1);
  tcase_add_test(tc_core, test_s21_sum_matrix_2);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_sub_matrix
START_TEST(test_s21_sub_matrix_1) {
  matrix_t A, B, result;
  int rows = 2;
  int columns = 2;

  int status_A = s21_create_matrix(rows, columns, &A);
  int status_B = s21_create_matrix(rows, columns, &B);
  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = 6.0;
  A.matrix[1][0] = 7.0;
  A.matrix[1][1] = 8.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  int status_sub = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status_sub, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 4.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 4.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 4.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t A, B, result;
  int rows_A = 2;
  int columns_A = 2;
  int rows_B = 3;
  int columns_B = 3;

  int status_A = s21_create_matrix(rows_A, columns_A, &A);
  int status_B = s21_create_matrix(rows_B, columns_B, &B);
  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  int status_sub = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status_sub, ERROR_2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_sub_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_SUB_MATRIX=-\033[0m");
  tc_core = tcase_create("SubMatrixCore");

  tcase_add_test(tc_core, test_s21_sub_matrix_1);
  tcase_add_test(tc_core, test_s21_sub_matrix_2);

  suite_add_tcase(s, tc_core);

  return s;
}

// 21_mult_number
START_TEST(test_s21_mult_number_1) {
  matrix_t A, result;
  int rows = 2;
  int columns = 2;
  double number = 2.0;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  int status_mult = s21_mult_number(&A, number, &result);

  ck_assert_int_eq(status_mult, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 2.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 6.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 8.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_MULT_NUMBER=-\033[0m");
  tc_core = tcase_create("MultNumberCore");

  tcase_add_test(tc_core, test_s21_mult_number_1);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_mult_matrix

START_TEST(test_s21_mult_matrix_1) {
  matrix_t A, B, result;
  int rows_A = 2;
  int columns_A = 2;
  int rows_B = 2;
  int columns_B = 2;

  int status_A = s21_create_matrix(rows_A, columns_A, &A);
  int status_B = s21_create_matrix(rows_B, columns_B, &B);

  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 2.0;
  B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 2.0;

  int status_mult = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status_mult, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 4.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 4.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 10.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], 8.0, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t A, B, result;
  int rows_A = 2;
  int columns_A = 2;
  int rows_B = 3;
  int columns_B = 3;

  int status_A = s21_create_matrix(rows_A, columns_A, &A);
  int status_B = s21_create_matrix(rows_B, columns_B, &B);

  ck_assert_int_eq(status_A, OK);
  ck_assert_int_eq(status_B, OK);

  for (int i = 0; i < rows_A; i++) {
    for (int j = 0; j < columns_A; j++) {
      A.matrix[i][j] = i * columns_A + j + 1;
    }
  }

  for (int i = 0; i < rows_B; i++) {
    for (int j = 0; j < columns_B; j++) {
      B.matrix[i][j] = i * columns_B + j + 1;
    }
  }

  int status_mult = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(status_mult, ERROR_2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_MULT_MATRIX=-\033[0m");
  tc_core = tcase_create("MultMatrixCore");

  tcase_add_test(tc_core, test_s21_mult_matrix_1);
  tcase_add_test(tc_core, test_s21_mult_matrix_2);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_transpose
START_TEST(test_s21_transpose_1) {
  matrix_t A, result;
  int rows = 3;
  int columns = 2;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i * columns + j + 1;
    }
  }

  int status_transpose = s21_transpose(&A, &result);

  ck_assert_int_eq(status_transpose, OK);

  ck_assert_int_eq(result.rows, columns);
  ck_assert_int_eq(result.columns, rows);

  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], A.matrix[j][i], 1e-7);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_TRANSPOSE=-\033[0m");
  tc_core = tcase_create("TransposeCore");

  tcase_add_test(tc_core, test_s21_transpose_1);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_calc_complements
START_TEST(test_s21_calc_complements_1) {
  matrix_t A, result;
  int rows = 3;
  int columns = 3;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i * columns + j + 1;
    }
  }

  int status_complements = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status_complements, OK);

  ck_assert_int_eq(result.rows, rows);
  ck_assert_int_eq(result.columns, columns);

  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert(result.matrix[i][j] != 0.0);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t A, result;
  int rows = 2;
  int columns = 3;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i * columns + j + 1;
    }
  }

  int status_complements = s21_calc_complements(&A, &result);

  ck_assert_int_eq(status_complements, ERROR_2);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_CALC_COMPLEMENTS=-\033[0m");
  tc_core = tcase_create("CalcComplementsCore");

  tcase_add_test(tc_core, test_s21_calc_complements_1);
  tcase_add_test(tc_core, test_s21_calc_complements_2);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_determinant
START_TEST(test_s21_determinant_1) {
  matrix_t A;
  int rows = 2;
  int columns = 2;
  double determinant = 0.0;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  int status_det = s21_determinant(&A, &determinant);

  ck_assert_int_eq(status_det, OK);

  ck_assert_double_eq_tol(determinant, -2.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t A;
  int rows = 1;
  int columns = 1;
  double determinant = 0.0;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  A.matrix[0][0] = 5.0;

  int status_det = s21_determinant(&A, &determinant);

  ck_assert_int_eq(status_det, OK);

  ck_assert_double_eq_tol(determinant, 5.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t A;
  int rows = 3;
  int columns = 3;
  double determinant = 0.0;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i * columns + j + 1;
    }
  }

  int status_det = s21_determinant(&A, &determinant);

  ck_assert_int_eq(status_det, OK);

  ck_assert_double_eq_tol(determinant, 0.0, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST
Suite *s21_determinant_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_DETERMINANT=-\033[0m");
  tc_core = tcase_create("DeterminantCore");

  tcase_add_test(tc_core, test_s21_determinant_1);
  tcase_add_test(tc_core, test_s21_determinant_2);
  tcase_add_test(tc_core, test_s21_determinant_3);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_inverse_matrix

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A, result;
  int rows = 1;
  int columns = 1;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  A.matrix[0][0] = 5.0;

  int status_inv = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(status_inv, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], 0.2, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t A, result;
  int rows = 2;
  int columns = 2;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i * columns + j + 1;
    }
  }

  int status_inv = s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(status_inv, OK);

  ck_assert_double_eq_tol(result.matrix[0][0], -2.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[0][1], 1.0, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][0], 1.5, 1e-7);
  ck_assert_double_eq_tol(result.matrix[1][1], -0.5, 1e-7);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_INVERSE_MATRIX=-\033[0m");
  tc_core = tcase_create("InverseMatrixCore");

  tcase_add_test(tc_core, test_s21_inverse_matrix_1);
  tcase_add_test(tc_core, test_s21_inverse_matrix_2);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_valid_struct
START_TEST(test_s21_valid_struct_1) {
  matrix_t A;

  int status_A = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(status_A, OK);

  int result = s21_valid_struct(&A);
  ck_assert_int_eq(result, OK);

  matrix_t *B = NULL;
  result = s21_valid_struct(B);
  ck_assert_int_eq(result, ERROR_1);

  matrix_t C;
  C.rows = -1;
  C.columns = 3;
  C.matrix = NULL;
  result = s21_valid_struct(&C);
  ck_assert_int_eq(result, ERROR_1);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_valid_struct_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_VALID_STRUCT=-\033[0m");
  tc_core = tcase_create("ValidStructCore");

  tcase_add_test(tc_core, test_s21_valid_struct_1);

  suite_add_tcase(s, tc_core);

  return s;
}

// s21_minor
START_TEST(test_s21_minor_1) {
  matrix_t A, result;
  int rows = 3;
  int columns = 3;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  int status_minor = s21_minor(&A, 0, 0, &result);

  ck_assert_int_eq(status_minor, OK);

  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_minor_2) {
  matrix_t A, result;
  int rows = 1;
  int columns = 1;

  int status_A = s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(status_A, OK);

  A.matrix[0][0] = 1.0;

  int status_minor = s21_minor(&A, 0, 0, &result);

  ck_assert_int_eq(status_minor, ERROR_2);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_minor_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[30;42m-=S21_MINOR=-\033[0m");
  tc_core = tcase_create("MinorCore");

  tcase_add_test(tc_core, test_s21_minor_1);
  tcase_add_test(tc_core, test_s21_minor_2);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int failed = 0;
  Suite *matrix_tests[] = {s21_create_matrix_suite(),
                           s21_eq_matrix_suite(),
                           s21_sum_matrix_suite(),
                           s21_sub_matrix_suite(),
                           s21_mult_number_suite(),
                           s21_mult_matrix_suite(),
                           s21_transpose_suite(),
                           s21_calc_complements_suite(),
                           s21_determinant_suite(),
                           s21_inverse_matrix_suite(),
                           s21_valid_struct_suite(),
                           s21_minor_suite(),
                           NULL};

  for (int i = 0; matrix_tests[i] != NULL; i++) {
    SRunner *runner;
    runner = srunner_create(matrix_tests[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
