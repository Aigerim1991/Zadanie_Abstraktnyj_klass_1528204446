#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/* ���������� ������ */
class BankLoan
{
private:
	float amount;						      // ����� �������
	int period;								  // ���� �������
	float percent;							  // ������� �� ��������
	string description;						  // �������� �������
	static float rateOfAnnuity(BankLoan obj); // ��������
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


