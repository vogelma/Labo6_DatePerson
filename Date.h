#ifndef LABO6_PERSONDATE_DATE_H
#define LABO6_PERSONDATE_DATE_H

#include <string>


class Date {
public:
   Date(unsigned d = 1, unsigned m = 1, unsigned y = 1900);
   Date(std::string n);

   enum class Month {
      JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
   };

   unsigned getDay();
   unsigned getMonthNo();
   unsigned getMonthEnum();
   unsigned getYear();
   std::string getMonthString();
   void setDay(unsigned d);
   void setMonth(unsigned m);
   void setMonth(std::string m);
   void setMonth(Month m);
   void setYear(unsigned y);
   bool isValid();
   bool isLeapYear();
   unsigned numberDaysInMonth();


   static bool isValid(unsigned d, unsigned m, unsigned y);
   static bool isLeapYear(unsigned y);
   static unsigned numberDaysInMonth(unsigned m, unsigned y);

private:
   unsigned day,
      month,
      year;
   bool correct = true;
};



#endif //LABO6_PERSONDATE_DATE_H
