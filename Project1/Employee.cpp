/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Implementation of the Employee class.
 */

#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Employee::Employee(string nameparam, int yearofbirthparam, string salaryparam, int durationparam) : Person(nameparam,
																							  yearofbirthparam)
{
	salary = salaryparam;			//initialize the parameters of employee with the default Person constructor,
	duration = durationparam;		//and the actual datamembers specified by the user for salary and duration.
}

Employee::~Employee()
{
}

string Employee::getSalary() const
{
	return salary; //Return the salary amount of the employee
}
	
int Employee::getDuration() const
{
	return duration; //return the duration of the employee
}

void Employee::write() const
{
	cout << " " << personName() << ":\n   Year of birth: " << personYear() << "\n   Salary: " << salary 
		<< "\n   Duration of employment: " << duration << endl;
	//output the datamembers relevant to the employee in rows so that is readable and nice to look at
}

		

string Employee::writeFormatted() const
{
	string formattedstring = "employee#" + personName() + "#" + to_string(personYear()) + "#" + salary + "#"
		+ to_string(duration);  //concatenate the formatted string so that it can be used with the program, and
	return formattedstring;		//return it.
}