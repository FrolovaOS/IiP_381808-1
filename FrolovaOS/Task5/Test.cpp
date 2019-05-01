#include <string>
#include <iostream>
#include <fstream>
#include <clocale>
#include "Bankomat.h"



using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Bankomat A;
	cout << "Enter the number of card" << endl;
	int numberCard;
	cin >> numberCard;
	if (A.getCard(numberCard) == false)
	{
		cout << "Card not found." << endl;
		A.ReturnCard();
	}
	cout << "Enter pincode" << endl;
	int ClientPin;
	cin >> ClientPin;
	while (A.PinCheck(ClientPin) != 1)
	{
		cin >> ClientPin;
	}
	if (A.GetCardBlock() == 0) return 0;
	int var = 1;
	int Money;
	cout << "Select an action: \n 1. Show the amount \n 2. Get money \n 3. Deposit money \n 4. Finish \n" << endl;
	while (var)
	{
		cin >> var;
		switch (var)
		{
		case 1:
		{
			A.printSum();
			break;
		}
		case 2:
		{
		met:
			cout << "Enter the amount you want to get \n" << endl;
			do
			{
				cout << "Enter the number multiple of 100 " << endl;
				cin >> Money;

			} while (Money % 100 != 0);
			if (A.GetMoney(Money) == 0) goto met;
			break;

		}
		case 3:
		{
		met1:
			cout << "Enter the amount you put on the account \ n" << endl;
			do
			{
				cout << "Enter the number multiple of 100 " << endl;
				cin >> Money;

			} while (Money % 100 != 0);

			if (A.DepositMoney(Money) == 0) goto met1;
			break;
		}
		case 4:
		{
			var = 0;
			A.ReturnCard();
			break;
		}
		}
	}

	return 0;
}