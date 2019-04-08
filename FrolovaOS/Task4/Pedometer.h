#include <iostream>
#include <fstream>
using namespace std;
class Pedometer
{
private:

	int *year;
	int *month;
	int *day;
	int *hour1;
	int *min1;
	int *hour2;
	int *min2;
	int *step;
	int size;//maximum number of observations
	int leng;//current number of observations
	int year_start;
	int month_start;
	int day_start;
	int hour_start;
	int min_start;

public:
	//constructors
	Pedometer();//po umolchaniu
	//inicializators
	Pedometer(int _size, int _day, int _month, int _year, int _hour, int _min);
	//Destructor
	~Pedometer();
	void newObservation(int _day, int _month, int _year, int _hour1, int _min1, int _hour2, int _min2, int _step);
	void SetSize(int _size);
	void GetStartDate();
	int GetInf(int year, int month, int day, int hour1, int min1, int hour2, int min2);//count of step
	int AveregeStepsMonth(int month);//average steps per month
	int AveregeStepsAllTime();//average steps at all time
	int MaxStepsMonth(int Month, int Day);//max steps per month
	int MaxStepsAllTime();//max steps at all time
	int DateMaxStepsMonth(int month);//the month when the maximum number of steps was reached
	void DateMaxSteps(int &d, int&m, int&y);//the date when the maximum number of steps was reached


	friend ostream &operator<<(ostream &stream, const Pedometer &c);
	friend istream &operator>>(istream &stream, Pedometer &c);

};



ostream& operator<<(ostream & stream, const Pedometer &c);
istream& operator >> (istream & stream, Pedometer &c);



