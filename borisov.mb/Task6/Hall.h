#ifndef HALL_H
#define HALL_H

#include "Data.h"

class Hall
{
public:
	Hall();
	Hall(const Hall& hall);
	Hall(int _noOfHall, std::string _zone, int _numberOfPlaces);
	~Hall();

	int getFreePlaces() const;
	int getNoOfHall() const;
	int getPriceForTicket() const;
	Beautiful<Place>& getPlaces();

	int calculateCost();

private:
	void sitDown(std::string _zone, int _numberOfPlaces);

	int m_noOfHall;
	int m_priceForTicket;
	int m_numberOfFreePlaces;
	Beautiful<Place> m_places;
};

#endif

