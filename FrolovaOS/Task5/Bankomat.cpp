#include "Bankomat.h"


Bankomat::Bankomat()
{
	for (int i = 0; i < 6; i++)
	{
		denominationCount[i] = 1600;
	}
}

int Bankomat::PinCheck(int _ClientPin)
{

	if (Client.ClientPin == _ClientPin)
	{
		Client.WrongPin = 0; return 1;
	}

	if (Client.WrongPin < 2)
	{
		Client.WrongPin++;
		cout << "You entered the wrong pincode \n";
		return 2;

	}
	Client.CardBlock = 0;
	Client.WrongPin = 0;
	cout << "Your card is blocked \n";
	ReturnCard();
	return 1;
}

int Bankomat::GetMoney(int Money)
{

	if ((double(Money) / 5000) > DenominationDown)
	{
		cout << "The amount entered exceeds the limit \n" << endl;
		return 0;
	}
	if ((Money > (denominationCount[6] * 5000 + denominationCount[5] * 2000 + denominationCount[4] * 1000 + denominationCount[3] * 500 + denominationCount[2] * 200 + denominationCount[1] * 100)) && ((Money / 5000) < DenominationDown))
	{
		cout << "ATM is not enough money" << endl;
		return 0;
	}
	if ( Client.ClientSum - Money < 0) return 0;
	Client.ClientSum = Client.ClientSum - Money;
	while (Money >= 5000) { denominationCount[6]--; Money = Money - 5000; }
	while (Money >= 2000) { denominationCount[5]--; Money = Money - 2000; }
	while (Money >= 1000) { denominationCount[4]--; Money = Money - 1000; }
	while (Money >= 500) { denominationCount[3]--; Money = Money - 500; }
	while (Money >= 200) { denominationCount[2]--; Money = Money - 200; }
	while (Money >= 100) { denominationCount[1]--; Money = Money - 100; }

	prc->ChangeDate(Client.CardNumber, Client.ClientSum, "D:/учебники/2 семестр/лабы/Task5/Bankomat/Debug/ProcCenter.txt");

}

int Bankomat::DepositMoney(int Money)
{
	if ((double(Money) / 5000) > DenominationDown)
	{
		cout << "The amount entered exceeds the limit \n" << endl;
		return 0;
	}
	if (Money > ((2000 - denominationCount[6]) * 5000 + (2000 - denominationCount[6]) * 5000 + (2000 - denominationCount[5]) * 2000 + (2000 - denominationCount[4]) * 1000 + (2000 - denominationCount[3]) * 500 + (2000 - denominationCount[2]) * 200 + (2000 - denominationCount[1]) * 100))
	{
		cout << "There is not enough space in the ATM" << endl;
		return 0;
	}
	Client.ClientSum = Client.ClientSum + Money;
	while ((denominationCount[6] < MaxDenominationCount) && (Money >= 5000)) { denominationCount[6]++; Money = Money - 5000; }
	while ((denominationCount[5] < MaxDenominationCount) && (Money >= 2000)) { denominationCount[5]++; Money = Money - 2000; }
	while ((denominationCount[4] < MaxDenominationCount) && (Money >= 1000)) { denominationCount[4]++; Money = Money - 1000; }
	while ((denominationCount[3] < MaxDenominationCount) && (Money >= 500)) { denominationCount[3]++; Money = Money - 500; }
	while ((denominationCount[2] < MaxDenominationCount) && (Money >= 200)) { denominationCount[2]++; Money = Money - 200; }
	while ((denominationCount[1] < MaxDenominationCount) && (Money >= 100)) { denominationCount[1]++; Money = Money - 100; }


	prc->ChangeDate(Client.CardNumber, Client.ClientSum, "D:/учебники/2 семестр/лабы/Task5/Bankomat/Debug/ProcCenter.txt");
}

void Bankomat::ReturnCard()
{
	Client.CardNumber = 0;
	Client.name = "";
	Client.surname = "";
	Client.patronymic = "";
	Client.ClientSum = 0;
	Client.ClientPin = 0;
	Client.CardBlock = 0;
	Client.WrongPin = 0;
}

int Bankomat::GetCardBlock()
{
	return Client.CardBlock;
}

int Bankomat::getCard(int _CardNumber)
{
	Client.CardNumber = _CardNumber;
	string &name1 = Client.name;
	string &surname1 = Client.surname;
	string &patronymic1 = Client.patronymic;
	int &ClientSum1 = Client.ClientSum;
	int &ClientPin1 = Client.ClientPin;
	bool &CardBlock1 = Client.CardBlock;
	int &WrongPin1 = Client.WrongPin;
	int a = prc->ClientFind(name1, surname1, patronymic1, ClientSum1, ClientPin1, CardBlock1, WrongPin1, _CardNumber);

	if (a == 0) return 0;
	else return 1;

}

void Bankomat::printSum()
{
	cout << Client.ClientSum << endl;
}



