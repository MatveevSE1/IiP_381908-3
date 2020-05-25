#ifndef DATA_H
#define DATA_H

#include "Beautiful.h"
#include <string>
#include <cassert>
#include <iostream>
#include <Windows.h>

const int MAX_ROWS = 10;
const int MAX_PLACES = 15;

struct Date
{
	int s_day;
	int s_month;
	int s_year;
	Date() : s_day(0), s_month(0), s_year(0) { }
	Date(int _day, int _month, int _year) : s_day(_day), s_month(_month), s_year(_year) { }
};

std::ostream& operator<<(std::ostream& out, const Date& date);
std::istream& operator>>(std::istream& in, Date& date);

struct Time
{
	int s_hour;
	int s_minute;
	Time() : s_hour(0), s_minute(0) { }
	Time(int _hour, int _minute) : s_hour(_hour), s_minute(_minute){ }
};

std::ostream& operator<<(std::ostream& out, const Time& time);
std::istream& operator>>(std::istream& in, Time& time);

struct Place
{
	int s_row;
	int s_place;
	Place() : s_row(0), s_place(0) { }
	Place(int _row, int _place) : s_row(_row), s_place(_place) { }
};

std::ostream& operator<<(std::ostream& out, const Place& place);



#endif