#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "BankLoan.h"
#include "Header.h"

using namespace std;

float BankLoan::rateOfAnnuity(BankLoan obj)
{
	float rate;

	rate = ((obj.percent / 12 / 100)*pow(1 + (obj.percent / 12 / 100), obj.period)) / (pow(1 + (obj.percent / 12 / 100), obj.period) - 1);
	float monthlyAnnuityPayment = rate * obj.amount;
	return monthlyAnnuityPayment;
}

BankLoan::BankLoan()
{
	amount = 0;
	period = 0;
	percent = 0;
}

BankLoan::BankLoan(string description, float amount, int period, float percent)
{
	this->description = description;
	this->amount = amount;
	this->period = period;
	this->percent = percent;
}

void BankLoan::getLoanRepaymentSchedule(BankLoan obj)
{
	double overpayment = rateOfAnnuity(obj)*obj.period - obj.amount;
	cout << "Loan name: " << obj.description << endl;
	cout << "Loan summ: " << fixed << setprecision(2) << setw(10) << obj.amount << endl;
	ShortLine();
	cout << "Month       Amount" << endl;
	for (int i = 1; i <= obj.period; i++)
	{
		cout << fixed << setw(2) << right << i << fixed << setw(20) << rateOfAnnuity(obj) << endl;
	}
	ShortLine();
	cout << "Overpayments: " << overpayment << endl;
}

BankLoan BankLoan::operator=(BankLoan obj)
{
	amount = obj.amount;
	period = obj.period;
	percent = obj.percent;
	description = obj.description;

	return *this;
}

string BankLoan::getLoanName()
{
	return description;
}

float BankLoan::getRateOfAnnuity()
{
	return rateOfAnnuity(*this);
}

float BankLoan::getAmount()
{
	return amount;
}

int BankLoan::getDate()
{
	return period;
}

float BankLoan::getPercent()
{
	return percent;
}

string BankLoan::getContent()
{
	return description;
}


BankLoan::~BankLoan()
{
}
