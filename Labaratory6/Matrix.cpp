#include <iostream>
using namespace std;
double check(double* n) {
	while (cin.fail() || *n < 1) {
		cout << endl << "������ �����. ��������� ��� ���." << endl;
		cin >> *n;
	}
	return *n;
}
double** creation(double n, double m) {
	double** matr = new double* [n];
	for (int i = 0; i < n; i++)
		matr[i] = new double[m];
	return matr;
}
void input(double** matr, double n, double m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> matr[i][j];
		}
}
void clear(double** matr, double n) {
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
	matr = 0;
}
void output(double** matr, double n, double m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << matr[i][j] << ' ';
		cout << endl;
	}
}
void square(double** matr, double** result, double n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int s = 0;//���������� ��������
			for (int q = 0; q < n; q++)
				s += matr[i][q] * matr[q][j];//������� �������
			result[i][j] = s;
		}
}
void mult_matrix_num(double** matr, double n, double m, double num) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] *= num;
}
void dif_matrix_matrix(double** result, double** matr, double n, double m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result[i][j] -= matr[i][j];
}
void sum_matrix_matrix(double** result, double** matr, double n, double m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result[i][j] += matr[i][j];
}
void sum_matrix_num(double** matr, double n, double num) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matr[i][j] += num;
}
void function_f(double** matr, double** result, double n) {
	square(matr, result, n);
	mult_matrix_num(result, n, n, 2);
	dif_matrix_matrix(result, matr, n, n);
}
void function_g(double** matr, double** result, double n) {
	square(matr, result, n);
	mult_matrix_num(result, n, n, 2);
	dif_matrix_matrix(result, matr, n, n);
	sum_matrix_num(result, n, 3);
}
// ��������� ������� ��� i-� ������ � j-�� �������
void get_matr(double** matr, double** p, double i, double j, double n) {
	int di = 0, dj;
	for (int ki = 0; ki < n - 1; ki++) { // �������� ������� ������
		if (ki == i) di = 1;
		dj = 0;
		for (int kj = 0; kj < n - 1; kj++) { // �������� ������� �������
			if (kj == j) dj = 1;
			p[ki][kj] = matr[ki + di][kj + dj];
		}
	}
}
// ����������� ���������� ������������
double determinant(double** matr, double n) {
	double det = 0, sign = 1, m;
	m = n - 1;
	if (n < 1) {
		cout << "������������ ��������� ����������!";
		return 0;
	}
	if (n == 1) {
		det = matr[0][0];
		return det;
	}
	if (n == 2) {
		det = matr[0][0] * matr[1][1] - (matr[1][0] * matr[0][1]);
		return det;
	}
	double** p = creation(n, n);
	if (n > 2) {
		for (int i = 0; i < n; i++) {
			get_matr(matr, p, i, 0, n);
			det = det + sign * matr[i][0] * determinant(p, m);
			sign = -sign;
		}
	}
	clear(p, n);
	return det;
}
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