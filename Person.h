#ifndef LABO6_PERSONDATE_PERSON_H
#define LABO6_PERSONDATE_PERSON_H
#include <string>
#include "Date.h"

class Person {
public:
   Person(std::string l, std::string f, Date d);

private:
   const std::string lastName;
   const std::string firstName;
   const Date date;
   const unsigned noId;
   static unsigned nbrePerson;

};



#endif //LABO6_PERSONDATE_PERSON_H
