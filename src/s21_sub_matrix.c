#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;

  if (s21_valid_struct(A) == 0 && s21_valid_struct(B) == 0 && result != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      result->rows = A->rows;
      result->columns = A->columns;
      result->matrix = (double **)malloc(result->rows * sizeof(double *));

      for (int i = 0; i < result->rows && flag == OK; i++) {
        result->matrix[i] = (double *)malloc(result->columns * sizeof(double));
        for (int j = 0; j < result->columns && flag == OK; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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
