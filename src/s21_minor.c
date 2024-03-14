#include "s21_matrix.h"

int s21_minor(matrix_t *A, int rows, int columns, matrix_t *result) {
  int flag = s21_valid_struct(A);
  if (A->columns >= 2 && A->rows >= 2 && flag == OK) {
    s21_create_matrix(A->rows - 1, A->columns - 1, result);
    for (int i = 0, res_i = 0; i < A->rows; i++) {
      if (rows == i) {
        continue;
      }
      for (int j = 0, res_j = 0; j < A->columns; j++) {
        if (columns == j) {
          continue;
        }
        result->matrix[res_i][res_j] = A->matrix[i][j];
        res_j++;
      }
      res_i++;
    }
  } else if (flag == OK) {
    flag = ERROR_2;
  }
  return flag;
}