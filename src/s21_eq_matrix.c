#include "s21_matrix.h"

int compare_double(double a, double b, double epsilon) {
  return fabs(a - b) < epsilon;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  double epsilon = 1e-7;
  int flag = SUCCESS;

  if (s21_valid_struct(A) == 0 && s21_valid_struct(B) == 0) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows && flag == SUCCESS; i++) {
        for (int j = 0; j < A->columns && flag == SUCCESS; j++) {
          if (!compare_double(A->matrix[i][j], B->matrix[i][j], epsilon)) {
            flag = FAILURE;
          }
        }
      }
    } else {
      flag = FAILURE;
    }
  } else {
    flag = FAILURE;
  }

  return flag;
}
