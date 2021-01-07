/*-------------------------------------------------------------------------------
 Laboratoire   : 07 - Person / Date
 Fichier       : Person.cpp
 Auteur(s)     : Maelle Vogel, Amandine Gainville
 Date          : 04.01.2021
 But           : Set of functions : define a person with identifiers (last name, first name, date, ID),
                 compare people and find a person with an identifier

 Remarque(s)   : Error management is assured

 Compilateur   : MinGW-g++ 4.6.2
 -------------------------------------------------------------------------------*/
#include "Person.h"

//*************** class Person ***************

//Init value
unsigned Person::nbrePersonAlive = 0;
unsigned Person::nextId = 0;

//--constructor---//
Person::Person(std::string l, std::string f, Date d) : lastName(l), firstName(f), date(d), noId(++nextId) {++nbrePersonAlive;}
Person::Person(const Person& p): lastName(p.lastName), firstName(p.firstName), date(p.date), noId(p.noId){ ++nbrePersonAlive;}

//---destructor---//
//to delete a person
Person::~Person(){--nbrePersonAlive;}

//function to count the number of people
unsigned int Person::nbrePerson() {
    return nbrePersonAlive;
}

//----operator=---//
//to assign identifiers from one person to another
Person& Person::operator=(const Person& person) {
    if(this != &person) {
        (std::string&) lastName = person.lastName;
        (std::string&) firstName = person.firstName;
        (Date&) date = person.date;
        (unsigned&) noId = person.noId;
    }
    return *this;
}

//----operator<<---//
//to display the person's idientifiers
std::ostream &operator<<(std::ostream &os, const Person p){
    const unsigned W = 17;
    os << std::fixed << std::left << std::setw(W) << p.lastName + " " + p.firstName
                                                  << p.date << " (id=" << p.noId << ")";
    return os;
}
//*************** end class Person ***************


//*************** class SortBy     ***************

SortBy::SortBy(PERSON identifier) {
    this->identifier = identifier;
}

//----operator()---//
//to compare people and sort them in ascending order
bool SortBy::operator()(const Person& person1, const Person& person2) {
    switch (identifier) {
        case PERSON::LASTNAME :
            return person1.lastName < person2.lastName;

        case PERSON::FIRSTNAME :
            return person1.firstName < person2.firstName;

        case PERSON::DATE :
            return person1.date < person2.date ;

        case PERSON::NO_ID :
            return person1.noId < person2.noId;

    }
}
//*************** end class SortBy ***************


//*************** class FindBy     ***************

FindBy::FindBy(PERSON identifier,const std::string f): toFind(f){
    this->identifier = identifier;
}

//----operator()---//
//to find a person among the requested identifier
bool FindBy::operator()(Person person) {
    switch (identifier) {
        case PERSON::LASTNAME :
            return (toFind == person.lastName);

        case PERSON::FIRSTNAME :
            return (toFind == person.firstName);

        case PERSON::DATE :
            return (toFind == std::string(person.date));

        case PERSON::NO_ID :
            return (std::stoi(toFind) == person.noId);

    }
}
//*************** end class FindBy ***************
