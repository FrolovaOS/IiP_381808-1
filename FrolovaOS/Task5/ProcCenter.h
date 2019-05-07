#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class ProcCenter
{

private:
	int *CardNumber;
	string *surname;
	string *name;
	string *patronymic;
	int *ClientSum;
	int *ClientPin;
	bool *CardBlock;//0-block;1-not block
	int *WrongPin;//the number of attempts to enter the wrong PIN code
	int ClientCount;
    string fileName;
public:
	
	ProcCenter(string fileName);
	bool ClientFind(string &name1, string &surname1, string &patronymic1, int &ClientSum, int &ClientPin, bool &CardBlock, int &WrongPin, int _CardNumber);
	//bool GetCardBlock();
	//int GetSum();
	string GetFileName();
	//int GetClientCount();
	void ChangeDate(int _CardNumber, int _ClientSum);//write new file with changes

	friend istream &operator >> (istream &fileName, ProcCenter &c);//overloaded input operator
	friend ostream &operator<< (ostream &fileName, const ProcCenter &c); // overloaded output operator
	
};
ostream& operator<<(ostream & fileName, const ProcCenter &c);
istream& operator >> (istream & fileName, ProcCenter &c);


