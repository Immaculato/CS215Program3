#include "PersonList.h"
#include <fstream>
#include <cstdlib>

using namespace std;

// Helper function to parse a line from the person list file.
//
// TODO: adjust this to match your classes, and add support for the
// other type of person.
//
// NOTE: You should cut and paste this function into your PersonList 
// class source file and declare the function prototype in the header
// file.

Person* parsePerson(string line)
{
	vector<string> columns = splitString(line);
	if (columns.size() < 3)
		throw runtime_error("not enough columns in: " + line);

	// Columns 1-3: type, name, and year
	string type = columns[0];
	string name = columns[1];
	int year = stringToInt(columns[2]);
	if (year < 1900 || year > 2014)
			throw runtime_error("year out of range");

	if (type == "student") {
		if (columns.size() < 6)
			throw runtime_error("not enough columns in: " + line);
		string level = columns[3];
		double gpa = stringToDouble(columns[4]);
		string major = columns[5];
		if (gpa < 0.0 || gpa > 4.0)
			throw runtime_error("GPA out of range");

		// Adjust this to match your class name and parameters.
		return new Student(name, year, level, gpa, major);
	}

	if (type == "employee")
	{
		if (columns.size() < 5)
		{
			throw runtime_error("not enough columns in " + line);
		}
		string salaryparam = columns[3]; 
		int durationparam = stringToInt(columns[4]);
		
		return new Employee(name, year, salaryparam, durationparam);
	}

	// TODO: add case for "employee"

	// If we got here, we didn't handle the person type.
	throw runtime_error("unknown person type " + type);
}


PersonList::PersonList(string filename)
{
	ifstream infile;				//attempt to open the file
	infile.open(filename.c_str());

	if (infile.fail() == true) //if the file fails to open,
	{
		
		//throw runtime_error("Error: Cannot open the file."); //throw a runtime error!
		cout << "FILE NOT LOADED; IMPLEMENT AN ERROR HERE!";
	}

	string line;
	int filelineindex = 0;
	while (getline(infile, line)) //while the file is still supplying valid lines,
	{
		vector<string> contentsOfLine;
		contentsOfLine = splitString(line);
		personlist.push_back(parsePerson(line));
	}
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
	cout << "No person was found. Was person name correct?";
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
			Person* persontoremove = personlist[index];
			for (int j = index; j < personlist.size()-2; j++)
			{
				personlist[j] = personlist[j+1];
			}
			personlist[personlist.size()-1] = persontoremove;
			personlist.pop_back();
			return;
		}
		index++;
	}
	cout << "Nothing was removed. Was person in list?";
}
		//Remove a given person from the personlist.