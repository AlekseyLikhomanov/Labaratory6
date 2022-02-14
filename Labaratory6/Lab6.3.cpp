#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	double n, m;
	cout << "Программа для решения системы матричных уравнений:" << endl;
	cout << "3X - 2Y = A" << endl << "2X + 3Y = B" << endl;
	cout << "Введите количество строк матриц n:" << endl;
	cin >> n;
	check(&n);
	cout << "Введите количество столбцов матриц m:" << endl;
	cin >> m;
	check(&m);
	cout << "Введите матрицу А:" << endl;
	double** A = creation(n, m);
	input(A, n, m);
	cout << "Введите матрицу B:" << endl;
	double** B = creation(n, m);
	input(B, n, m);
	system_solution(A, B, n, m);
	clear(A, n);
	clear(B, n);
	system("pause");
	return 0;
}
//2, 2, все 1;