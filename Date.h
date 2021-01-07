#ifndef LABO6_PERSONDATE_DATE_H
#define LABO6_PERSONDATE_DATE_H

#include <string>
#include <iostream>

//Enum class en dehors de la class Date car dans le main.cpp la ligne 58 et 126 ne comprend pas
//le mois et voudrait plutot "Date::Month" mais comme on peut pas modifier le main je l'ai mis dehors
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
   //--constructor----//
   Date(unsigned d = 1, unsigned m = 1, unsigned y = 1900);
   Date(Date const &dateUser);
   Date(std::string n);

//----getter----/
   unsigned getDay() const;
   unsigned getMonthNo() const;
   Month getMonthEnum() const;
   unsigned getYear() const;
   std::string getMonthString() const;
//----setter----//
   void setDay(unsigned d);
   void setMonth(unsigned m);
   void setMonth(std::string m);
   void setMonth(Month m);
   void setYear(unsigned y);
//---utility----//
   bool isValid() const;
   bool isLeapYear() const;
   unsigned numberDaysInMonth() const;

//---operator---//
   bool operator<(Date date2) const;
   bool operator>(Date date2) const;
   bool operator<=(Date date2) const;
   bool operator>=(Date date2) const;
   bool operator==(Date date2) const;

   Date operator+(unsigned d);
   Date operator-(unsigned d);

   //++x and --x
   Date operator++();
   Date operator--();
   //x++ and x--
   Date operator++(int i);
   Date operator--(int i);

   //increment and decrement
   Date operator+=(unsigned d);
   Date operator-=(unsigned d);

   friend Date operator+(unsigned d, Date date1);

   explicit operator std::string() const;
   friend std::ostream &operator<<(std::ostream &os, const Date& dateDisplay);

   static bool isValid(unsigned d, unsigned m, unsigned y);
   static bool isLeapYear(unsigned y);
   static unsigned numberDaysInMonth(unsigned m, unsigned y);
   static std::string showDate(unsigned i);

private:
   unsigned day,
      month,
      year;
   bool correct = true;
};



#endif //LABO6_PERSONDATE_DATE_H
