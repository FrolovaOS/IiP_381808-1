#include <iostream>
#include <fstream>
#include <iomanip>
#include "Pedometer.h"
using namespace std;



Pedometer::Pedometer(int _size, int _day, int _month, int _year, int _hour, int _min)//start date
{

	leng = 0;
	size = _size;

	step = new int[size];
	year = new int[size];
	month = new int[size];
	day = new int[size];
	hour1 = new int[size];
	min1 = new int[size];
	hour2 = new int[size];
	min2 = new int[size];
	year_start = _year;
	month_start = _month;
	day_start = _day;
	hour_start = _hour;
	min_start = _min;

}

Pedometer::~Pedometer() //Destructor
{
	leng = 0;
	size = 0;
	year_start = 0;
	month_start = 0;
	day_start = 0;
	hour_start = 0;
	min_start = 0;
	if (step != NULL) {
		delete[] step;
		step = NULL;
	}
	if (year != NULL) {
		delete[] year;
		year = NULL;

	}

	if (month != NULL) {
		delete[] month;
		month = NULL;

	}
	if (day != NULL) {
		delete[] day;
		day = NULL;
	}
	if (hour1 != NULL) {
		delete[] hour1;
		hour1 = NULL;
	}

	if (min1 != NULL) {
		delete[] min1;
		min1 = NULL;
	}
	if (hour2 != NULL) {
		delete[] hour2;
		hour2 = NULL;
	}
	if (min2 != NULL) {
		delete[] min2;
		min2 = NULL;
	}
}

void Pedometer::GetStartDate()//getting start date 
{
	cout << "The date of begining : " << day_start << "." << month_start << "." << year_start << ". The time is " << hour_start << ":" << min_start << endl;
}
void Pedometer::newObservation(int _day, int _month, int _year, int _hour1, int _min1, int _hour2, int _min2, int _step)//adding observation
{

	if (leng < size)
	{

		year[leng] = _year;
		month[leng] = _month;
		day[leng] = _day;
		hour1[leng] = _hour1;
		min1[leng] = _min1;
		hour2[leng] = _hour2;
		min2[leng] = _min2;
		step[leng] = _step;
		leng++;

	}
	else
	{
		
		int* year_copy;
		int* month_copy;
		int* day_copy;
		int* hour1_copy;
		int* min1_copy;
		int* hour2_copy;
		int* min2_copy;
		int* step_copy;
		
		year_copy = new int[size];
		month_copy = new int[size];
		day_copy = new int[size];
		hour1_copy = new int[size];
		min1_copy = new int[size];
		hour2_copy = new int[size];
		min2_copy = new int[size];
		step_copy = new int[size];

		for (int i = 0; i < leng; i++)
		{
			year_copy[i] = year[i];
			month_copy[i] = month[i];
			day_copy[i] = day[i];
			hour1_copy[i] = hour1[i];
			min1_copy[i] = min1[i];
			hour2_copy[i] = hour2[i];
			min2_copy[i] = min2[i];
			step_copy[i] = step[i];
		}

		size++;

		year = new int[size];
		month = new int[size];
		day = new int[size];
		hour1 = new int[size];
		min1 = new int[size];
		hour2 = new int[size];
		min2 = new int[size];
		step = new int[size];

		for (int i = 0;i < leng; i++)
		{
			year[i] = year_copy[i];
			month[i] = month_copy[i];
			day[i] = day_copy[i];
			hour1[i] = hour1_copy[i];
			min1[i] = min1_copy[i];
			hour2[i] = hour2_copy[i];
			min2[i] = min2_copy[i];
			step[i] = step_copy[i];
		}

		delete[] year_copy;
		delete[] month_copy;
		delete[] day_copy;
		delete[] hour1_copy;
		delete[] min1_copy;
		delete[] hour2_copy;
		delete[] min2_copy;
		delete[] step_copy;

		year[leng] = _year;
		month[leng] = _month;
		day[leng] = _day;
		hour1[leng] = _hour1;
		min1[leng] = _min1;
		hour2[leng] = _hour2;
		min2[leng] = _min2;
		step[leng] = _step;
		leng++;

	}
}

