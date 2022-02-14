//f(x) = 2x^2 - x; g(x) = 2x^2 - x + 3; g(f(A))
#include <iostream>
#include "Matrix.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	double n;//размерность
	cout << "f(x) = 2x^2 - x; g(x) = 2x^2 - x + 3; g(f(A))" << endl;
	cout << "Введите размерность матрицы:" << endl;
	cin >> n;
	check(&n);
	cout << endl << "Введите матрицу:" << endl;
	double** matrix = creation(n, n);
	input(matrix, n, n);
	double** result = creation(n, n);
	function_f(matrix, result, n);//вычисление f
	for (int i = 0; i < n; i++) //делаем matrix равной result
		for (int j = 0; j < n; j++)
			matrix[i][j] = result[i][j];
	function_g(matrix, result, n);//вычисление g
	cout << "Результат вычислений:" << endl;
	output(result, n, n);//вывод результата
	clear(matrix, n);//очистка матрицы
	clear(result, n);
	system("pause");
	return 0;
}
//Тесты: 3, все 1