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

Date::Date(std::string) {
    //to do
}

unsigned Date::getDay() {
    return day;
}

unsigned Date::getMonthNo() {
    return month;
}

unsigned Date::getYear() {
    return year;
}


unsigned Date::getMonthEnum() {

}

std::string Date::getMonthString() {
    return months[month];
}

void Date::setDay(unsigned d) {
    day = d;
}

void Date::setMonth(unsigned m) {
    month = m;
}

//update with string
void Date::setMonth(std::string m) {
    for (size_t i = (size_t) Month::JANUARY; i < (size_t) Month::DECEMBER; ++i) {
        if (months[i] == m) {
            month = i;
        }
    }
}

//update with enum
void Date::setMonth(Month m) {
    month = (unsigned int) m;
}

void Date::setYear(unsigned y) {
    year = y;
}

bool Date::isValid() {
    return isValid(day, month, year);
}

bool Date::isLeapYear() {
    return isLeapYear(year);
}

unsigned Date::numberDaysInMonth() {
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
