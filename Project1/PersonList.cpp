#include "PersonList.h"

using namespace std;


PersonList::PersonList(string filename)
{
	//PARSE DAT SHIT
}
		//Initialize the personlist by parsing information from a given file.
PersonList::PersonList()
{
}

		//Initialize the personlist as completely empty.
void PersonList::printPersons()
{
	for (int i = 0; i < personlist.size(); i++)
	{
		personlist[0]->write();
	}
}
		//Print all of the data for each relevant person in an easy-to-read format. Calls .write() method for each person.
void PersonList::printEmployees()
{
	for (int i = 0; i < personlist.size(); i++)
	{
		Person* personptr = personlist[i];
		Employee* employeeptr = dynamic_cast<Employee*>(personptr);
		if (employeeptr) // if converted pointer is not NULL
			{
				employeeptr->write();
			}
	}
}
		
		//Print all the data for each relevaant employee in an easy-to-read format. Calls .isEmployee() for each person, and .write() method for each employee.
void PersonList::printStudents()
{
	for (int i = 0; i < personlist.size(); i++)
	{
		Person* personptr = personlist[i];
		Student* studentptr = dynamic_cast<Student*>(personptr);
		if (studentptr) // if converted pointer is not NULL
			{
				studentptr->write();
			}
	}
}

		//Print all the data for each relevant student in an easy-to-read format. Calls .isStudent() for each person, and .write() method for each student.
Person PersonList::findPerson(string personname)
{
	bool notfound = true;
	int index = 0;
	while (notfound && (index < personlist.size()))
	{
		if ((personlist[index]->personName()) == personname )
		{
			return *personlist[index];
		}
		index++;
	}
}
	
		//Search for a person with the given string name in the vector of persons. If found, return the person object corresponding to the given person name. Uses .personName() method to find the name of each person.
void PersonList::addPerson(Person givenperson)
{
	Person* personptr = new Person;
	//make a new pointer to a person
	personptr = &givenperson;
	//deepcopy the given pointer
	personlist.push_back(personptr);
	//push it back to the list
}
		//Push back a given person to the personlist.
void PersonList::removePerson(Person givenperson)
{
	bool notfound = true;
	int index = 0;
	while (notfound && (index < personlist.size()))
	{
		if ((personlist[index]->personName() == givenperson.personName()) && 
			(personlist[index]->personYear() == givenperson.personYear()))
		{
			
		}
		index++;
	}
}
		//Remove a given person from the personlist.