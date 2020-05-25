#include "TicketOffice.h"

TicketOffice::TicketOffice()
{
	m_sessions.reallocate(0);
	m_id = 0;
}

TicketOffice::TicketOffice(const TicketOffice& ticketOffice)
{
	m_sessions = Beautiful<Session>(ticketOffice.m_sessions);
	m_id = ticketOffice.m_id;
}

TicketOffice::~TicketOffice()
{
	m_sessions.reallocate(0);
	m_id = 0;
}

void TicketOffice::makeOrder(Date _date, Time _timeOfStart, std::string _title, int _noOfHall, 
		std::string _zone, int _numberOfPlaces)
{
	assert(_noOfHall > 0 and _noOfHall <= 6);
	assert(_zone == "VIP" or _zone == "Basic");	

	m_sessions.pushBack(Session(_date, _timeOfStart, _title, _noOfHall, _zone, _numberOfPlaces));
	std::cout << "Done." << "Your id is " << m_id << std::endl;
	m_id++;
}

void TicketOffice::checkFreePlaces(int _numberOfPlaces, std::string _zone)
{
	std::string count;
	std::string inThe = "There are empty places for you in the halls: ";
	if (m_sessions.size() == 0) {
		std::cout << "Cinema is empty. Be the first" << std::endl;
		return;
	}
	for (int i = 0; i < m_sessions.size(); i++) {
		if (m_sessions[i].getHall().getFreePlaces() >= _numberOfPlaces) {
			count += std::to_string(m_sessions[i].getHall().getNoOfHall());
		}
	}
	std::cout << inThe + count << "\n";
}

void TicketOffice::reservePlaces(int _numberOfPlaces) 
{
	Session reserved;
	for (int i = 0; i < m_sessions.size(); i++) {
		if (m_sessions[i].getHall().getFreePlaces() == _numberOfPlaces) {
			reserved = Session(m_sessions[i].getDate(), m_sessions[i].getTimeOfStart(), m_sessions[i].getTitle(),
				m_sessions[i].getHall().getNoOfHall(), "Basic", _numberOfPlaces);
		}
	}
	m_id++;
	std::cout << "Done." << "Your id is " << m_id << std::endl;
	m_sessions.pushBack(reserved);
}

void TicketOffice::calculateCost(int _id)
{
	bool isMorning = m_sessions[_id].getTimeOfStart().s_hour >= 8 and
		m_sessions[_id].getTimeOfStart().s_hour < 12;
	bool isEvening = m_sessions[_id].getTimeOfStart().s_hour >= 18 and
		m_sessions[_id].getTimeOfStart().s_hour < 23;
	int priceForTicket = m_sessions[_id].getHall().getPriceForTicket();
	if (isMorning) {
		priceForTicket *= 0.75;
	}
	if (isEvening) {
		priceForTicket *= 1.5;
	}
	int numberOfPlaces = -(m_sessions[_id].getHall().getFreePlaces() - 150);
	int resultCost = priceForTicket * numberOfPlaces;
	std::cout << "Result cost for ID " << _id << " is " << resultCost << " rubles" <<std::endl;
}

void TicketOffice::cancelOrder(int _id)
{
	m_sessions.remove(_id);
	std::cout << "Done. Order is canceled" << std::endl;
}

void TicketOffice::printTickets(int _id)
{
	int numberOfPlaces = m_sessions[_id].getHall().getPlaces().size();
	std::cout << "Give us a second...\nWe are forming tickets for you...\n";
	Sleep(2000);
	std::cout << "Title: " << m_sessions[_id].getTitle() << "\n";
	std::cout << "Date: " << m_sessions[_id].getDate() << "\n";
	std::cout << "Time: " << m_sessions[_id].getTimeOfStart() << "\n";
	std::cout << "Hall: #" << m_sessions[_id].getHall().getNoOfHall() << "\n";
	for (int i = 0; i < numberOfPlaces; i++) {
		std::cout << "Place: #" << i + 1 << " " << m_sessions[_id].getHall().getPlaces()[i] << "\n";
	}
}
