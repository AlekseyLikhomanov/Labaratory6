#include <iostream>
#include "Matrix.h"
using namespace std;

// Основная функция
int main() {
    setlocale(LC_ALL, "Rus");
    double n, det;
    cout << "Введите размерность квадратной матрицы: ";
    cin >> n;
    double** matr = creation(n, n);
    input(matr, n, n);
    det = determinant(matr, n);
    cout << "Определитель матрицы равен " << det;
    clear(matr, n);
    system("pause");
    return 0;
}