/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Person header
 */

#ifndef Person_H
#define Person_H

#include <vector>
#include <string>

using namespace std;

class Person
{
public:
	/* void Person() - ABSTRACT BASE CLASS CONSTRUCTOR: default constructor for a person.
	 *
	 * Description: 
	 *  Acts as the abstract base class default constructor. Not to be called directly.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   A Person with uninitialized data members.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Not to be called.
	 */
	Person();

	/* virtual ~Person() - Abstract base class virtual destructor
	 *
	 * Description: 
	 *  Acts as the abstract base class default destructor. Virtual to ensure pointer to Person and derived class
	 *  can be deleted when prompted.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Deletes Person object.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	virtual ~Person();

	/* virtual ~Person() - Abstract base class constructor
	 *
	 * Description: 
	 *  Acts as the abstract base class constructor.
	 *
	 * Inputs:
	 *   string name and integer year of birth.
	 *
	 * Outputs:
	 *   Person with initialized data members as specified.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Used to construct derived class objects.
	 */
	Person(string nameparam, int yearofbirthparam);
	
	/* string personName() const - Accessor to name of Person: returns name of the person as an string.
	 *
	 * Description: 
	 *   Accessor to the name of the Person as a string.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   Returns the name of the Person as a string.
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
	string personName() const;
	
	/* int personYear() const - Accessor to birth year of Person: returns year of the person as an integer.
	 *
	 * Description: 
	 *   Accessor to the year of the Person as an integer.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   Returns the year of the Person as a string.
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
	int personYear() const;
	
	/* virtual void write() const - Abstract base class print to standard output.
	 *
	 * Description: 
	 *  Prints a Person's data members to standard output.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Outputs a Person's data members to standard output.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Should not be called explicitly. Used as a abstract base class method, overriden by derived class methods.
	 */
	virtual void write() const;
	
	/* virtual string writeFormatted() const - Abstract base class to output the formatted data members of a Person.
	 *
	 * Description: 
	 *  Abstract base class to format a Person's data members; here, it is useless. Overriden by
	 *  derived class methods.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   Returns a junk string containing a statement that the user should not be seeing its output, because
	 *   it should not be called directly.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Should not be called explicitly. Used as a abstract base class method, overriden by derived class methods.
	 */
	virtual string writeFormatted() const;
		
private:

	string name;     //contains the name of the Person as a string.
	int yearofbirth; //contains the integer of the Person's birth year.

};





#endif