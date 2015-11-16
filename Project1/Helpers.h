/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Helper header
 */

#ifndef Helpers_H
#define Helpers_H

#include <vector>
#include <string>

using namespace std;

    /* vector<string> splitString(string input) - splits a string along #'s: used for splitting lines read from
	 *											  the formatted datafile specified by the user.
	 *
	 * Description: 
	 *  Splits a string along #'s. Used to to split a line into a vector of strings to be converted to their
	 *  repesctive necessary data members for either an employee or student.
	 *
	 * Inputs:
	 *   A string input with strings separated by #'s, particularly from a formatted datafile.
	 *
	 * Outputs:
	 *   A vector of strings containing each piece of information encapsulated by the formatted line.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   Used with a line read from a formatted datafile.
	 */
vector<string> splitString(string input);

    /* int stringToInt(string str) - helper function that converts a given string to an integer.
	 *
	 * Description: 
	 *  converts a string of digits to an integer.
	 *
	 * Inputs:
	 *   A string of numerical digits.
	 *
	 * Outputs:
	 *   The integer corresponding to the digits in the string.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   Throws an exception if the string does not contain digits corresponding to an integer.
	 *
	 * Notes:
	 *   Used to convert parsed string info from the line of a datafile to an integer (year of birth).
	 */
int stringToInt(string str);

// Convert a numeric string to a double.  Throws an exception if it is
// not a number.
    /* double stringToDouble(string str) - helper function that converts a given string to an double.
	 *
	 * Description: 
	 *  converts a string of digits to a double.
	 *
	 * Inputs:
	 *   A string of digits corresponding to a float value (digits.digits)
	 *
	 * Outputs:
	 *   The double corresponding to the digits in the string.
	 *
	 * Side-effects:
	 *   None.
	 *
	 * Exceptions:
	 *   Throws an exception if the string does not contain digits corresponding to a double.
	 *
	 * Notes:
	 *   Used to convert parsed string info from the line of a datafile to a double (GPA).
	 */
double stringToDouble(string str);

#endif