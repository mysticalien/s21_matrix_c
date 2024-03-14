#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A != NULL && A->matrix != NULL && result != NULL) {
    result->rows = A->rows;
    result->columns = A->columns;

    result->matrix = (double **)malloc(result->rows * sizeof(double *));

    for (int i = 0; i < result->rows; i++) {
      result->matrix[i] = (double *)malloc(result->columns * sizeof(double));

      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
    return OK;
  } else {
    return ERROR_1;
  }
}
