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
    int pos = d.find("-");
    std::string strday(d, 0, pos);
    std::string strmonth(d, pos + 1, 2);
    std::string stryear(d, pos + 4);

    day = std::stoi(strday);
    month = std::stoi(strmonth);
    year = std::stoi(stryear);
    correct = isValid();

}

Date::Date(Date const &dateUser) {
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


Month Date::getMonthEnum() const {
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

std::ostream &operator<<(std::ostream &os, const Date &dateDisplay) {
    if (dateDisplay.isValid()) {

        std::cout << Date::showDate(dateDisplay.getDay()) << "-" << Date::showDate(dateDisplay.getMonthNo()) << "-"
                  << dateDisplay.getYear();
    } else {
        std::cout << "Invalide Date";
    }
    return os;
}
//--------------------greater and smaller---------------------//
bool Date::operator<(Date date2) {
    if (!(this->isValid()) || !(date2.isValid())) {
        return false;
    }
    if (this->year < date2.year) {
        return true;
    }
    if (this->month < date2.month) {
        return true;
    }
    if (this->day < date2.day) {
        return true;
    }
    return false;
}

bool Date::operator>(Date date2) {
    if (!(this->isValid()) || !(date2.isValid())) {
        return false;
    }
    if (this->year > date2.year) {
        return true;
    }
    if (this->month > date2.month) {
        return true;
    }
    if (this->day > date2.day) {
        return true;
    }

    return false;
}
//-------------------greater or equal and smaller or equal-------------------//
bool Date::operator<=(Date date2) {
    if (!(this->isValid()) || !(date2.isValid())) {
        return false;
    }
    if (*this < date2 || *this == date2) {
        return true;
    } else {
        return false;
    }
}

bool Date::operator>=(const Date& date2) {
    if (!(this->isValid()) || !(date2.isValid())) {
        return false;
    }
    if (*this > date2 || *this == date2) {
        return true;
    } else {
        return false;
    }
}

//-------------------equal--------------------//
bool Date::operator==(const Date& date2) {
    if (!(this->isValid()) || !(date2.isValid())) {
        return false;
    }
    if (this->day == date2.day && this->month == date2.month && this->year == date2.year) {
        return true;
    }

    return false;
}
//-----------------add and sub---------------//
Date Date::operator+(unsigned d) {
    if (!(isValid())) {
        return *this;
    }
    Date dateReturn(*this);
    for (unsigned i = 0; i < d; ++i) {
        (++dateReturn);
    }
    return dateReturn;
}

Date operator+(unsigned d, Date date1){
    if (!(date1.isValid())) {
        return date1;
    }
    Date dateReturn(date1);
    return (dateReturn + d);
}

Date Date::operator-(unsigned d) {
    if (!(isValid())) {
        return *this;
    }
    Date dateReturn(*this);
    for (unsigned i = 0; i < d; ++i) {
        --dateReturn;
    }
    return dateReturn;
}
//--------------increment and decrement-------------------//
Date Date::operator++() {
    if (!(isValid())) {
        return *this;
    }

    if (day == numberDaysInMonth()) {
        if (month == (unsigned) Month::DECEMBER) {
            ++year;
            month = (unsigned) Month::JANUARY;
            day = 1;
        } else {
            ++month;
            day = 1;
        }
    } else {
        ++day;
    }

    return *this;
}

Date Date::operator--() {
    if (!(isValid())) {
        return *this;
    }

    if (day == 1) {
        if (month == (unsigned) Month::JANUARY) {
            --year;
            month = (unsigned) Month::DECEMBER;
            day = numberDaysInMonth();
        } else {
            --month;
            day = numberDaysInMonth();
        }
    } else {
        --day;
    }

    return *this;
}

//post-incrementation
Date Date::operator++(int i){
    Date temp = *this;
    ++*this;
    return temp;
}


Date Date::operator--(int i){
    Date temp = *this;
    --*this;
    return temp;
}

std::string Date::showDate(unsigned i){
    std::string sortie = std::to_string(i);

    if(i < 10){
        sortie.insert(0, "0");
    }
    return sortie;
}
