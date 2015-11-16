/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Implementation of the Student class.
 */

#include "Student.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Student::Student(string nameparam, int yearofbirthparam, string levelofstudyparam, double GPAparam, string majorparam)
	: Person(nameparam, yearofbirthparam)
{
	levelofstudy = levelofstudyparam;  //initailize a student using the person default constructor and the given
	GPA = GPAparam;					   //student data members.
	major = majorparam;
}

Student::~Student()
{
}

string Student::getLevelofstudy() const
{
	return levelofstudy;  //return the string level of study of the student.
}

double Student::getGPA() const
{
	return GPA;   //return the double GPA of the student.
}

string Student::getMajor() const
{
	return major;  //return the major of the student.
}

void Student::write() const
{
	cout << " " << personName() << ":\n   Year of birth: " << personYear() << "\n   Student level: " 
		<< levelofstudy << "\n   GPA: " << GPA << "\n   Major: " << major << endl;
	//cout the relevant info for the student.
}

string Student::writeFormatted() const
{
	string formattedstring = "student#" + personName() + "#" + to_string(personYear()) + "#" + levelofstudy + "#"
		+ to_string(GPA) + "#" + major;  //construct the formatted string for the student, and
	return formattedstring;				 //return it.
}