#include "stdafx.h"
#include "Mortgage.h"


void Mortgage::InfoOnCredit(string description, float amount, int period, float percent)
{
	BankLoan infoOnCredit(description, amount, period, percent);

	creditVectorOfBankLoan.push_back(infoOnCredit);
}

Mortgage::Mortgage()
{
	BankLoan temp;
	interestRateOnCredit = temp.getPercent();
}


Mortgage::~Mortgage()
{
}

Facilities::Facilities()
{
	amountOfCredit = 0;		 // К - сумма кредита
	totalArea = 0;			 //общая площадь
	usefulArea = 0;		     //полезная площадь
	quantityOfFloors = 0;      //количество этажей
	quantityOfPremises = 0;    //количество помещений

}

Facilities::Facilities(int totalArea, int usefulArea, string purpose, string address, string GPS, int quantityOfFloors, int quantityOfPremises)
{
	this->totalArea = totalArea;
	this->usefulArea = usefulArea;
	this->purpose = purpose;
	this->address = address;
	this->GPS = GPS;
	this->quantityOfFloors = quantityOfFloors;
	this->quantityOfPremises = quantityOfPremises;
}

double Facilities::MinCreditAmount()
{
	return (valuationOfFacilities*(1 + ((INF - IZN) / 100))) / (1 + (interestRateOnCredit / 100)*P);
}

double Facilities::MinMarketValueOfMortgage(double amount)
{
	return (amount * ((1 + (interestRateOnCredit / 100))*P) / (1 * (INF - IZN) / 100));
}

void Facilities::PrintInfo()
{
	cout << endl << "==============================" << endl;
	cout << "Сооружение: " << endl;
	cout << endl << "Общая площадь: " << totalArea << endl;
	cout << "Полезная площадь: " << usefulArea << endl;
	cout << "Назначение: " << purpose << endl;
	cout << "Адрес: " << address << endl;
	cout << "GPS координаты: " << GPS << endl;
	cout << "Количество этажей: " << quantityOfFloors << endl;
	cout << "Количество помещений: " << quantityOfPremises << endl;
	cout << endl << "==============================" << endl;
}

bool Facilities::CreditProvide()
{
	float CreditAmount = NULL;

	for (size_t i = 0; i < creditVectorOfBankLoan.size(); i++)
		CreditAmount += creditVectorOfBankLoan[i].getAmount();

	if (MinMarketValueOfMortgage(CreditAmount) < valuationOfFacilities)
		return false;
	else
		return true;
}

bool Facilities::CreditAdditioanalProvide()
{
	float CreditAmount = NULL;

	for (size_t i = 0; i < creditVectorOfBankLoan.size(); i++)
		CreditAmount += creditVectorOfBankLoan[i].getAmount();

	if (MinMarketValueOfMortgage(CreditAmount) > valuationOfFacilities)
		return false;
	else
		return true;
}

double Facilities::AdditionalProvideSum()
{
	float CreditAmount = NULL;

	for (size_t i = 0; i < creditVectorOfBankLoan.size(); i++)
		CreditAmount += creditVectorOfBankLoan[i].getAmount();

	if (MinMarketValueOfMortgage(CreditAmount) > valuationOfFacilities)
		return MinMarketValueOfMortgage(CreditAmount) - valuationOfFacilities;

}

void Facilities::InfoOnCredit(string description, float amount, int period, float percent)
{
	BankLoan infoOnCredit(description, amount, period, percent);

	creditVectorOfBankLoan.push_back(infoOnCredit);

}

Facilities::~Facilities()
{
}

EarthArea::EarthArea()
{
	AreaRaiting = 0;
	GeneralSquare = 0;
	UsefullSquare = 0;
	Floor = 0;
	CountAccomondation = 0;
}

EarthArea::EarthArea(int GeneralSquare, int UsefullSquare, string Destination, string Adress, string GPS_Coordinate, short int Floor, short int CountAccomondation)
{
	this->GeneralSquare = GeneralSquare;
	this->UsefullSquare = UsefullSquare;
	this->Destination = Destination;
	this->Adress = Adress;
	this->GPS_Coordinates = GPS_Coordinates;
	this->Floor = Floor;
	this->CountAccomondation = CountAccomondation;
}

double EarthArea::MinCreditAmount()
{
	return (AreaRaiting * (1 + LEVEL_INFLATION / 100)) / (1 + (interestRateOnCredit / 100) * KOEF);
}

double EarthArea::MinMarketValueOfMortgage(double sum)
{
	return (1 + (interestRateOnCredit / 100) * KOEF) / (valuationOfFacilities * (1 + ((LEVEL_INFLATION - LEVEL_WEAR) / 100)));
}

void EarthArea::PrintInfo()
{
	cout << endl << "==============================" << endl;
	cout << "Земельный участок: " << endl;
	cout << endl << "Общая площадь: " << GeneralSquare << endl;
	cout << "Полезная площадь: " << UsefullSquare << endl;
	cout << "Назначение: " << Destination << endl;
	cout << "Адрес: " << Adress << endl;
	cout << "GPS координаты: " << GPS_Coordinates << endl;
	cout << "Количество этажей: " << Floor << endl;
	cout << "Количество помещений: " << CountAccomondation << endl;
	cout << endl << "==============================" << endl;

}

bool EarthArea::CreditProvide()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < creditVectorOfBankLoan.size(); i++)
		CreditSum += creditVectorOfBankLoan[i].getAmount();

	if (MinMarketValueOfMortgage(CreditSum) < AreaRaiting)
		return false;
	else
		return true;
}

bool EarthArea::CreditAdditioanalProvide()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < creditVectorOfBankLoan.size(); i++)
		CreditSum += creditVectorOfBankLoan[i].getAmount();

	if (MinMarketValueOfMortgage(CreditSum) > AreaRaiting)
		return true;
	else
		return false;
}

double EarthArea::AdditionalProvideSum()
{
	float CreditSum = NULL;

	for (size_t i = 0; i < creditVectorOfBankLoan.size(); i++)
		CreditSum += creditVectorOfBankLoan[i].getAmount();

	if (MinMarketValueOfMortgage(CreditSum) > AreaRaiting)
		return MinMarketValueOfMortgage(CreditSum) - AreaRaiting;

}

void EarthArea::InfoOnCredit(string description, float amount, int period, float percent)
{

	BankLoan infoOnCredit(description, amount, period, percent);

	creditVectorOfBankLoan.push_back(infoOnCredit);

}

EarthArea::~EarthArea()
{
}
