//
// Created by Maëlle on 04.01.2021.
//
#include "Person.h"
Person::Person(std::string l, std::string f, Date d) : lastName(l), firstName(f), date(d), noId(++nbrePerson) {}
//Init value
unsigned Person::nbrePerson = 0;
enum class PERSON {NO_ID, LASTNAME, FIRSTNAME, DATE};