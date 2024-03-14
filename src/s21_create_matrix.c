#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;

  if (rows <= 0 || columns <= 0) {
    flag = ERROR_1;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));

    for (int i = 0; i < rows && flag == OK; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
      //                if (result->matrix[i] == NULL) {
      //                    for (int j = 0; j < i; j++) {
      //                        free(result->matrix[j]);
      //                    }
      //                    free(result->matrix);
      //                    result->matrix = NULL;
      //                    flag = ERROR_1;
      //                }
    }
  }

  return flag;
}
