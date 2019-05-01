#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include "ProcCenter.h"

using namespace std;



class Bankomat
{
private:

	int denominationCount[6];//denomination (100,200,500,1000,2000,5000)
	const int MaxDenominationCount = 2000;//maximum number of bills
	const int DenominationDown = 40;//maximum amount of money that can be withdrawn at once
	struct //customer data, whose card at an ATM
	{
		int CardNumber;
		string surname;
		string name;
		string patronymic;
		int ClientSum;
		int ClientPin;
		bool CardBlock;//0-block;1-not block
		int WrongPin;//the number of attempts to enter the wrong PIN code
	} Client;

public:

	Bankomat();//default constructor
	//methods
	int getCard(int _CardNumber);
	void printSum();
	int GetCardBlock();
	int PinCheck(int _ClientPin);
	int GetMoney(int Money);
	int DepositMoney(int Money);
	void ReturnCard();

	ProcCenter *prc = new ProcCenter("C:/Users/Ol/Desktop/FrolovaOS/IiP_381808-1/FrolovaOS/Task5/x64/Debug/ProcCenter.txt");


};

#pragma once
