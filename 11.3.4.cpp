#include<iostream>

struct calendar {
	int day;
	int month;
	int year;
};

void nextDay(calendar&);

int main() {
	calendar date;
	std::cout << "Please enter today's date (dd mm yyyy)\n";
	std::cin >> date.day >> date.month >> date.year;
	std::cout << "Today's date : " << date.day << "." << date.month << "." << date.year << std::endl;
	nextDay(date);
	std::cout << "Tomorrow's date : " << date.day << "." << date.month << "." << date.year << std::endl;
}

void nextDay(calendar& date) {
	++date.day;
	switch (date.month) {
	case 1:case 3: case 5: case 7: case 8: case 10:
		if (date.day == 32) {
			++date.month;
			date.day = 1;
		}
		break;
	case 4: case 6: case 9: case 11:
		if (date.day == 31) {
			++date.month;
			date.day = 1;
		}
		break;
	case 12:
		if (date.day == 32) {
			++date.year;
			date.month = 1;
			date.day = 1;
		}
		break;
	case 2:
		if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0) {
			if (date.day == 30) {
				++date.month;
				date.day = 1;
			}
		}
		else if (date.day == 29) {
			++date.month;
			date.day = 1;
		}
		break;
	}
}
