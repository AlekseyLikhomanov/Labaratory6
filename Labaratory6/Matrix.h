#ifndef MATRIX_HPP
#define MATRIX_HPP
//проверка ввода
double matrix_size_check(double* n);

//создание матрицы
double** creation(double n, double m);

//ввод матрицы
void input(double** matr, double n, double m);

//очистка памяти
void clear(double** matr, double n);

//вывод результата
void output(double** matr, double n, double m);

//квадрат матрицы
void square(double** matr, double** result, double n);

//умножение матрицы на число и запись результата в неё
void mult_matrix_num(double** matr, double n, double m, double num);

//разница матриц
void dif_matrix_matrix(double** result, double** matr, double n, double m);

//сумма матриц
void sum_matrix_matrix(double** result, double** matr, double n, double m);

//сумма матрицы с числом и запись результата в неё
void sum_matrix_num(double** matr, double n, double num);

//f(x) = 2x^2 - x
void function_f(double** matr, double** result, double n);

//g(x) = 2x^2 - x + 3;
void function_g(double** matr, double** result, double n);

// Получение матрицы без i-й строки и j-го столбца
void get_matr(double** matr, double** p, double i, double j, double n);

// Рекурсивное вычисление определителя
int determinant(double** matr, double n);

// Функция перемножения матриц
void multiply_matrix_matrix(double** matrixA, double** matrixB, double** result, int n);

// Функция изменения значения result 
void matrix_to_result(double** matr, double** result, int n);

//функция перемножения квадратных матриц
double** sqr_matrix_multiply_matrix(double** matrixA, double** matrixB, double** result, int n);

//функция подставляет значение одной матрицы в другую
void copy_matrix(double** original, double** copy, double n);
#endif
