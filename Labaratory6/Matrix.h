#ifndef MATRIX_HPP
#define MATRIX_HPP
//???????? ?????
double matrix_size_check(double* n);

//???????? ???????
double** creation(double n, double m);

//???? ???????
void input(double** matr, double n, double m);

//??????? ??????
void clear(double** matr, double n);

//????? ??????????
void output(double** matr, double n, double m);

//??????? ???????
void square(double** matr, double** result, double n);

//????????? ??????? ?? ????? ? ?????? ?????????? ? ???
void mult_matrix_num(double** matr, double n, double m, double num);

//??????? ??????
void dif_matrix_matrix(double** result, double** matr, double n, double m);

//????? ??????
void sum_matrix_matrix(double** result, double** matr, double n, double m);

//????? ??????? ? ?????? ? ?????? ?????????? ? ???
void sum_matrix_num(double** matr, double n, double num);

//f(x) = 2x^2 - x
void function_f(double** matr, double** result, double n);

//g(x) = 2x^2 - x + 3;
void function_g(double** matr, double** result, double n);

// ????????? ??????? ??? i-? ?????? ? j-?? ???????
void get_matr(double** matr, double** p, double i, double j, double n);

// ??????????? ?????????? ????????????
int determinant(double** matr, double n);

// ??????? ???????????? ??????
void multiply_matrix_matrix(double** matrixA, double** matrixB, double** result, int n);

// ??????? ????????? ???????? result 
void matrix_to_result(double** matr, double** result, int n);

//??????? ???????????? ?????????? ??????
double** sqr_matrix_multiply_matrix(double** matrixA, double** matrixB, double** result, int n);

//??????? ??????????? ???????? ????? ??????? ? ??????
void copy_matrix(double** original, double** copy, double n);
#endif
