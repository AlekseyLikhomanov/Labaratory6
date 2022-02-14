//f(x) = 2x^2 - x; g(x) = 2x^2 - x + 3; g(f(A))
#include <iostream>
#include "Matrix.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	double n;//�����������
	cout << "f(x) = 2x^2 - x; g(x) = 2x^2 - x + 3; g(f(A))" << endl;
	cout << "������� ����������� �������:" << endl;
	cin >> n;
	check(&n);
	cout << endl << "������� �������:" << endl;
	double** matrix = creation(n, n);
	input(matrix, n, n);
	double** result = creation(n, n);
	function_f(matrix, result, n);//���������� f
	for (int i = 0; i < n; i++) //������ matrix ������ result
		for (int j = 0; j < n; j++)
			matrix[i][j] = result[i][j];
	function_g(matrix, result, n);//���������� g
	cout << "��������� ����������:" << endl;
	output(result, n, n);//����� ����������
	clear(matrix, n);//������� �������
	clear(result, n);
	system("pause");
	return 0;
}
//�����: 3, ��� 1