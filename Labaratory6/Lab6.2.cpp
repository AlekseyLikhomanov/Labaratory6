//Программа вычисляет определитель порядка n, элементы которого заданы условием Aij = max(i,j)
//Нумерация строк и столбцов начинается с единицы

#include <iostream>
#include "Matrix.h"
using namespace std;

// Матрица A' = A + 3
double** matrix_new_A(double** matrixA, double n) {
    double** newA = creation(n, n);
    sum_matrix_num(matrixA, n, 3);
    function_f(matrixA, newA, n);//вычисление f
    function_g(newA, matrixA, n);//вычисление g

    return matrixA;
}

// Основная функция
int main() {
    setlocale(LC_ALL, "Rus");
    double n, det;
    cout << "Введите размерность квадратной матрицы: ";
    cin >> n;
    matrix_size_check(&n);
    double** matr = creation(n, n);
    cout << "Введите матрицу:" << endl;
    input(matr, n, n);
    matr = matrix_new_A(matr, n);
    output(matr, n, n);
    det = determinant(matr, n);
    cout << "Определитель матрицы равен " << det << endl;
    clear(matr, n);
    system("pause");
    return 0;
}