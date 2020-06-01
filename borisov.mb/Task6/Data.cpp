#include "Data.h"

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.s_day << "." << date.s_month << "." << date.s_year;
	return out;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	in >> date.s_day;
	char tmp = in.get();
	in >> date.s_month;
	tmp = in.get();
	in >> date.s_year;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Time& time)
{
	out << time.s_hour << ":" << time.s_minute;
	return out;
}

std::istream& operator>>(std::istream& in, Time& time)
{
	in >> time.s_hour;
	char tmp = in.get();
	in >> time.s_minute;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Place& place)
{
	out << "Row: " << place.s_row << " Place: " << place.s_place;
	return out;
}
