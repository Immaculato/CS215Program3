#ifndef Person_H
#define Person_H

#include <vector>
#include <string>

using namespace std;

class Person
{
public:
	Person();
	Person(string nameparam, int yearofbirthparam);
		//Create a person with a given string name and a given int year of birth.
	string personName() const;
		//Return the name of the person.
	int personYear() const;
		//Return the int year of birth of the person.
	virtual void write() const;
		//Print the given person's name and year of birth to standard output stream.
	virtual void writeToOutput(string nameoffile) const;
		//Write the given person's name and year of birth to a given output stream. **IMPLEMENT******
private:
	string name;
	int yearofbirth;
};

class Employee : public Person
{
public:
	Employee(string nameparam, int yearofbirthparam, string salaryparam, int durationparam);
			//Create an employee with the given int salary and int duration. Sets employee_status to True.
	string getSalary() const;
			//Return the int salary amount of the employee as a string.
	int getDuration() const;
			//Return the int amount of time in months the employee has been employed.
	virtual void write() const;
		//Rather than just print the employees name and year, this override will print those, with the employee's salary and duration.
	virtual void writeToOutput(string nameoffile) const;
		//Rather than just write the employees name and year, this override will print those, with the employee's salary and duration.
private:
	string salary;
	int duration;
};

class Student : public Person
{
public:
	Student(string nameparam, int yearofbirth, string levelofstudyparam, double GPAparam, string majorparam);
			//Create a student with the given level of study, GPA, and major. Sets student_status to True.
	string getLevelofstudy() const;
			//Return the level of study of the student as a string.
	double getGPA() const;
			//Return the GPA of the student as a double.
	string getMajor() const;
			//Return the major of the student as a string.
	virtual void write() const;
		//Rather than just print the student's name and year, this override will print those, with the student's level of study, gpa, and major.
	virtual void writeToOutput(string nameoffile) const;
		//Rather than just write the student's name and year, this override will print those, with the student's level of study, gpa, and major.
private:
	string levelofstudy;
	double GPA;
	string major;

};

#endif