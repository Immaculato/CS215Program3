/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Employee header
 */

#ifndef Employee_H
#define Employee_H

#include "Person.h"
#include <vector>
#include <string>

using namespace std;

class Employee : public Person
{
public:

	/* Employee(string nameparam, int yearofbirth, string salaryparam, int durationparam)
	 *		- Constructor for an Employee
	 *
	 * Description: 
	 *   Take in a name, year, salary, and duration and initialize an employee with those data members.
	 *
	 * Inputs:
	 *   string name, integer year of birth, string salary, and integer duration of employment.
	 *
	 * Outputs:
	 *   An initialized Employee with specified parameters.
	 *
	 * Side-effects:
	 *  None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Inherits data members from Person.
	 */
	Employee(string nameparam, int yearofbirthparam, string salaryparam, int durationparam);

	/* ~Employee() - Destructor for employee.
	 *
	 * Description: 
	 *   Default destructor for a Employee class object.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *  Deletes the Employee pointer object, and after, its respective pointer as an inherited Person when called
	 *  upon.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Virtual function destructor of Person class. Will call Person class destructor just after calling this one.
	 */
	~Employee();

	/* string getSalary() const - Accessor to salary of employee: returns salary of the employee as a string.
	 *
	 * Description: 
	 *   Accessor to the salary of the employee as a string.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   Returns the salary of the employee as a string.
	 *
	 * Side-effects:
	 *  None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	string getSalary() const;
	
	/* integer getDuration() const - Accessor to duration of employee: returns duration of the employee as an integer.
	 *
	 * Description: 
	 *   Accessor to the duration of the employee as an integer.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   Returns the duration of the employee as an integer.
	 *
	 * Side-effects:
	 *  None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	int getDuration() const;
	
	/*virtual void write() const - Print Employee data members to standard output (formatted in rows)
	 *
	 * Description: 
	 *   Prints an Employee's data members to standard output.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *  Prints the Employee's data members to standard output (name, year, salary, duration) 
	 *  formatted in a row system with a new line after each row.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Includes a space at the beginning to put the number of the object in the PersonList vector data member.
	 *   Override of Person's write function.
	 */
	virtual void write() const;
	
	/*virtual string writeFormatted() const - Return database-form string of Employee data members
	 *
	 * Description: 
	 *   Returns the database-formatted data members of the Employee, with #'s between them.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   String of formatted data members with #'s between them.
	 *
	 * Side-effects:
	 *  None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Prints the data members of the employee formatted such that it can be inserted directly into a new file,
	 *   which can be saved and accessed by the program at another time.
	 */
	virtual string writeFormatted() const;

private:
	//note that contains name and yearofbirth parameters from Person class.

	string salary; //string containing the salary of the employee (60,000, etc)
	int duration;  //integer containing the duration of employment of the employee (30, 60, etc)

};

#endif