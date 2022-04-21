//На вход программе подается две матрицы: A и B. 
//На выход программа выдает два значения: A' и B'.
//Результат программы получается путем решения выражения: f(x) = 2x^2 - x; g(x) = 2x^2 - x + 3; g(f(A)) = A
//f(A+3) = A'; f(A*B) = B'.

#include <iostream>
#include "Matrix.h"
using namespace std;

// Матрица A' = A + 3. 
// Функция возвращает ссылку на указатель
double** matrix_new_A(double** matrixA, double n) {
	double** newA = creation(n, n);
	//std::cout << newA << "1" << std::endl;
	//std::cout << matrixA << std::endl;

	sum_matrix_num(matrixA, n, 3);
	//std::cout << matrixA << std::endl;
	function_f(matrixA, newA, n);//вычисление f
	//std::cout << matrixA << std::endl;

	function_g(newA, matrixA, n);//вычисление g
	//std::cout << matrixA << std::endl;

	return newA;
}

// Матрица B' = B * A
double** matrix_new_B(double** matrixA, double** matrixB, double n) {
	double** newB = creation(n, n);
	std::cout << matrixA << " 1" << std::endl;
	std::cout << matrixB << std::endl;
	double** tmpB = creation(n, n);
	tmpB = sqr_matrix_multiply_matrix(matrixA, matrixB, tmpB, n);
	std::cout << matrixA << " 1" << std::endl;
	std::cout << matrixB << std::endl;
	function_f(tmpB, newB, n);//вычисление f
	std::cout << matrixA << " 1" << std::endl;
	std::cout << matrixB << std::endl;
	function_g(newB, tmpB, n);//вычисление g
	std::cout << matrixA << " 1" << std::endl;
	std::cout << matrixB << std::endl;

	clear(tmpB, n);
	return newB;
}

int main() {
	setlocale(LC_ALL, "Rus");
	double n; //размерность квадратной матрицы 
	cout << "f(x) = 2x^2 - x; g(x) = 2x^2 - x + 3; g(f(A))" << endl;

	cout << "Введите размерность матрицы:" << endl;
	cin >> n;
	matrix_size_check(&n);

	cout << endl << "Введите матрицу A:" << endl;
	double** matrixA = creation(n, n); //создание матрицы А.
	input(matrixA, n, n);
	double** saveA = creation(n, n);
	copy_matrix(matrixA, saveA, n);

	//std::cout << resultA << "  res" << std::endl;
	//std::cout << matrixA << "  in" << std::endl;

	double** resultA = matrix_new_A(matrixA, n); //создание матрицы, сохраняющей изменения матрицы А в ходе решения
	//std::cout << resultA << std::endl;

	cout << endl << "Введите матрицу B:" << endl;
	double** matrixB = creation(n, n); //создание матрицы B.
	input(matrixB, n, n);

	double** resultB = matrix_new_B(saveA, matrixB, n); //создание матрицы, сохраняющей изменения матрицы B в ходе решения
	std::cout << resultB << std::endl;

	cout << "Результаты вычислений:" << endl;
	cout << "Матрица A' = A + 3:" << endl;
	output(resultA, n, n);//вывод результата
	cout << "Матрица B' = A * B:" << endl;
	output(resultB, n, n);//вывод результата

	//очистка памяти
	std::cout << matrixB << std::endl;

	clear(matrixA, n);
	std::cout << resultB << std::endl;
	clear(resultA, n);
	clear(saveA, n);
	clear(matrixB, n);
	clear(resultB, n);

	system("pause");

	return 0;
}