#pragma once
#include <iostream>
#include <vector>
#include  "BankLoan.h"

#define LEVEL_INFLATION 0.40	   //������� �������� �� (������ 2018)
#define KOEF 0.15				   //�����������, ����������� ������� �����
#define LEVEL_WEAR 0.37			   //������� ������ 
#define valuationOfFacilities 0.54 //��� - ������ ������ �� ������ ��������� ��������

using namespace std;

/* ������� ����������� ����� ���������� ��������� */
class Mortgage
{
private:
	double amountOfMortgage;	  // ����� ���������� ���������
	double marketValueOfMortgage; // �������� ��������� ���������� ���������

protected:
	/* ������ � �������� (��� ��������� ������������� ������� ������ BankLoan)*/
	BankLoan * credit;
	vector<BankLoan> creditVectorOfBankLoan;

	float interestRateOnCredit; // ���������� ������ �� �������
	virtual void InfoOnCredit(string description, float amount, int period, float percent) = 0;
public:
	Mortgage();

	/* ������:
	- ����������� ����������� �������� ���������������� �������;
	- ����������� �������� �������� ��������� ������.           */

	virtual double MinCreditAmount() = 0;					    // ����������� �������� ���������������� �������
	virtual double MinMarketValueOfMortgage(double amount) = 0; // ����������� �������� �������� ��������� ������

	virtual ~Mortgage();
};

//ostream &operator<<(ostream &stream, Mortgage &obj)
//{
//	stream << obj.MinCreditAmount << endl;
//}

class Facilities : public Mortgage
{
private:
	double amountOfCredit;		  // � - ����� �������

protected:
	int totalArea;		    //����� �������
	int usefulArea;		    //�������� �������
	string purpose;		    //����������
	string address;		    //������
	string GPS;			    //GPS ����������
	int quantityOfFloors;   //���������� ������
	int quantityOfPremises; //���������� ���������

	const double INF = 10.2;				 //������ �������� �� ���� ������ ����������
	const double P = 0.2;					 //�������� ��������
	const double IZN = 0.7;					 //������� ������ ������(����������)

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
	double AreaRaiting;  //������ ���������� �������
protected:
	enum { Residential, General, Buiseness };

	int GeneralSquare;			   //����� �������
	int UsefullSquare;			   //�������� �������
	string Destination;			   //����������
	string Adress;			       //������
	string GPS_Coordinates;		   //GPS ����������
	short int Floor;			   //���������� ������
	short int CountAccomondation;  //���������� ���������
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


