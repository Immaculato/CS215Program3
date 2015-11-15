#ifndef Employee_H
#define Employee_H

#include "Person.h"
#include <vector>
#include <string>

using namespace std;

class Employee : public Person
{
public:
	Employee(string nameparam, int yearofbirthparam, string salaryparam, int durationparam);
	~Employee();
			//Create an employee with the given int salary and int duration. Sets employee_status to True.
	string getSalary() const;
			//Return the int salary amount of the employee as a string.
	int getDuration() const;
			//Return the int amount of time in months the employee has been employed.
	virtual void write() const;
		//Rather than just print the employees name and year, this override will print those, with the employee's salary and duration.
	virtual string writeFormatted() const;
		//Rather than just write the employees name and year, this override will print those, with the employee's salary and duration.
private:
	string salary;
	int duration;
};

#endif