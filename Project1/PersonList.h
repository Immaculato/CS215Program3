/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * PersonList header
 */

#ifndef PersonList_H
#define PersonList_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Person.h"
#include "Helpers.h"
#include "Employee.h"
#include "Student.h"

using namespace std;

/* Person* parsePerson(string line) - Helper function that parses a line from the datafile into an Employee or Student
	 *
	 * Description: 
	 *   Take in a line from the datafile, and parse it into a new pointer to that new object.
	 *
	 * Inputs:
	 *   A line from the datafile specified by the user upon startup of the program.
	 *
	 * Outputs:
	 *   A Person pointer, that actually refers to either a Student or Employee, based on what was read.
	 *
	 * Side-effects:
	 *  Applies for new memory to create the objects.
	 *
	 * Exceptions:
	 *   Throws runtime errors if the datafile is formatted incorrectly, the years are out of range, if the GPA
	 *   is out of range, or if the type of Person cannot be identified as Student or Employee.
	 *
	 * Notes:
	 *   The new memory allocated to these objects is freed by the PersonList::removePerson() method.
	 */
Person* parsePerson(string line);

class PersonList
{
public:

	/* PersonList(string filename) - Constructor for the person list.
	 *
	 * Description: 
	 *   Take in a string filename, and attempt to open that file and parse its contents into a vector of Persons.
	 *
	 * Inputs:
	 *   string filename to attempt to read.
	 *
	 * Outputs:
	 *   An initialized vector of pointers to Persons with the specified Employees and Students of the data file.
	 *
	 * Side-effects:
	 *  None.
	 *
	 * Exceptions:
	 *   Will throw runtime error if the file cannot be opened.
	 *
	 * Notes:
	 *   None.
	 */
	PersonList(string filename);

	/* PersonList() - Default constructor for the person list.
	 *
	 * Description: 
	 *   Initialize the PersonList vector as empty, to be filled using the program.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   An empty vector of pointers to Persons.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Vector will be filled via user interaction with the program.
	 */
	PersonList();

	/* printPersons() - Print all of the data for each relevant person.
	 *
	 * Description: 
	 *   Prints all of the data for each relevant person in the Person pointer vector.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Prints all of the data for each relevant person in the Person pointer vector to standard output.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Overloaded; alternate outputs in the datafile format to a specified file.
	 */
	void printPersons();
	
	/* printPersons(string filename) - Outputs all of the data for each relevant person to a file.
	 *
	 * Description: 
	 *   Outputs all of the data for each relevant person in the Person pointer vector to a file.
	 *
	 * Inputs:
	 *   A string filename for the file to be opened to write to.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Outputs all of the data for each relevant person in the Person pointer vector to the specified file.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Overloaded function; alternate prints to standard output and is not formatted for the file.
	 */
	void printPersons(string filename);

	/* printEmployees() - Outputs all of the data for each relevant Employee to standard output.
	 *
	 * Description: 
	 *   Outputs all of the data for each Employee in the Person pointer vector to standard output.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Outputs all of the data for each Employee in the Person pointer vector to standard output.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	void printEmployees();
	
	/* printStudents() - Outputs all of the data for each relevant Student to standard output.
	 *
	 * Description: 
	 *   Outputs all of the data for each Student in the Person pointer vector to standard output.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Outputs all of the data for each Student in the Person pointer vector to standard output.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	void printStudents();

	/* Person* findPerson(string personname) - Finds a person with the specified name.
	 *
	 * Description: 
	 *   Finds a person with the specified string name. Returns a pointer to this person, to be printed out by the
	 *	 program.
	 *
	 * Inputs:
	 *   The string (first and last, separated by a space) name of the person to find in the vector of pointers.
	 *
	 * Outputs:
	 *   A pointer to the person that was found, or nothing, if one wasn't found.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   Will throw a runtime error if the specified person cannot be found.
	 *
	 * Notes:
	 *   None.
	 */
	Person* findPerson(string personname);
		
	/* int findIndexPerson(string personname) - Finds the index of the person with the specified string name.
	 *
	 * Description: 
	 *   Finds the index of the person with the specified string name. Returns the integer index of the Person in
	 *   the vector, which can be used to delete the object with removePerson() method.
	 *
	 * Inputs:
	 *   The string (first and last, separated by a space) name of the person to find in the vector of pointers.
	 *
	 * Outputs:
	 *   The integer index of that person in the vector of Persons, or nothing, if it cannot be found.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   Will throw a runtime error if the specified person cannot be found.
	 *
	 * Notes:
	 *   None.
	 */
	int findIndexPerson(string personname);

	/* void addPerson(Person* givenperson) - Adds the given person pointer to the vector of persons.
	 *
	 * Description: 
	 *   Adds the given person (via a pointer to that person) to the vector of persons at the end.
	 *
	 * Inputs:
	 *   A pointer to the given person.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Pushes back the pointer to the Person onto the person vector.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   This documentation is taking forever.
	 */
	void addPerson(Person* givenperson);

	/* void removePerson(int personindex) - Removes the person at the index specified in the vector of Persons.
	 *
	 * Description: 
	 *  Removes the person at the index specified in the vector of Persons. All users after that person will be
	 *  moved upward in the sequence (so if 4 is deleted, 5 will become 4, 6 will become 5, etc)
	 *
	 * Inputs:
	 *   The index of the person in the vector of persons which is to be deleted.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   Removes the specified person at the index, and also deallocates the memory used to store the pointer.
	 *
	 * Exceptions:
	 *   Will throw a runtime error if the given integer is out of range of the vector.
	 *
	 * Notes:
	 *   None.
	 */
	void removePerson(int personindex);

	/* int sizeOfList() - Returns the current size of the user list.
	 *
	 * Description: 
	 *  Gives current size of user list as int.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
	int sizeOfList() const;

private:

	vector<Person*> personlist; //create a vector to hold the pointers to the Persons.
};

#endif