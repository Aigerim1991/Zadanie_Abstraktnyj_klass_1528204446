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
Создать абстрактный класс «Залоговое имущество», хранящий данные о:
- сумме залогового имущества,
- рыночной стоимости залогового имущества
- кредитах (как агрегация динамического массива класса BankLoan).
Методы:
- определения минимальной величины предоставляемого кредита;
- минимальной величины рыночной стоимости залога.
Остальные члены класса определять по мере необходимости.
На основании абстрактного класса создать два дочерних класса для учета земельных участков, зданий и сооружений.
Земельный участок должен содержать данные о площади, назначении (1), адрес местоположения, GPS координаты.
Здание и сооружение должен содержать, общую и полезную площадь, назначение, этажность, количество помещений,
адрес места положения.
Основной код программы должен хранить список залогового имущества, распечатывать его, проверять достаточно ли
обеспечения по кредиту (2), можно ли выдать под существующее обеспечение дополнительный кредит, достаточно ли
обеспечения для обслуживания текущего кредита, рассчитать сумму дополнительного обеспечения.
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
	BankLoan Obj("Строительство жилого дома", 1000000, 10, 15.1);

	cout << endl;

	Obj.getLoanRepaymentSchedule(Obj);

	return 0;
}
