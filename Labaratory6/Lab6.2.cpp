//��������� ��������� ������������ ������� n, �������� �������� ������ �������� Aij = max(i,j)
//��������� ����� � �������� ���������� � �������

#include <iostream>
#include "Matrix.h"
using namespace std;

// ������� A' = A + 3
double** matrix_new_A(double** matrixA, double n) {
    double** newA = creation(n, n);
    sum_matrix_num(matrixA, n, 3);
    function_f(matrixA, newA, n);//���������� f
    function_g(newA, matrixA, n);//���������� g

    return matrixA;
}

// �������� �������
int main() {
    setlocale(LC_ALL, "Rus");
    double n, det;
    cout << "������� ����������� ���������� �������: ";
    cin >> n;
    matrix_size_check(&n);
    double** matr = creation(n, n);
    cout << "������� �������:" << endl;
    input(matr, n, n);
    matr = matrix_new_A(matr, n);
    output(matr, n, n);
    det = determinant(matr, n);
    cout << "������������ ������� ����� " << det << endl;
    clear(matr, n);
    system("pause");
    return 0;
}