#include "Cinema.h"
bool checkDate(const Date& nowDate, const Date& newDate)
{
	bool isOk = newDate.s_day - nowDate.s_day < 3 or newDate.s_month == nowDate.s_month or
		newDate.s_year == nowDate.s_year;
	if (isOk)
		return true;
	else
		return false;
}

void enterNCheckDate(Date& date, const Date& todayDate)
{
	std::cout << "Choose date of film\n>>";
	std::cin >> date;
	assert(checkDate(todayDate, date));
	//if (!checkDate(todayDate, date)) {
	//	throw std::logic_error("input_error: You can make an order within 3 days");
	//}
}

void enterNCheckTitle(std::string& title, Beautiful<std::string>& filmList)
{
	int tmp;
	std::cout << "Choose film\n>>";
	std::cin >> tmp;
	title = filmList[tmp - 1];
}

void enterNCheckTime(Time& time)
{
	std::cout << "Enter Time: ";
	std::cin >> time;
}

void enterNoOfHall(int& noOfHall)
{
	std::cout << "Choose hall\n>>";
	std::cin >> noOfHall;
}

void enterZone(std::string& zone)
{
	std::cout << "Choose zone\n>>";
	std::cin >> zone;
	assert(zone == "Basic" or zone == "VIP");
}

void enterNumberOfPlaces(int& numberOfPlaces)
{
	std::cout << "How many places do you order?\n>>";
	std::cin >> numberOfPlaces;
	assert(numberOfPlaces <= 150);
}

void enterID(int& id)
{
	std::cout << "Enter ID: ";
	std::cin >> id;
	
}



int main()
{
	
	Beautiful<std::string> filmList;
	Date today(14,03,2020);
	Date dateOfFilm;
	Time timeOfStart;
	std::string title;
	int noOfHall;
	std::string zone;
	int numberOfPlaces;
	int id;
	int choice;
	Cinema cinema;
	bool isCinemaWork = true;
	cinema.printFilmList(filmList);
	for (int i = 0; i < filmList.size(); i++) {
		std::cout << filmList[i];
	}
	while(isCinemaWork) {
		system("pause");
		system("cls");
		std::cout << "What would you like to do?\n";
		std::cout << "1 - Show film list\t2 - Make order\n3 - Check free places\t4 - Reserve places\n" <<
			"5 - Calculate the cost\t6 - Cancel order\n7 - Print tickets\t8 - Exit\n>> ";
		std::cin >> choice;
		switch (choice) {
			case 1 :
				cinema.printFilmList();
				break;
			case 2 :
				enterNCheckDate(dateOfFilm, today);
				enterNCheckTime(timeOfStart);
				enterNCheckTitle(title, filmList);
				enterNoOfHall(noOfHall);
				enterZone(zone);
				enterNumberOfPlaces(numberOfPlaces);
				cinema.getTicketOffice().makeOrder(dateOfFilm, timeOfStart, title, noOfHall, zone, numberOfPlaces);
				break;
			case 3 :
				enterZone(zone);
				enterNumberOfPlaces(numberOfPlaces);
				cinema.getTicketOffice().checkFreePlaces(numberOfPlaces, zone);
				break;
			case 4 :
				enterNumberOfPlaces(numberOfPlaces);
				cinema.getTicketOffice().reservePlaces(numberOfPlaces);
				break;
			case 5 :
				enterID(id);
				cinema.getTicketOffice().calculateCost(id);
				break;
			case 6 :
				enterID(id);
				cinema.getTicketOffice().cancelOrder(id);
				break;
			case 7 :
				enterID(id);
				cinema.getTicketOffice().printTickets(id);
				break;
			case 8 :
				isCinemaWork = false;
				break;
			default :
				isCinemaWork = false;
				break;
		}

	}


}