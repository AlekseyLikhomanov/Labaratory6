#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	double n, m;
	cout << "��������� ��� ������� ������� ��������� ���������:" << endl;
	cout << "3X - 2Y = A" << endl << "2X + 3Y = B" << endl;
	cout << "������� ���������� ����� ������ n:" << endl;
	cin >> n;
	check(&n);
	cout << "������� ���������� �������� ������ m:" << endl;
	cin >> m;
	check(&m);
	cout << "������� ������� �:" << endl;
	double** A = creation(n, m);
	input(A, n, m);
	cout << "������� ������� B:" << endl;
	double** B = creation(n, m);
	input(B, n, m);
	system_solution(A, B, n, m);
	clear(A, n);
	clear(B, n);
	system("pause");
	return 0;
}
//2, 2, ��� 1;