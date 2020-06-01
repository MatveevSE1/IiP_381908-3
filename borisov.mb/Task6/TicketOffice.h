#ifndef TICKETOFFICE_H
#define TICKETOFFICE_H

#include "Session.h"

class TicketOffice
{
public:
	TicketOffice();
	TicketOffice(const TicketOffice& ticketOffice);
	~TicketOffice();

	void makeOrder(Date _date, Time _timeOfStart, std::string _title, int _noOfHall, 
		std::string _zone, int _numberOfPlaces);
	void checkFreePlaces(int _numberOfPlaces, std::string _zone); // FIX ME: NEED TO CHECK ZONE VIP OR NOT
	void reservePlaces(int _numberOfPlaces);
	void calculateCost(int _id); 
	//void calculateCost(Date _date, Time _timeOfStart, std::string _title); // FIX ME: CHECK FOR BETTER ARGS
	void cancelOrder(int _id); 
	//void cancelOrder(Date _date, Time _timeOfStart, std::string _title); // FIX ME: CHECK FOR BETTER ARGS
	void printTickets(int _id); // FIX ME

private:
	Beautiful<Session> m_sessions;
	int m_id;

};

#endif

