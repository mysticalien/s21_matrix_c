#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (s21_valid_struct(A) == 0 && A->rows > 0 && A->columns > 0) {
    result->rows = A->columns;
    result->columns = A->rows;
    result->matrix = (double **)malloc(result->rows * sizeof(double *));

    for (int i = 0; i < result->rows; i++) {
      result->matrix[i] = (double *)malloc(result->columns * sizeof(double));
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  } else {
    flag = ERROR_1;
  }

  return flag;
}
