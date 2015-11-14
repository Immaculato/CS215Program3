#ifndef Helpers_H
#define Helpers_H

#include <vector>
#include <string>

using namespace std;

// Split a string on the # character.  Returns a vector of the parts, in order.
vector<string> splitString(string input);

// Convert a numeric string to an int.  Throws an exception if it is
// not a number.
int stringToInt(string str);

// Convert a numeric string to a double.  Throws an exception if it is
// not a number.
double stringToDouble(string str);


#endif