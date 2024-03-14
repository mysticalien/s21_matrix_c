#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = s21_valid_struct(A);
  if (flag == OK) {
    if (A->rows != A->columns || A->rows <= 1) {
      flag = ERROR_2;
    } else {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor;
          double det = 0.0;
          s21_minor(A, i, j, &minor);
          s21_determinant(&minor, &det);
          result->matrix[i][j] = ((i + j) % 2 == 0) ? det : -det;
          s21_remove_matrix(&minor);
        }
      }
    }

  } else {
    flag = ERROR_1;
  }
  return flag;
}
