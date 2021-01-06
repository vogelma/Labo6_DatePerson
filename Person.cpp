//
// Created by Maëlle on 04.01.2021.
//
#include "Person.h"
Person::Person(std::string l, std::string f, Date d) : lastName(l), firstName(f), date(d), noId(++nbrePersonActif) {
	++nbre_Person;
}
//Init value
unsigned Person::nbrePersonActif = 0;

unsigned int Person::nbrePerson() {
return nbre_Person;
}

bool SortBy::operator() (const Person& person1, const Person& person2){
	switch(identifier){
		case PERSON::LASTNAME : return person1.lastName < person2.lastName; break;
		case PERSON::FIRSTNAME : return person1.firstName < person2.firstName; break;
		case PERSON::DATE : return person1.date < person2.date ; break;
		case PERSON::NO_ID : return person1.noId < person2.noId ; break;
	}
}