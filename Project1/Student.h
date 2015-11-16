/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Student header
 */

#ifndef Student_H
#define Student_H

#include "Person.h"
#include <vector>
#include <string>

using namespace std;


class Student : public Person
{
public:
	/* Student(string nameparam, int yearofbirth, string levelofstudyparam, double GPAparam, string majorparam)
	 *		- Constructor for a student.
	 *
	 * Description: 
	 *   Take in a name, year, level of study, gpa, and major, and initialize a student with those data members.
	 *
	 * Inputs:
	 *   string name, integer year of birth, string level of study, double GPA, and string major.
	 *
	 * Outputs:
	 *   An initialized Student with specified parameters.
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
	Student(string nameparam, int yearofbirth, string levelofstudyparam, double GPAparam, string majorparam);
	
	/* ~Student() - Destructor for student.
	 *
	 * Description: 
	 *   Default destructor for a Student class object.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *  Deletes the Student pointer object, and after, its respective pointer as an inherited Person when called
	 *  upon.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Virtual function destructor of Person class. Will call Person class destructor just after calling this one.
	 */
	~Student();

	/* string getLevelofstudy() const - Accessor to level of study: returns level of study of the student as a string.
	 *
	 * Description: 
	 *   Accessor to the level of study of a student as a string.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   Returns the level of study of the student as a string.
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
	string getLevelofstudy() const;
	
	/* double getGPA() const - Accessor to GPA: returns GPA of the student as a double.
	 *
	 * Description: 
	 *   Accessor to the GPA of a student as a double.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   Returns the GPA of the student as a double.
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
	double getGPA() const;
	
	/*string getMajor() const - Accessor to major: returns major of the student as a string.
	 *
	 * Description: 
	 *   Accessor to the major of a student as a string.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   Returns the major of the student as a string.
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
	string getMajor() const;
	
	/*virtual void write() const - Print Student data members to standard output (formatted in rows)
	 *
	 * Description: 
	 *   Prints a student's data members to standard output.
	 *
	 * Inputs:
	 *   None.
	 *
	 * Outputs:
	 *   None.
	 *
	 * Side-effects:
	 *  Prints the Student's data members to standard output (name, year, level of study, gpa, major) 
	 *  formatted in a row system with a new line after.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Includes a space at the beginning to put the number of the object in the PersonList vector data member.
	 *   Override of Person's write function.
	 */
	virtual void write() const;

	/*virtual string writeFormatted() const - Return database-form string of Student data members
	 *
	 * Description: 
	 *   Returns the database-formatted data members of the student, with #'s between them.
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
	 *   Prints the data members of a student formatted such that it can be inserted directly into a new file,
	 *   which can be saved and accessed by the program at another time.
	 */
	virtual string writeFormatted() const;
		
private:
	//note that contains name and yearofbirth parameters from Person class.

	string levelofstudy;  //string containing level of study (freshman, sophomore, etc)
	double GPA;			  //double containing GPA of student
	string major;		  //string containing major of student (CS, EE, etc)

};

#endif