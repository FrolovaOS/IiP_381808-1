#include "ProcCenter.h"




ProcCenter::ProcCenter(string _fileName)
{
	fileName = _fileName;
	
	
}
bool ProcCenter::ClientFind(string &name1, string &surname1, string &patronymic1, int &ClientSum1, int &ClientPin1, bool &CardBlock1, int &WrongPin1, int _CardNumber)
{
	for (int i = 0; i < ClientCount; i++)
	{
		if (CardNumber[i] == _CardNumber)
		{
			name1 = name[i];
			surname1 = surname[i];
			patronymic1 = patronymic[i];
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

string ProcCenter::GetFileName()
{
	return fileName;
}


int ProcCenter::GetClientCount()
{
	return ClientCount;
}

void ProcCenter::ChangeDate(int _CardNumber, int _ClientSum)
{
	for (int i = 0; i < ClientCount; i++)
	{
		if (CardNumber[i] == _CardNumber) ClientSum[i] = _ClientSum;
	}
}
ostream & operator<<(ostream &fileName, const ProcCenter &c)
{
	fileName.clear();

	fileName << c.ClientCount << " ";
	for (int i = 0; i < c.ClientCount; i++)
	{
		fileName << c.CardNumber[i] << " ";
		fileName << c.name[i] << " ";
		fileName << c.surname[i] << " ";
		fileName << c.patronymic[i] << " ";
		fileName << c.ClientSum[i] << " ";
		fileName << c.ClientPin[i] << " ";
		fileName << c.CardBlock[i] << " ";
		fileName << c.WrongPin[i] << " ";
	}
	return fileName;
}

istream & operator>>(istream & fileName ,ProcCenter &c)
{
	fileName >> c.ClientCount;
	c.CardNumber = new int[c.ClientCount];
	c.name = new string[c.ClientCount];
	c.surname = new string[c.ClientCount];
	c.patronymic = new string[c.ClientCount];
	c.ClientSum = new int[c.ClientCount];
	c.ClientPin = new int[c.ClientCount];
	c.CardBlock = new bool[c.ClientCount];
	c.WrongPin = new int[c.ClientCount];

	for (int i = 0; i < c.ClientCount; i++)
	{
		fileName >> c.CardNumber[i];
		fileName >> c.name[i];
		fileName >> c.surname[i];
		fileName >> c.patronymic[i];
		fileName >> c.ClientSum[i];
		fileName >> c.ClientPin[i];
		fileName >> c.CardBlock[i];
		fileName >> c.WrongPin[i];
	}
	return fileName;
}
