// ConsoleApplication76.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <clocale>
#include <ctime>
#include <list>
#include "Mortgage.h"
using namespace std;
/*
������� ����������� ����� ���������� ���������, �������� ������ �:
- ����� ���������� ���������,
- �������� ��������� ���������� ���������
- �������� (��� ��������� ������������� ������� ������ BankLoan).
������:
- ����������� ����������� �������� ���������������� �������;
- ����������� �������� �������� ��������� ������.
��������� ����� ������ ���������� �� ���� �������������.
�� ��������� ������������ ������ ������� ��� �������� ������ ��� ����� ��������� ��������, ������ � ����������.
��������� ������� ������ ��������� ������ � �������, ���������� (1), ����� ��������������, GPS ����������.
������ � ���������� ������ ���������, ����� � �������� �������, ����������, ���������, ���������� ���������,
����� ����� ���������.
�������� ��� ��������� ������ ������� ������ ���������� ���������, ������������� ���, ��������� ���������� ��
����������� �� ������� (2), ����� �� ������ ��� ������������ ����������� �������������� ������, ���������� ��
����������� ��� ������������ �������� �������, ���������� ����� ��������������� �����������.
(1)	http://egov.kz/cms/ru/law/list/V08R000799_
(2)	https://cyberleninka.ru/article/v/opredelenie-zalogovoy-stoimosti-zemelnogo-uchastka-i-summy-neobhodimogo-kredita
*/


int main()
{
	setlocale(LC_ALL, "rus");

	list<Mortgage*> add;
	list<Mortgage*>::iterator Iter;
	add.push_back(new EarthArea(250000, 245000, "Production factory of oil", "Tirupati, Andhra Pradesh", "13.644460, 79.520892", 14, 548));
	add.push_back(new Facilities(250000, 245000, "Production factory of oil", "Tirupati, Andhra Pradesh", "13.644460, 79.520892", 14, 548));

	EarthArea a(250000, 245000, "Production factory of oil", "Tirupati, Andhra Pradesh", "13.644460, 79.520892", 14, 548);
	a.PrintInfo();
	Facilities b(250000, 245000, "Production factory of oil", "Tirupati, Andhra Pradesh", "13.644460, 79.520892", 14, 548);
	b.PrintInfo();
	BankLoan Obj("������������� ������ ����", 1000000, 10, 15.1);

	cout << endl;

	Obj.getLoanRepaymentSchedule(Obj);

	return 0;
}
