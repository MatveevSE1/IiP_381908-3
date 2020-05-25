#include "Hall.h"

void Hall::sitDown(std::string _zone, int _numberOfPlaces)
{
	int row, place;
	for (int i = 0; i < _numberOfPlaces; i++) {
		std::cout << "Choose place: " << std::endl;
		std::cout << "Row: ";
		std::cin >> row;
		std::cout << "Place: ";
		std::cin >> place;
		assert(row > 0 and row <= 10);
		assert(place > 0 and place <= 15);
		if (_zone == "VIP") {
			assert(row < 3 or row == 10);
		}
		m_places.pushBack(Place(row, place));
	}
}

Hall::Hall() : m_noOfHall(1), m_priceForTicket(150), m_numberOfFreePlaces(150), m_places()
{
}

Hall::Hall(const Hall& hall) : m_noOfHall(hall.m_noOfHall), m_priceForTicket(hall.m_priceForTicket),
	m_numberOfFreePlaces(hall.m_numberOfFreePlaces), m_places(hall.m_places)
{ }

Hall::Hall(int _noOfHall, std::string _zone, int _numberOfPlaces) : m_noOfHall(_noOfHall)
{
	m_priceForTicket = 150;
	m_numberOfFreePlaces = MAX_ROWS * MAX_PLACES;
	if (_zone == "VIP") {
		m_priceForTicket = 250;
		sitDown(_zone, _numberOfPlaces);
	}
	if (_zone == "Basic") {
		m_priceForTicket = 150;
		sitDown(_zone, _numberOfPlaces);
	}
	else {
		throw std::logic_error("zone_error: There is no " + _zone + " zone");
	}
	m_numberOfFreePlaces -= _numberOfPlaces;
}

Hall::~Hall()
{

}

int Hall::getFreePlaces() const
{
	return m_numberOfFreePlaces;
}

int Hall::getNoOfHall() const
{
	return m_noOfHall;
}

int Hall::getPriceForTicket() const
{
	return m_priceForTicket;
}

Beautiful<Place>& Hall::getPlaces()
{
	return m_places;
}



