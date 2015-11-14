#include <iostream>
#include <vector>
#include <stdexcept>
#include "Person.h"

using namespace std;

class PersonList
{
public:
	PersonList(string filename);
		//Initialize the personlist by parsing information from a given file.
	PersonList();
		//Initialize the personlist as completely empty.
	void printPersons();
		//Print all of the data for each relevant person in an easy-to-read format. Calls .write() method for each person.
	void printEmployees();
		//Print all the data for each relevaant employee in an easy-to-read format. Calls .isEmployee() for each person, and .write() method for each employee.
	void printStudents();
		//Print all the data for each relevant student in an easy-to-read format. Calls .isStudent() for each person, and .write() method for each student.
	Person findPerson(string personname);
		//Search for a person with the given string name in the vector of persons. If found, return the person object corresponding to the given person name. Uses .personName() method to find the name of each person.
	void addPerson(Person givenperson);
		//Push back a given person to the personlist.
	void removePerson(Person givenperson);
		//Remove a given person from the personlist.
private:
	vector<Person*> personlist; //create a vector to hold the pointers to the people.
};