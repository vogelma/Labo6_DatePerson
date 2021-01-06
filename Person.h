#ifndef LABO6_PERSONDATE_PERSON_H
#define LABO6_PERSONDATE_PERSON_H
#include <string>
#include "Date.h"


class Person {
public:
   Person(std::string l, std::string f, Date d);
	static unsigned int nbrePerson();
private:
   const std::string lastName;
   const std::string firstName;
   const Date date;
   const unsigned noId;
   static unsigned nbrePersonActif;
	static unsigned int nbre_Person;
	friend std::ostream& operator<<(std::ostream&, const Person& person);

};

class SortBy{
public:

private:

};

class FindBy{
public:

private:

};


#endif //LABO6_PERSONDATE_PERSON_H
