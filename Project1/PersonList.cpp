/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Implementation of the PersonList class, alongside the parsePerson helper function, declared in Personlist.h.
 */

#include "PersonList.h"
#include <fstream>
#include <cstdlib>

using namespace std;

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

	if (type == "student") {      //if the line says that it's a studnet,
		if (columns.size() < 6)   //verify the line is formatted correctly.
			throw runtime_error("not enough columns in: " + line);
		string level = columns[3];
		double gpa = stringToDouble(columns[4]);
		string major = columns[5];
		if (gpa < 0.0 || gpa > 4.0)
			throw runtime_error("GPA out of range");

		// finally, return a new pointer to the student.
		return new Student(name, year, level, gpa, major);
	}

	if (type == "employee")      //if the line says that it's an employee,
	{
		if (columns.size() < 5)  //verify that the line is formatted correctly.
		{
			throw runtime_error("not enough columns in " + line);
		}
		string salaryparam = columns[3]; 
		int durationparam = stringToInt(columns[4]);
		
		// finally, return a new pointer to the employee.
		return new Employee(name, year, salaryparam, durationparam);
	}

	// If we got here, we didn't handle the person type.
	throw runtime_error("unknown person type " + type);
}


PersonList::PersonList(string filename)
{
	ifstream infile;				//attempt to open the file
	infile.open(filename.c_str());

	if (infile.fail() == true) //if the file fails to open,
	{
		
		throw runtime_error("Error: Cannot open the file."); //throw a runtime error!
	}

	string line;
	while (getline(infile, line)) //while the file is still supplying valid lines,
	{
		personlist.push_back(parsePerson(line)); //push back the pointer to the derived object to the array

	}
}

PersonList::PersonList()
{
	//initalize the personlist as empty.
}

void PersonList::printPersons()
{
	cout << "Person list:" << endl;
	for (int i = 0; i < personlist.size(); i++)
	{
		cout << i << ".";			//Print all of the data for each person in an easy-to-read
		personlist[i]->write();		//format.
		cout << "\n";
	}
}
		
void PersonList::printEmployees()
{
	cout << "Employee list:" << endl;
	for (int i = 0; i < personlist.size(); i++)   //for each person in the list,
	{
		Person* personptr = personlist[i];
		Employee* employeeptr = dynamic_cast<Employee*>(personptr);		//if the pointer points to an employee
		if (employeeptr) // (if converted pointer is not NULL; it was downcast successfully),
			{
				cout << i << ".";    
				employeeptr->write();  //cout it!
				cout << "\n";
			}
	}
}
		
		//Print all the data for each relevaant employee in an easy-to-read format. Calls .isEmployee() for each person, and .write() method for each employee.
void PersonList::printStudents()
{
	cout << "Student list:" << endl;
	for (int i = 0; i < personlist.size(); i++)   //for each person in the list,
	{
		Person* personptr = personlist[i];
		Student* studentptr = dynamic_cast<Student*>(personptr);  //if the pointer points to a student
		if (studentptr) // (if converted pointer is not NULL; it was downcast successfully),
			{
				cout << i << ".";
				studentptr->write();  //cout it!
				cout << "\n";
			}
	}
}

		//Print all the data for each relevant student in an easy-to-read format. Calls .isStudent() for each person, and .write() method for each student.
Person* PersonList::findPerson(string personname)
{
	bool notfound = true;
	int index = 0;
	while (notfound && (index < personlist.size())) //until the person is found or the list is exhausted,
	{
		if ((personlist[index]->personName()) == personname )  //if the person's name at that index matches,
		{
			return personlist[index];  //return the pointer to that person.
		}
		index++;
	}
	throw runtime_error("Person not found!");  //if the person can't be found, throw an error to show it.
}

int PersonList::findIndexPerson(string personname)
{
	bool notfound = true;
	int index = 0;
	while (notfound && (index < personlist.size()))  //until the person is found or the list is exhausted,
	{
		if ((personlist[index]->personName()) == personname )  //if the person's name at that index matches,
		{
			return index;  //return the index pointing to that name.
		}
		index++;
	}
	throw runtime_error("Person not found!");  //if it can't be found, throw an error to show it.
}
		
void PersonList::addPerson(Person* givenperson)
{
	personlist.push_back(givenperson);  //push back the given person pointer to the personlist.
}

void PersonList::removePerson(int personindex)
{
	if (personindex >= 0 && personindex < personlist.size())  //if the index is in range of the personlist,
	{
		delete personlist[personindex]; //delete the memory allocated to that person, and
		for (int i = personindex; i < personlist.size()-1; i++) //for each person after,
		{
			personlist[i] = personlist[i+1]; //move them down one to accomodate the absence.
		}
	}
	else  //if the index is out of range,
	{
		throw range_error("Error: person number out of bounds\n\n");  //throw an error that says so.
	}
	personlist.pop_back();  //knowing the method worked succesfully, take off the last person on the list.
}

void PersonList::printPersons(string filename)
{
	ofstream outputfile;
	outputfile.open(filename.c_str());  //open a file with the name specified.
	for (int i = 0; i < personlist.size(); i++)  //for each person in the personlist,
		{
			outputfile << personlist[i]->writeFormatted() << endl;  //output its formatted info to the specified file.
		}
	outputfile.close();   //close the file to save the changes, and
	cout << "Saved " << filename << ".\n";  //say it was saved.
}

int PersonList::sizeOfList() const
{
	return personlist.size();  //return the size of the person list.
}