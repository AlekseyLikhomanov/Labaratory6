#include <iostream>
#include <iomanip>
using namespace std;

//Функция проверяет корректность ввода значения размерности матрицы
double matrix_size_check(double* n) {
	while (cin.fail() || *n < 1) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << endl << "Ошибка ввода. Повторите ещё раз." << endl;
		cin >> *n;
	}
	return *n;
}

//Функция проверяет корректность ввода значений матрицы
double matrix_nums_check(double* n) {
	while (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << endl << "Ошибка ввода. Повторите ещё раз." << endl;
		cin >> *n;
	}
	return *n;
}

double** creation(double n, double m) {
	double** matr = new double* [n];

	for (int i = 0; i < n; i++) 
		matr[i] = new double[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matr[i][j] = 0;

	return matr;
}
void input(double** matr, double n, double m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> matr[i][j];
			matrix_nums_check(&matr[i][j]);
		}
}
void clear(double** matr, double n) {
	if (matr == 0)
		return;
	for (int i = 0; i < n; i++)
		delete[] matr[i];
	delete[] matr;
	matr = 0;
}
void output(double** matr, double n, double m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << setprecision(15) << matr[i][j] << ' ';
		cout << endl;
	}
}
void square(double** matr, double** result, double n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int s = 0;//вычисление элемента
			for (int q = 0; q < n; q++)
				s += matr[i][q] * matr[q][j];//квадрат матрицы
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
			if (i == j)
				matr[i][j] += num;

}

// Функция изменения значения result 
void matrix_to_result(double** matr, double** result, int n) {
	for (int i = 0; i < n; i++) //делаем matrix равной result
		for (int j = 0; j < n; j++)
			matr[i][j] = result[i][j];
}

void function_f(double** matr, double** result, double n) {
	square(matr, result, n);
	mult_matrix_num(result, n, n, 2);
	dif_matrix_matrix(result, matr, n, n);
	matrix_to_result(matr, result, n); //делаем matrix равной result
}

void function_g(double** matr, double** result, double n) {
	square(matr, result, n);
	mult_matrix_num(result, n, n, 2);
	dif_matrix_matrix(result, matr, n, n);
	sum_matrix_num(result, n, 3);
	matrix_to_result(matr, result, n); //делаем matrix равной result
}

// Получение матрицы без i-й строки и j-го столбца
void get_matr(double** matr, double** p, double i, double j, double n) {
	int di = 0, dj;
	for (int ki = 0; ki < n - 1; ki++) { // проверка индекса строки
		if (ki == i) di = 1;
		dj = 0;
		for (int kj = 0; kj < n - 1; kj++) { // проверка индекса столбца
			if (kj == j) dj = 1;
			p[ki][kj] = matr[ki + di][kj + dj];
		}
	}
}

// Рекурсивное вычисление определителя
int	 determinant(double** matr, double n) {
	long long det = 0, sign = 1, m;
	m = n - 1;
	if (n < 1) {
		cout << "Определитель вычислить невозможно!";
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

//функция перемножения матриц
void multiply_matrix_matrix(double** matrixA, double** matrixB, double** result, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
				result[i][j] += matrixA[i][j] * matrixB[i][j];
}

//функция перемножения квадратных матриц
double** sqr_matrix_multiply_matrix(double** matrixA, double** matrixB, double** result, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				result[i][j] += matrixA[i][k] * matrixB[k][j];
	return result;
}

//функция подставляет значение одной матрицы в другую
void copy_matrix(double** original, double** copy, double n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			copy[i][j] = original[i][j];
}

