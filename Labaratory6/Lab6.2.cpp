#include <iostream>
#include "Matrix.h"
using namespace std;

// �������� �������
int main() {
    setlocale(LC_ALL, "Rus");
    double n, det;
    cout << "������� ����������� ���������� �������: ";
    cin >> n;
    double** matr = creation(n, n);
    input(matr, n, n);
    det = determinant(matr, n);
    cout << "������������ ������� ����� " << det;
    clear(matr, n);
    system("pause");
    return 0;
}