//
// Created by Maëlle on 04.01.2021.
//

#include "Date.h"


const std::string months[] = {"error", "January", "February", "March", "April", "May", "June", "July", "August",
                              "September",
                              "October", "November", "December"};

Date::Date(unsigned d, unsigned m, unsigned y) {
    day = d;
    month = m;
    year = y;
    correct = isValid();
}

Date::Date(std::string d) {
   int pos =  d.find("-");
   std::string strday(d, 0, pos);
   std::string strmonth(d, pos + 1, 2);
   std::string stryear(d, pos + 4);

   day = std::stoi (strday);
   month = std::stoi (strmonth);
   year = std::stoi (stryear);
   correct = isValid();

}

Date::Date(Date const &dateUser){
    day = dateUser.getDay();
    month = dateUser.getMonthNo();
    year = dateUser.getYear();
    correct = isValid();
}

unsigned Date::getDay() const {
    return day;
}

unsigned Date::getMonthNo() const {
    return month;
}

unsigned Date::getYear() const {
    return year;
}


Month Date::getMonthEnum() {
    return Month(month);
}

std::string Date::getMonthString() const {
    return months[month];
}

void Date::setDay(unsigned d) {
    day = d;
    correct = isValid();
}

void Date::setMonth(unsigned m) {
    month = m;
    correct = isValid();
}

//update with string
void Date::setMonth(std::string m) {
    for (size_t i = (size_t) Month::JANUARY; i < (size_t) Month::DECEMBER; ++i) {
        if (months[i] == m) {
            month = i;
        }
    }
    correct = isValid();
}

//update with enum
void Date::setMonth(Month m) {
    month = (unsigned int) m;
    correct = isValid();
}

void Date::setYear(unsigned y) {
    year = y;
    correct = isValid();
}

bool Date::isValid() const {
    return isValid(day, month, year);
}

bool Date::isLeapYear() const {
    return isLeapYear(year);
}

unsigned Date::numberDaysInMonth() const {
    return numberDaysInMonth(month, year);
}

bool Date::isValid(unsigned d, unsigned m, unsigned y) {
    if (d > numberDaysInMonth(m, y)) {
        return false;
    }
    if ((Month) m > Month::DECEMBER) {
        return false;
    }

    return true;
}

bool Date::isLeapYear(unsigned y) {
    return y % 4 == 0 and (y % 100 != 0 or y % 400 == 0);
}

unsigned Date::numberDaysInMonth(unsigned m, unsigned y) {
    if ((Month) m == Month::FEBRUARY) {
        return isLeapYear(y) ? 29 : 28;
    } else if ((Month) m == Month::APRIL || (Month) m == Month::JUNE || (Month) m == Month::SEPTEMBER ||
               (Month) m == Month::NOVEMBER) {
        return 30;
    } else {
        return 31;
    }
}

std::ostream &operator<<(std::ostream &os, const Date& dateDisplay) {
    if(dateDisplay.isValid()) {

        std::cout << Date::showDate(dateDisplay.getDay()) << "-" << Date::showDate(dateDisplay.getMonthNo()) << "-" << dateDisplay.getYear();
    }
    else{
        std::cout << "Invalide Date";
    }
    return os;
}

bool operator<(Date date1, Date date2){
    if(!(date1.isValid()) || !(date2.isValid())) {
        return false;
    }
    //version compacte
    if((date1.year < date2.year) || (date1.year == date2.year && date1.month < date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day))
	 {
    	return true;
	 }
    else return false;
    /*
   //Version non compacte
	if (date1.year < date2.year)
	{
		return true;
	}
	else if(date1.year == date2.year && date1.month < date2.month )
	{
		return true;
	}
	else if(date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)
	{
		return true;
	}
	else return false;
   */
}
bool operator>(Date date1, Date date2){
    if(!(date1.isValid()) || !(date2.isValid())) {
        return false;
    }
    if(!(date1 == date2))
	 {
		 return !(date1 < date2);
	 }
    else return false;

}
bool operator<=(Date date1, Date date2){
    if(!(date1.isValid()) || !(date2.isValid())) {
        return false;
    }
}
bool operator>=(Date date1, Date date2){
    if(!(date1.isValid()) || !(date2.isValid())) {
        return false;
    }
}
bool operator==(Date date1, Date date2){
    if(!(date1.isValid()) || !(date2.isValid())) {
        return false;
    }
}
Date operator+(Date date1, unsigned d){
    if(!(date1.isValid())) {
        return date1;
    }
}
Date operator+(unsigned d, Date date1){
    if(!(date1.isValid())) {
        return date1;
    }
}
Date operator-(Date date1, unsigned d){
    if(!(date1.isValid())) {
        return date1;
    }
}

Date operator++(Date date1){
    if(!(date1.isValid())) {
        return date1;
    }
}
Date operator--(Date date1){
    if(!(date1.isValid())) {
        return date1;
    }
}
Date operator+=(Date date1, unsigned d){
    if(!(date1.isValid())) {
        return date1;
    }
}
Date operator-=(Date date1, unsigned d){
    if(!(date1.isValid())) {
        return date1;
    }
}

std::string Date::showDate(unsigned i){
    std::string sortie = std::to_string(i);

    if(i < 10){
        sortie.insert(0, "0");
    }
    return sortie;
}
