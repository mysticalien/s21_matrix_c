#include "s21_matrix.h"

int s21_valid_struct(matrix_t *A) {
  int flag = OK;
  if (A == NULL) {
    flag = ERROR_1;
  } else {
    if (A->matrix == NULL) {
      flag = ERROR_1;
    }
    if (A->rows < 0 || A->columns < 0) {
      flag = ERROR_1;
    }
  }
  return flag;
}
