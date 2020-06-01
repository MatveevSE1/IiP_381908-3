#ifndef CINEMA_H
#define CINEMA_H

#include "TicketOffice.h"

class Cinema
{
public:
	Cinema();
	Cinema(const Cinema& cinema);
	~Cinema();

	TicketOffice& getTicketOffice();

	void printFilmList(Beautiful<std::string>& filmList);
	void printFilmList();
	
private:
	TicketOffice m_ticketOffice;
};


#endif

