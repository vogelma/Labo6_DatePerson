//
// Created by Maëlle on 04.01.2021.
//
#include "Person.h"
Person::Person(std::string l, std::string f, Date d) : lastName(l), firstName(f), date(d), noId(++nbrePersonActif) {
	++nbre_Person;
}
//Init value
unsigned Person::nbrePersonActif = 0;
enum class PERSON {NO_ID, LASTNAME, FIRSTNAME, DATE};

unsigned int Person::nbrePerson() {
return nbre_Person;
}

