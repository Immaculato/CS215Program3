#ifndef Person_H
#define Person_H

#include <vector>
#include <string>

using namespace std;

class Person
{
public:
	Person();
	virtual ~Person();
	Person(string nameparam, int yearofbirthparam);
		//Create a person with a given string name and a given int year of birth.
	string personName() const;
		//Return the name of the person.
	int personYear() const;
		//Return the int year of birth of the person.
	virtual void write() const;
		//Print the given person's name and year of birth to standard output stream.
	virtual string writeFormatted() const;
		//Write the given person's name and year of birth to a given output stream. **IMPLEMENT******
private:
	string name;
	int yearofbirth;
};





#endif