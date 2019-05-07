#include <iostream>
#include <cstdlib>
#include "BullsAndCows.h"
#include <time.h>


using namespace std;

Play::Play()
{
	n = 0;
	Count1 = NULL;//computer numbers
	Count2 = NULL;//player numbers
	Cows = 0;
	Bulls = 0;
}

Play::~Play()
{
	n = 0;
	delete Count1;
	delete Count2;
	Count1 = NULL;//computer numbers
	Count2 = NULL;//player numbers
	Cows = 0;
	Bulls = 0;
}

void Play::Setn(int _n)
{
	n = _n;
}

void Play::GetCount()
{
	Count1 = new int[n];
	for (int i = 0; i < n; i++)
	{
	met:
		srand(time(NULL));
		int number = rand() % 10;
		if (Count[number] != -1)
		{
			Count1[i] = Count[number];
			Count[number] = -1;
		}
		else goto met;
	}
}

void Play::SetCount()
{
	if (Count2 != NULL) {
		delete Count2;
		Count2 = NULL;
	}
	Count2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> Count2[i];
	}
}

void Play::GetAnswer()
{
	for (int i = 0; i < n; i++)
	{
		cout << Count1[i] << " ";
	}
	cout << endl;
}

void Play::coincidence()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((Count1[i] == Count2[j]) && (i != j))
			{
				Cows++;
			}
			if ((Count1[i] == Count2[j]) && (i == j))
			{
				Bulls++;
			}
		}
	}


}

int Play::ShowRes()
{
	cout << Cows << " " << Bulls << endl;

	if (Bulls == n) { cout << "You are winner!" << endl; return 1; }
	Cows = 0; Bulls = 0;
}


