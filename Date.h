#ifndef LABO6_PERSONDATE_DATE_H
#define LABO6_PERSONDATE_DATE_H
#include <string>


class Date {
public:
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


#endif //LABO6_PERSONDATE_DATE_H
