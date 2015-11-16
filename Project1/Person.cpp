/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Implementation of the Person class.
 */

#include "Person.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


Person::Person()
{
}

Person::Person(string nameparam, int yearofbirthparam)
{
	name = nameparam;  //create a person and set the data members to the specified parameters of the user
	yearofbirth = yearofbirthparam;
}

Person::~Person()
{
}


string Person::personName() const
{
	return name;  //Return the name of the person.
}

		
int Person::personYear() const
{
	return yearofbirth;  //Return the int year of birth of the person.
}

		
void Person::write() const
{
	cout << "Person Class: Name=" << name << " Yearofbirth=" << yearofbirth << endl;
	//Print the given person's name and year of birth to standard output stream.
}

		

string Person::writeFormatted() const
{
	string junkstring = "you better not be seeing this";
	return junkstring;
	//output a string that says that this shouldn't be getting called.
}