int Pedometer::GetInf(int _day, int _month, int _year, int _hour1, int _min1, int _hour2, int _min2)//getting start date 
{

	for (int i = 0; i <= leng; i++)
	{
		if ((_year == year[i] || _year == year_start) && (_month == month[i] || _month == month_start) && (_day == day[i] || _day == day_start) && (_hour1 == hour1[i] || _hour1 == hour_start) && (_min1 == min1[i] || _min1 == min_start) && _hour2 == hour2[i] && _min2 == min2[i])
		{
			return step[i];
		}
		else if (i == size) {
			cout << "Observation not found.\n";
			return -1;
		}
	}

}
int Pedometer::AveregeStepsMonth(int _month) //average steps per month
{
	int Steps = 0;
	int num = 0;
	for (int i = 0; i <= leng; i++)
		if (_month == month[i])
		{
			num++;
			Steps += step[i];
		}
	return Steps / num;
}
int Pedometer::AveregeStepsAllTime()//average steps at all time
{
	int Steps = 0;
	for (int i = 0; i < leng; i++) {
		Steps += step[i];
	}
	return Steps / leng;
}

int Pedometer::MaxStepsMonth(int Month, int Day)//max steps per month
{
	int Steps = 0;
	for (int i = 0; i <= leng; i++)
		if (Month == month[i] && Day == day[i] && step[i] > Steps)
		{
			Steps = step[i];
		}
	return Steps;
}
int Pedometer::DateMaxStepsMonth(int _month)//the month when the maximum number of steps was reached
{
	int num;
	int Steps = 0;
	for (int i = 0; i <= leng; i++)
		if (_month == month[i] && step[i] > Steps)
		{
			Steps = step[i];
			num = day[i];
		}
	return num;

}
int Pedometer::MaxStepsAllTime()//max steps at all time
{
	int Steps = 0;
	for (int i = 0; i <= leng; i++)
		if (step[i] > Steps)
		{
			Steps = step[i];
		}
	return Steps;
}
//дата
void Pedometer::DateMaxSteps(int &d, int&m, int&y) //the date when the maximum number of steps was reached
{
	int Steps = 0;
	for (int i = 0; i <= leng; i++)
		if (step[i] > Steps)
		{
			Steps = step[i];
			m = month[i];
			d = day[i];
			y = year[i];
		}
}

ostream& operator<<(ostream & stream, const Pedometer &c)
{
	stream << c.leng << " " << c.size << " " << c.day_start << " " << c.month_start << " " << c.year_start << " " << c.hour_start << " " << c.min_start << " ";
	for (int i = 0; i < c.leng; i++)
	{
		stream << c.day[i] << " ";
		stream << c.month[i] << " ";
		stream << c.year[i] << " ";
		stream << c.hour1[i] << " ";
		stream << c.min1[i] << " ";
		stream << c.hour2[i] << " ";
		stream << c.min2[i] << " ";
		stream << c.step[i] << " ";
	}
	
	stream << endl;
	return stream;
}

istream& operator>>(istream& stream, Pedometer& c)
{
	int leng, size;
	stream >> leng >> size;
	int year_st, month_st, day_st, hour_st, min_st;
	stream >> day_st >> month_st >> year_st >> hour_st >> min_st;
	c.year_start = year_st;
	c.month_start = month_st;
	c.day_start = day_st;
	c.hour_start = hour_st;
	c.min_start = min_st;
	if ((c.size < size) || (c.size > size))
	{

		delete[] c.year;
		delete[] c.month;
		delete[] c.day;
		delete[] c.hour1;
		delete[] c.min1;
		delete[] c.hour2;
		delete[] c.min2;
		delete[] c.step;
		
		c.year = new int[size];
		c.month = new int[size];
		c.day = new int[size];

		c.hour1 = new int[size];
		c.min1 = new int[size];
		c.hour2 = new int[size];
		c.min2 = new int[size];

		c.step = new int[size];

		
	}
	c.leng = leng;
	c.size = size;
			for (int i = 0; i < c.leng; i++)
			{
				stream >> c.day[i];
				stream >> c.month[i];
				stream >> c.year[i];
				stream >> c.hour1[i];
				stream >> c.min1[i];
				stream >> c.hour2[i];
				stream >> c.min2[i];
				stream >> c.step[i];
			}
			return stream;
}
