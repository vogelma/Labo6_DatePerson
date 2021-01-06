#ifndef LABO6_PERSONDATE_PERSON_H
#define LABO6_PERSONDATE_PERSON_H
#include <string>
#include "Date.h"

enum class PERSON {NO_ID, LASTNAME, FIRSTNAME, DATE};
class SortBy;
class FindBy;

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
	friend SortBy;
	friend FindBy;



};

class SortBy{
public:
	SortBy(PERSON identifier);
	bool operator() (const Person& person1, const Person& person2);

private:
   PERSON identifier;

};

class FindBy{
public:
	FindBy(PERSON identifier, const std::string string);

private:
   PERSON identifier;
	const std::string string;

};


#endif //LABO6_PERSONDATE_PERSON_H
