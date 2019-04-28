#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class ProcCenter
{

private:
	int *CardNumber;
	struct {
		string *surname;
		string *name;
		string *patronymic;
	} fullname;
	int *ClientSum;
	int *ClientPin;
	bool *CardBlock;//0-block;1-not block
	int *WrongPin;//the number of attempts to enter the wrong PIN code
	int ClientCount;

public:
	string fileName = "D:/учебники/2 семестр/лабы/Task5/Bankomat/Debug/ProcCenter.txt";
	ProcCenter(string fileName);
	bool ClientFind(string &name1, string &surname1, string &patronymic1, int &ClientSum, int &ClientPin, bool &CardBlock, int &WrongPin, int _CardNumber);
	bool GetCardBlock();
	int GetSum();
	int GetClientCount();
	void ChangeDate(int _CardNumber, int _ClientSum, string fileName);//write new file with changes


};
#pragma once
