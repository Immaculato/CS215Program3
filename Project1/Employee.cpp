#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Employee::Employee(string nameparam, int yearofbirthparam, string salaryparam, int durationparam) : Person(nameparam,
																							  yearofbirthparam)
{
	salary = salaryparam;
	duration = durationparam;
}

Employee::~Employee()
{
}

			//Create an employee with the given int salary and int duration.
string Employee::getSalary() const
{
	return salary;
}

			//Return the int salary amount of the employee as a string.
int Employee::getDuration() const
{
	return duration;
}

			//Return the int amount of time in months the employee has been employed.
void Employee::write() const
{
	cout << " " << personName() << ":\n   Year of birth: " << personYear() << "\n   Salary: " << salary 
		<< "\n   Duration of employment: " << duration << endl;

}

		//Rather than just print the employees name and year, this override will print those, with the employee's salary and duration.

string Employee::writeFormatted() const
{
	string formattedstring = "employee#" + personName() + "#" + to_string(personYear()) + "#" + salary + "#"
		+ to_string(duration);
	return formattedstring;
}