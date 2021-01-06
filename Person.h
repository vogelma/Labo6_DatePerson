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
	static unsigned int nbre_Person;
	friend std::ostream& operator<<(std::ostream&, const Person& person);
	friend SortBy;
	friend FindBy;


};

class SortBy{
public:
	PERSON identifier;
private:
	SortBy(PERSON identifier);
	bool operator() (const Person& person1, const Person& person2);
	}
};

class FindBy{
public:
	PERSON identifier;
private:
	FindBy(PERSON identifier);
};


#endif //LABO6_PERSONDATE_PERSON_H
