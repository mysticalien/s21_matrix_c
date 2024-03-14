#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (A != NULL && B != NULL && result != NULL) {
    if (A->columns == B->rows) {
      result->rows = A->rows;
      result->columns = B->columns;
      result->matrix = (double **)malloc(result->rows * sizeof(double *));

      for (int i = 0; i < result->rows && flag == OK; i++) {
        result->matrix[i] = (double *)malloc(result->columns * sizeof(double));
        for (int j = 0; j < B->columns && flag == OK; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      flag = ERROR_2;
    }
  } else {
    flag = ERROR_1;
  }
  return flag;
}
