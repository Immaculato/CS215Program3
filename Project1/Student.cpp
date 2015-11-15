#include "Student.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Student::Student(string nameparam, int yearofbirthparam, string levelofstudyparam, double GPAparam, string majorparam)
	: Person(nameparam, yearofbirthparam)
{
	levelofstudy = levelofstudyparam;
	GPA = GPAparam;
	major = majorparam;
}

Student::~Student()
{
}

			//Create a student with the given level of study, GPA, and major. Sets student_status to True.
string Student::getLevelofstudy() const
{
	return levelofstudy;
}
			//Return the level of study of the student as a string.
double Student::getGPA() const
{
	return GPA;
}
			//Return the GPA of the student as a double.
string Student::getMajor() const
{
	return major;
}
			//Return the major of the student as a string.
void Student::write() const
{
	cout << " " << personName() << ":\n   Year of birth: " << personYear() << "\n   Student level: " 
		<< levelofstudy << "\n   GPA: " << GPA << "\n   Major: " << major << endl;
}

		//Rather than just print the student's name and year, this override will print those, with the student's level of study, gpa, and major.

string Student::writeFormatted() const
{
	string formattedstring = "student#" + personName() + "#" + to_string(personYear()) + "#" + levelofstudy + "#"
		+ to_string(GPA) + "#" + major;
	return formattedstring;
}
		//Rather than just write the student's name and year, this override will print those, with the student's level of study, gpa, and major.