#ifndef LABO6_PERSONDATE_PERSON_H
#define LABO6_PERSONDATE_PERSON_H
#include <string>
#include <iomanip>
#include "Date.h"

enum class PERSON {NO_ID, LASTNAME, FIRSTNAME, DATE};
class SortBy;
class FindBy;

class Person {
public:
   Person(std::string l, std::string f, Date d);
   Person(const Person& p);
   ~Person();
   //----getter----/
   static unsigned int nbrePerson();


   Person& operator=(const Person& person);

   friend std::ostream &operator<<(std::ostream &os,const Person p);
private:
   const std::string lastName;
   const std::string firstName;
   const Date date;
   const unsigned noId;
   static unsigned nextId;
   static unsigned nbrePersonAlive;
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
	FindBy(PERSON identifier,const std::string f);
	bool operator() (Person person);

private:
   PERSON identifier;
   const std::string toFind;

};


#endif //LABO6_PERSONDATE_PERSON_H
