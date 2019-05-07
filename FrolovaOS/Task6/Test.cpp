#include "BullsAndCows.h"
#include <iostream>
using namespace std;

int main()
{
	Play A;
	cout << "Enter the length of the number " << endl;
	int n;
	cin >> n;
	A.Setn(n);
	A.GetCount();//random number generation
	//A.GetAnswer();
	A.SetCount();
	A.coincidence();
	while (A.ShowRes() != 1) { A.SetCount(); A.coincidence(); }
	getchar();
	getchar();
	return 0;
}
