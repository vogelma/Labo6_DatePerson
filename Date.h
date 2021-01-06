#ifndef LABO6_PERSONDATE_DATE_H
#define LABO6_PERSONDATE_DATE_H

#include <string>
#include <iostream>

//Enum class en dehors de la class Date car dans le main.cpp la ligne 58 et 126 ne comprend pas
//le mois et voudrait plutot "Date::Month" mais comme on peut pas modifier le main je l'ai mis dehors
enum class Month {
	JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class Date {
public:
   Date(unsigned d = 1, unsigned m = 1, unsigned y = 1900);
   Date(Date const &dateUser);
   Date(std::string n);


   unsigned getDay() const;
   unsigned getMonthNo() const;
   unsigned getMonthEnum();
   unsigned getYear() const;
   std::string getMonthString() const;
   void setDay(unsigned d);
   void setMonth(unsigned m);
   void setMonth(std::string m);
   void setMonth(Month m);
   void setYear(unsigned y);
   bool isValid() const;
   bool isLeapYear() const;
   unsigned numberDaysInMonth() const;

   friend std::ostream &operator<<(std::ostream &os, const Date& dateDisplay);
   friend bool operator<(Date date1, Date date2);
   friend bool operator>(Date date1, Date date2);
   friend bool operator<=(Date date1, Date date2);
   friend bool operator>=(Date date1, Date date2);
   friend bool operator==(Date date1, Date date2);
   friend Date operator+(Date date1, unsigned d);
   friend Date operator+(unsigned d, Date date1);
   friend Date operator-(Date date1, unsigned d);
   friend Date operator++(Date date1);
   friend Date operator--(Date date1);
   friend Date operator+=(Date date1, unsigned d);
   friend Date operator-=(Date date1, unsigned d);

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
