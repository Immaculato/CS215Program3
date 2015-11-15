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
	name = nameparam;
	yearofbirth = yearofbirthparam;
}

Person::~Person()
{
}

		//Create a person with a given string name and a given int year of birth.
string Person::personName() const
{
	return name;
}

		//Return the name of the person.
int Person::personYear() const
{
	return yearofbirth;
}

		//Return the int year of birth of the person.
void Person::write() const
{
	cout << "Person Class: Name=" << name << " Yearofbirth=" << yearofbirth << endl;
}

		//Print the given person's name and year of birth to standard output stream.

string Person::writeFormatted() const
{
	string junkstring = "you better not be seeing this";
	return junkstring;
}