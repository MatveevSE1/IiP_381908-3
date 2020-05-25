#ifndef SESSION_H
#define SESSION_H

#include "Hall.h"
#include "Data.h"

class Session
{
public:
	Session();
	Session(Date _date, Time _timeOfStart, std::string _title, int _nameOfHall,
		std::string _zone, int _numberOfPlaces);
	Session(const Session& session);
	~Session();

	Session& operator=(const Session& session);
	Session& operator=(const int zero);

	Hall getHall() const;
	Date getDate() const;
	Time getTimeOfStart() const;
	std::string getTitle() const;
private:
	Date m_date;
	Time m_timeOfStart;
	std::string m_title;
	int m_price;
	Hall m_hall;
};
#endif

