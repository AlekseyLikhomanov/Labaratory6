#include <iostream>
#include "Matrix.h"
using namespace std;

//������� ������� ������� 
void system_solution(double** A, double** B, double n, double m) {
	cout << "�������� ������ ��������� �� 1.5 � �������� �� ���� ������:" << endl;
	cout << "6.5Y = 1.5B - A" << endl;
	cout << "�� ����� ��������� ������� Y" << endl;
	mult_matrix_num(B, n, m, 1.5);
	dif_matrix_matrix(B, A, n, m);
	mult_matrix_num(B, n, m, 1 / 6.5);
	cout << "������� Y �����:" << endl;
	output(B, n, m);
	cout << "����������� Y � ������ ��������� � ������� X" << endl;
	cout << "3X = A + 2Y" << endl;
	mult_matrix_num(B, n, m, 2);
	sum_matrix_matrix(B, A, n, m);
	mult_matrix_num(B, n, m, 1 / 3.0);
	cout << "������� X �����:" << endl;
	output(B, n, m);
}

// ������� A' = A + 3
double** matrix_new_A(double** matrixA, double n) {
	double** newA = creation(n, n);
	sum_matrix_num(matrixA, n, 3);
	function_f(matrixA, newA, n);//���������� f
	function_g(newA, matrixA, n);//���������� g

	return newA;
}

// ������� B' = B * A
double** matrix_new_B(double** matrixA, double** matrixB, double n) {
	double** newB = creation(n, n);
	double** tmpB = creation(n, n);
	tmpB = sqr_matrix_multiply_matrix(matrixA, matrixB, tmpB, n);
	function_f(tmpB, newB, n);//���������� f
	function_g(newB, tmpB, n);//���������� g

	return newB;
}

int main() {
	setlocale(LC_ALL, "Rus");
	double n, m;
	cout << "��������� ��� ������� ������� ��������� ���������:" << endl;
	cout << "3X - 2Y = A" << endl << "2X + 3Y = B" << endl;
	cout << "������� ���������� ����� ������ n:" << endl;
	cin >> n;
	matrix_size_check(&n);
	cout << "������� ���������� �������� ������ m:" << endl;
	cin >> m;
	matrix_size_check(&m);
	cout << "������� ������� �:" << endl;
	double** A = creation(n, m);
	input(A, n, m);
	double** resultA = creation(n, m);
	resultA = matrix_new_A(A, n);
	cout << "������� ������� B:" << endl;
	double** B = creation(n, m);
	input(B, n, m);
	double** resultB = creation(n, m);
	resultB = matrix_new_B(A, B, n);
	system_solution(A, B, n, m);
	clear(A, n);
	clear(resultA, n);
	clear(B, n);
	clear(resultB, n);

	system("pause");
	return 0;
}
//2, 2, ��� 1;