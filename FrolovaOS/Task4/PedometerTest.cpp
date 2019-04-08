#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Pedometer.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int day, month, year, hour1, min1, hour2, min2, step;
	cout << "Enter the start date and time of observation. " << endl;
	cin >> day >> month >> year >> hour1 >> min1;
	Pedometer A(100, day, month, year, hour1, min1);
	Pedometer B(100, 1, 1, 2019, 0, 0);
	int var;
	cout << "1. Find out the time and time of calculation" << endl;
	cout << "2. Add observation" << endl;
	cout << "3. Get counting information by date and time interval" << endl;
	cout << "4. Average number of steps in the selected month" << endl;
	cout << "5. average number of steps in the entire history of observations" << endl;
	cout << "6 maximum number of steps in the selected month and date " << endl;
	cout << "7 maximum number of steps per day in the entire history of observations and date" << endl;
	cout << "8 to finish work" << endl;
	int Exit = 1;
	while (Exit) {
		cin >> var;
		switch (var)
		{
		case 1:
		{
			A.GetStartDate();
			break;
		}
		case 2:
		{
			cout << "Enter : day, month, year, hour and min of begin, hour and min of end and steps." << endl;
			cin >> day >> month >> year >> hour1 >> min1 >> hour2 >> min2 >> step;
			A.newObservation(day, month, year, hour1, min1, hour2, min2, step);
			break;
		}
		case 3:
		{
			cout << "Enter : day, month, year, hour and min of begin,hour and min of end and, which you what to know" << endl;
			cin >> day >> month >> year >> hour1 >> min1 >> hour2 >> min2;
			cout << A.GetInf(day, month, year, hour1, min1, hour2, min2) << endl;
			break;
		}
		case 4: {

			cout << "Enter the month, which you what to know" << endl;
			cin >> month;
			cout << "The Avarege count steps of this month :" << endl;
			cout << A.AveregeStepsMonth(month) << endl;
			break;
		}
		case 5:
		{
			cout << "The Avarege count steps of all time :" << endl;

			cout << A.AveregeStepsAllTime() << endl;
			break;
		}
		case 6: {
			cout << "Enter the month and day, which you what to know" << endl;
			cin >> month >> day;
			cout << "Max steps of this date : " << endl;
			cout << A.MaxStepsMonth(month, day) << endl;
			break;
		}
		case 7:
		{

			A.DateMaxSteps(day, month, year);
			cout << "Max steps of all time : " << A.MaxStepsAllTime() << endl;

			cout << "The date : " << day << "." << month << "." << year << endl;
			break;
		}
		case 8:
		{
			Exit = 0;
			break;

		}

		}
	}
	ofstream os;
	os.open("Pedomet.txt");
	os << A << endl;
	os.close();
	ifstream is;
	is.open("Pedomet.txt");
	is >> B;
	is.close();

}

