/*-------------------------------------------------------------------------------
 Laboratoire   : 07 - Person / Date
 Fichier       : Person.h
 Auteur(s)     : Maelle Vogel, Amandine Gainville
 Date          : 04.01.2021
 But           : Set of functions - header

 Remarque(s)   : Error management is assured

 Compilateur   : MinGW-g++ 4.6.2
 -------------------------------------------------------------------------------*/
#ifndef LABO6_PERSONDATE_PERSON_H
#define LABO6_PERSONDATE_PERSON_H
#include <string>
#include <iomanip> //setw
#include "Date.h" //used for Date in Person, SortBy, FindBy

//the enum class is declared outside the class so that it can be used in each class.
enum class PERSON {NO_ID, LASTNAME, FIRSTNAME, DATE};
class SortBy;
class FindBy;


//*************** class Person ***************
class Person {
public:
   Person(std::string l, std::string f, Date d);
   Person(const Person& p);

   //----Destructor----/
	//to delete a person
   ~Person();

   //function to count the number of people
   static unsigned int nbrePerson();

   //----Operator=----/
	//to assign identifiers from one person to another
   Person& operator=(const Person& person);

	//function friend : operator<<
   //to display the person's idientifiers
   friend std::ostream &operator<<(std::ostream &os,const Person p);

private:
   const std::string lastName;
   const std::string firstName;
   const Date date;
   const unsigned noId;

   //Used for nbrePerson
   static unsigned nextId;
   static unsigned nbrePersonAlive;

   //class friend
   friend SortBy;
   friend FindBy;
};
//*************** end class Person ***************


//*************** class SortBy     ***************
class SortBy{
public:
	SortBy(PERSON identifier);
	//----operator()---//
   //to compare people and sort them in ascending order
	bool operator() (const Person& person1, const Person& person2);

private:
   PERSON identifier;

};
//*************** end class SortBy ***************


//*************** class FindBy     ***************
class FindBy{
public:
	FindBy(PERSON identifier,const std::string f);

	//----operator()---//
   //to find a person among the requested identifier
	bool operator() (Person person);

private:
   PERSON identifier;
   const std::string toFind;

};
//*************** end class FindBy ***************

#endif //LABO6_PERSONDATE_PERSON_H
