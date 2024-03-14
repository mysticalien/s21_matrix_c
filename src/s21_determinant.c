#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  *result = 0.0;
  int flag = s21_valid_struct(A);
  if (flag == OK) {
    if (A->rows == 1 && A->columns == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == A->columns) {
      if (A->rows == 2) {
        *result = (A->matrix[0][0] * A->matrix[1][1] -
                   A->matrix[1][0] * A->matrix[0][1]);
      } else {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor;
          double det = 0.0;
          s21_minor(A, 0, j, &minor);
          s21_determinant(&minor, &det);
          if (j % 2 == 0) {
            *result += det * A->matrix[0][j];
          } else {
            *result -= det * A->matrix[0][j];
          }
          s21_remove_matrix(&minor);
        }
      }
    } else {
      flag = ERROR_2;
    }
  }
  return flag;
}