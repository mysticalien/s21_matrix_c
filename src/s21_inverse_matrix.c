#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = s21_valid_struct(A);
  if (flag == OK) {
    double det = 0.0;
    flag = s21_determinant(A, &det);
    if (det == 0.0 && flag == OK) {
      flag = ERROR_2;
    } else if (det == 0.0) {
      flag = ERROR_1;
    } else if (A->rows == A->columns && A->rows == 1 && flag == OK) {
      s21_create_matrix(A->rows, A->columns, result);
      result->matrix[0][0] = 1.0 / det;
    } else if (A->rows == A->columns && flag == OK) {
      s21_create_matrix(A->rows, A->columns, result);
      matrix_t minor, transpose;
      s21_calc_complements(A, &minor);
      s21_transpose(&minor, &transpose);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = transpose.matrix[i][j] / det;
        }
      }

      s21_remove_matrix(&minor);
      s21_remove_matrix(&transpose);
    }
  }
  return flag;
}
