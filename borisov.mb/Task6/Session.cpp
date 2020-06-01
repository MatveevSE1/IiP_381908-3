#include "Session.h"

Session::Session() : m_date(), m_timeOfStart(), m_title(""), m_hall()
{ }

Session::Session(Date _date, Time _timeOfStart, std::string _title, int _noOfHall,
		std::string _zone, int _numberOfPlaces) :
	m_date(_date),
	m_timeOfStart(_timeOfStart),
	m_title(_title),
	m_hall(_noOfHall, _zone, _numberOfPlaces)
{ }

Session::Session(const Session& session) : m_date(session.m_date), m_timeOfStart(session.m_timeOfStart),
	m_title(session.m_title), m_hall(session.m_hall)
{ }

Session::~Session()
{

}

Session& Session::operator=(const Session& session)
{
	m_date = session.m_date;
	m_timeOfStart = session.m_timeOfStart;
	m_title = session.m_title;
	m_hall = session.m_hall;
	return *this;
}

Session& Session::operator=(const int zero)
{
	m_date = Date();
	m_timeOfStart = Time();
	m_title = "";
	m_hall = Hall();
	return *this;
}

Hall Session::getHall() const
{
	return m_hall;
}

Date Session::getDate() const
{
	return m_date;
}

Time Session::getTimeOfStart() const
{
	return m_timeOfStart;
}

std::string Session::getTitle() const
{
	return m_title;
}
