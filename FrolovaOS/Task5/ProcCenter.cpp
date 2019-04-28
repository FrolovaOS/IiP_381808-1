#include "ProcCenter.h"




ProcCenter::ProcCenter(string fileName)
{
	ifstream is;
	is.open(fileName);
	is >> ClientCount;
	CardNumber = new int[ClientCount];
	fullname.name = new string[ClientCount];
	fullname.surname = new string[ClientCount];
	fullname.patronymic = new string[ClientCount];
	ClientSum = new int[ClientCount];
	ClientPin = new int[ClientCount];
	CardBlock = new bool[ClientCount];
	WrongPin = new int[ClientCount];

	for (int i = 0; i < ClientCount; i++)
	{
		is >> CardNumber[i];
		is >> fullname.name[i];
		is >> fullname.surname[i];
		is >> fullname.patronymic[i];
		is >> ClientSum[i];
		is >> ClientPin[i];
		is >> CardBlock[i];
		is >> WrongPin[i];
	}
}
bool ProcCenter::ClientFind(string &name1, string &surname1, string &patronymic1, int &ClientSum1, int &ClientPin1, bool &CardBlock1, int &WrongPin1, int _CardNumber)
{
	for (int i = 0; i < ClientCount; i++)
	{
		if (CardNumber[i] == _CardNumber)
		{
			name1 = fullname.name[i];
			surname1 = fullname.surname[i];
			patronymic1 = fullname.patronymic[i];
			ClientSum1 = ClientSum[i];
			ClientPin1 = ClientPin[i];
			CardBlock1 = CardBlock[i];
			WrongPin1 = WrongPin[i];
		}

	}
	if (name1 == "") { return false; }
	return true;
}
bool ProcCenter::GetCardBlock()
{
	return CardBlock;
}

int ProcCenter::GetSum()
{
	return *ClientSum;
}

int ProcCenter::GetClientCount()
{
	return ClientCount;
}

void ProcCenter::ChangeDate(int _CardNumber, int _ClientSum, string fileName)
{
	for (int i = 0; i < ClientCount; i++)
	{
		if (CardNumber[i] == _CardNumber) ClientSum[i] = _ClientSum;
	}
	ofstream is;
	is.open(fileName);
	is.clear();
	is << ClientCount << " ";
	for (int i = 0; i < ClientCount; i++)
	{
		is << CardNumber[i] << " ";
		is << fullname.name[i] << " ";
		is << fullname.surname[i] << " ";
		is << fullname.patronymic[i] << " ";
		is << ClientSum[i] << " ";
		is << ClientPin[i] << " ";
		is << CardBlock[i] << " ";
		is << WrongPin[i] << " ";
	}
	is.close();
}
