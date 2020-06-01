#include "Cinema.h"

Cinema::Cinema()
{
	m_ticketOffice = TicketOffice();
}

Cinema::Cinema(const Cinema& cinema)
{
	m_ticketOffice = TicketOffice(cinema.m_ticketOffice);
}

Cinema::~Cinema()
{
	m_ticketOffice.~TicketOffice();
}

TicketOffice& Cinema::getTicketOffice()
{
	return m_ticketOffice;
}

void Cinema::printFilmList(Beautiful<std::string>& filmList)
{
	int numberOfFilms = 3;
	std::cout << "\t\tFILM LIST" << "\n";
	std::cout << "11:00 - The Flash\n";
	std::cout << "15:00 - Harry Potter and the carantine\n";
	std::cout << "20:00 - Missing Street\n";
	filmList.pushBack("The Flash");
	filmList.pushBack("Harry Potter and the carantine");
	filmList.pushBack("Missing Street");
}

void Cinema::printFilmList()
{
	std::cout << "\t\tFILM LIST" << "\n";
	std::cout << "11:00 - The Flash\n";
	std::cout << "15:00 - Harry Potter and the carantine\n";
	std::cout << "20:00 - Missing Street\n";
}
