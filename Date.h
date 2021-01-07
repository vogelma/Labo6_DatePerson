#ifndef LABO6_PERSONDATE_DATE_H
#define LABO6_PERSONDATE_DATE_H

#include <string>
#include <iostream>


enum class Month {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

class Date {
public:
   //constructor
   //with default value
   Date(unsigned d = 1, unsigned m = 1, unsigned y = 1900);
   //by copy
   Date(Date const &dateUser);
   //with a string
   Date(std::string n);

   //----getter----/
   unsigned getDay() const;
   unsigned getMonthNo() const;
   unsigned getYear() const;
   Month getMonthEnum() const;
   //return the month name
   std::string getMonthString() const;

   //----setter----//
   void setDay(unsigned d);
   void setMonth(unsigned m);
   void setMonth(std::string m);
   void setMonth(Month m);
   void setYear(unsigned y);

   //Is a date valid?
   //return true if valid
   //       false if not
   bool isValid() const;

   //Is a year leap?
   //return true a year is leap
   //       false if not
   bool isLeapYear() const;

   //Returns the number of day in a month
   unsigned numberDaysInMonth() const;

   //---operator overload---//
   bool operator<(Date date2) const;
   bool operator>(Date date2) const;
   bool operator<=(Date date2) const;
   bool operator>=(Date date2) const;
   bool operator==(Date date2) const;

   //add and sub overload
   Date operator+(unsigned d);
   Date operator-(unsigned d);

   //++x and --x
   Date operator++();
   Date operator--();

   //x++ and x--
   Date operator++(int i);
   Date operator--(int i);

   //add or sub a number of days
   Date operator+=(unsigned d);
   Date operator-=(unsigned d);

   friend Date operator+(unsigned d, Date date1);

   //cast a date in string
   explicit operator std::string() const;

   //overload operator << for display a date dd-mm-yyyy
   friend std::ostream &operator<<(std::ostream &os, const Date& dateDisplay);

   //static functions
   static bool isValid(unsigned d, unsigned m, unsigned y);
   static bool isLeapYear(unsigned y);
   static unsigned numberDaysInMonth(unsigned m, unsigned y);

   //returns a string which contains a number with two digit (3 -> 03)
   static std::string showDate(unsigned i);

private:
   unsigned day,
            month,
            year;
   bool correct = true;
};



#endif //LABO6_PERSONDATE_DATE_H
