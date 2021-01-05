#ifndef LABO6_PERSONDATE_PERSON_H
#define LABO6_PERSONDATE_PERSON_H
#include <string>
#include "Date.h"

class Person {
public:
   Person(std::string l, std::string f, Date d);
   void SortBy(unsigned index);
private:
   const std::string lastName;
   const std::string firstName;
   const Date date;
   const unsigned noId;
   static unsigned nbrePerson;

};

//Init value
unsigned Person::nbrePerson = 0;
enum class PERSON {NO_ID, LASTNAME, FIRSTNAME, DATE};

#endif //LABO6_PERSONDATE_PERSON_H
