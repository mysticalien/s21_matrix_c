#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

#define OK 0       // OK
#define ERROR_1 1  // Error, incorrect matrix
#define ERROR_2 2  // Error calculation

// 0 - OK
// 1 - Ошибка,
// некорректная матрица
// 2 -Ошибка вычисления(несовпадающие размеры матриц;
// матрица, для которой нельзя провести вычисления и
//

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result);

// Очистка матриц
void s21_remove_matrix(matrix_t *A);

// Сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// Сложение матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Вычитание матриц
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Умножение матрицы на число
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// Умножение двух матриц
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// Транспонирование матриц
int s21_transpose(matrix_t *A, matrix_t *result);

// Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);

// Определитель матрицы
int s21_determinant(matrix_t *A, double *result);

// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_valid_struct(matrix_t *A);

int s21_minor(matrix_t *A, int rows, int columns, matrix_t *result);
