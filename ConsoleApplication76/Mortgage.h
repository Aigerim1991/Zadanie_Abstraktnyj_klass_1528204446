#pragma once
#include <iostream>
#include <vector>
#include  "BankLoan.h"

#define LEVEL_INFLATION 0.40	   //уровень инфляции РК (апрель 2018)
#define KOEF 0.15				   //коэффициент, учитывающий расходы банка
#define LEVEL_WEAR 0.37			   //уровень износа 
#define valuationOfFacilities 0.54 //ОЗД - оценка зданий на момент пописания договора

using namespace std;

/* Создать абстрактный класс «Залоговое имущество» */
class Mortgage
{
private:
	double amountOfMortgage;	  // сумма залогового имущества
	double marketValueOfMortgage; // рыночная стоимость залогового имущества

protected:
	/* Данные о кредитах (как агрегация динамического массива класса BankLoan)*/
	BankLoan * credit;
	vector<BankLoan> creditVectorOfBankLoan;

	float interestRateOnCredit; // процентная ставка по крадиту
	virtual void InfoOnCredit(string description, float amount, int period, float percent) = 0;
public:
	Mortgage();

	/* Методы:
	- определения минимальной величины предоставляемого кредита;
	- минимальной величины рыночной стоимости залога.           */

	virtual double MinCreditAmount() = 0;					    // минимальная величина предоставляемого кредита
	virtual double MinMarketValueOfMortgage(double amount) = 0; // минимальная величина рыночной стоимости залога

	virtual ~Mortgage();
};

//ostream &operator<<(ostream &stream, Mortgage &obj)
//{
//	stream << obj.MinCreditAmount << endl;
//}

class Facilities : public Mortgage
{
private:
	double amountOfCredit;		  // К - сумма кредита

protected:
	int totalArea;		    //общая площадь
	int usefulArea;		    //полезная площадь
	string purpose;		    //назначение
	string address;		    //адресс
	string GPS;			    //GPS координаты
	int quantityOfFloors;   //количество этажей
	int quantityOfPremises; //количество помещений

	const double INF = 10.2;				 //оценка инфляции за один период накоплений
	const double P = 0.2;					 //рисковая надбавка
	const double IZN = 0.7;					 //уровень износа зданий(сооружений)

public:
	Facilities();
	Facilities(int totalArea, int usefulArea, string purpose, string address, string GPS, int quantityOfFloors, int quantityOfPremises);

	double MinCreditAmount();
	double MinMarketValueOfMortgage(double amount);
	void PrintInfo();
	bool CreditProvide();
	bool CreditAdditioanalProvide();
	double AdditionalProvideSum();
	void InfoOnCredit(string description, float amount, int period, float percent);

	virtual ~Facilities();

};

class EarthArea : public Mortgage
{
private:
	double AreaRaiting;  //оценка земельного участка
protected:
	enum { Residential, General, Buiseness };

	int GeneralSquare;			   //общая площадь
	int UsefullSquare;			   //полезная площадь
	string Destination;			   //назначение
	string Adress;			       //адресс
	string GPS_Coordinates;		   //GPS координаты
	short int Floor;			   //количество этажей
	short int CountAccomondation;  //количество помещений
public:
	EarthArea();
	EarthArea(int GeneralSquare, int UsefullSquare, string Destination, string Adress, string GPS_Coordinate, short int Floor, short int CountAccomondation);

	double MinCreditAmount();
	double MinMarketValueOfMortgage(double sum);
	void PrintInfo();
	bool CreditProvide();
	bool CreditAdditioanalProvide();
	double AdditionalProvideSum();
	void InfoOnCredit(string description, float amount, int period, float percent);

	virtual ~EarthArea();
};


