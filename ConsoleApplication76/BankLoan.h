#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/* Банковский кредит */
class BankLoan
{
private:
	float amount;						      // сумма кредита
	int period;								  // срок кредита
	float percent;							  // процент по кредитту
	string description;						  // описание кредита
	static float rateOfAnnuity(BankLoan obj); // аннуитет
public:
	BankLoan();
	BankLoan(string description, float amount, int period, float percent);

	void static getLoanRepaymentSchedule(BankLoan obj);
	BankLoan operator=(BankLoan obj);
	string getLoanName();
	float getRateOfAnnuity();
	float getAmount();
	int getDate();
	float getPercent();
	string getContent();

	virtual ~BankLoan();
};


