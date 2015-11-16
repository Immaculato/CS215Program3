/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Implementation of the Helper functions, declared in Helpers.h.
 */

#include <stdexcept>
#include <iostream>
#include <sstream>
#include "helpers.h"

// Split a string on the # character.  Returns a vector of the parts, in order.
vector<string> splitString(string input)
{
	vector<string> pieces;

	// Start of the current field
	int field_start = 0;

	// Location of the next at sign.
	int next_at;
	do {
		// Find the #.  Returns the index, or string::npos if it wasn't
		// found.
		next_at = input.find('#', field_start);

		// If it wasn't found, add the last piece.
		if (next_at == string::npos)
			pieces.push_back(input.substr(field_start));
		// Or it was found, so add this piece
		else
			pieces.push_back(input.substr(field_start, next_at - field_start));

		// The next field starts just after the # 
		field_start = next_at + 1;

		// If there was no #, we're done.
	} while(next_at != string::npos);

	return pieces;
}

// Convert a numeric string to an int.  Throws an exception if it is
// not a number.
int stringToInt(string str)
{
	int num;
	istringstream instr(str);
	instr >> num;
	if (instr.fail())
		throw runtime_error("invalid number " + str);

	// Check for junk after the number.
	string remaining = "junk";
	getline(instr, remaining);

	// End of file or an empty string means there was no junk.
	if (instr.eof() || remaining == "")
		return num;
	else
		throw runtime_error("garbage after number " + str);
}

// Convert a numeric string to a double.  Throws an exception if it is
// not a number.
double stringToDouble(string str)
{
	double num;
	istringstream instr(str);
	instr >> num;
	if (instr.fail())
		throw runtime_error("invalid number " + str);

	// Check for junk after the number.
	string remaining = "junk";
	getline(instr, remaining);

	// End of file or an empty string means there was no junk.
	if (instr.eof() || remaining == "")
		return num;
	else
		throw runtime_error("garbage after number " + str);
}