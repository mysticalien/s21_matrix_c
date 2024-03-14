#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
      }
      free(A->matrix);
    }
    A->rows = 0;
    A->columns = 0;
  }
}