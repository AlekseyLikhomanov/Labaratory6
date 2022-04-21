#include <iostream>
#include "Matrix.h"
using namespace std;

//Функция решения системы 
void system_solution(double** A, double** B, double n, double m) {
	cout << "Умножаем второе уравнение на 1.5 и вычитаем из него первое:" << endl;
	cout << "6.5Y = 1.5B - A" << endl;
	cout << "Из этого уравнения находим Y" << endl;
	mult_matrix_num(B, n, m, 1.5);
	dif_matrix_matrix(B, A, n, m);
	mult_matrix_num(B, n, m, 1 / 6.5);
	cout << "Матрица Y равна:" << endl;
	output(B, n, m);
	cout << "Подставляем Y в первое уравнение и находим X" << endl;
	cout << "3X = A + 2Y" << endl;
	mult_matrix_num(B, n, m, 2);
	sum_matrix_matrix(B, A, n, m);
	mult_matrix_num(B, n, m, 1 / 3.0);
	cout << "Матрица X равна:" << endl;
	output(B, n, m);
}

// Матрица A' = A + 3
double** matrix_new_A(double** matrixA, double n) {
	double** newA = creation(n, n);
	sum_matrix_num(matrixA, n, 3);
	function_f(matrixA, newA, n);//вычисление f
	function_g(newA, matrixA, n);//вычисление g

	return newA;
}

// Матрица B' = B * A
double** matrix_new_B(double** matrixA, double** matrixB, double n) {
	double** newB = creation(n, n);
	double** tmpB = creation(n, n);
	tmpB = sqr_matrix_multiply_matrix(matrixA, matrixB, tmpB, n);
	function_f(tmpB, newB, n);//вычисление f
	function_g(newB, tmpB, n);//вычисление g

	return newB;
}

int main() {
	setlocale(LC_ALL, "Rus");
	double n, m;
	cout << "Программа для решения системы матричных уравнений:" << endl;
	cout << "3X - 2Y = A" << endl << "2X + 3Y = B" << endl;
	cout << "Введите количество строк матриц n:" << endl;
	cin >> n;
	matrix_size_check(&n);
	cout << "Введите количество столбцов матриц m:" << endl;
	cin >> m;
	matrix_size_check(&m);
	cout << "Введите матрицу А:" << endl;
	double** A = creation(n, m);
	input(A, n, m);
	double** resultA = creation(n, m);
	resultA = matrix_new_A(A, n);
	cout << "Введите матрицу B:" << endl;
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
//2, 2, все 1;