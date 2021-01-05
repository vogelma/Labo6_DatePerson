#ifndef LABO6_PERSONDATE_DATE_H
#define LABO6_PERSONDATE_DATE_H

#include <string>


class Date {
public:
   Date(unsigned d = 1, unsigned m = 1, unsigned y = 1900);
   Date(std::string n);

   unsigned getDay();

   unsigned getMonthNo();

   //enum avec mois
   unsigned getMonthEnum();

   std::string getMonthString();

   unsigned getYear();

private:
   unsigned day,
      month,
      year;
   bool correct = true;
};

enum class MONTHS {
   JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};
const std::string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                              "October", "November", "December"};

#endif //LABO6_PERSONDATE_DATE_H
