#include "Person.h"
#include <iostream>
#include <iomanip>

using namespace std;


Person::Person()
{
}

Person::Person(string nameparam, int yearofbirthparam)
{
	name = nameparam;
	yearofbirth = yearofbirthparam;
}

		//Create a person with a given string name and a given int year of birth.
string Person::personName() const
{
	return name;
}

		//Return the name of the person.
int Person::personYear() const
{
	return yearofbirth;
}

		//Return the int year of birth of the person.
void Person::write() const
{
	cout << "Person Class: Name=" << name << " Yearofbirth=" << yearofbirth << endl;
}

		//Print the given person's name and year of birth to standard output stream.

void Person::writeToOutput(string nameoffile) const
{
	cout << "IMPLEMENT THIS";
}


//EMPLOYEE IMPLEMENTATION


Employee::Employee(string nameparam, int yearofbirthparam, string salaryparam, int durationparam) : Person(nameparam,
																							  yearofbirthparam)
{
	salary = salaryparam;
	duration = durationparam;
}

			//Create an employee with the given int salary and int duration.
string Employee::getSalary() const
{
	return salary;
}

			//Return the int salary amount of the employee as a string.
int Employee::getDuration() const
{
	return duration;
}

			//Return the int amount of time in months the employee has been employed.
void Employee::write() const
{
	cout << " " << personName() << ":\n   Year of birth: " << personYear() << "\n   Salary: " << salary 
		<< "\n   Duration of employment: " << duration << endl;

}

		//Rather than just print the employees name and year, this override will print those, with the employee's salary and duration.

void Employee::writeToOutput(string nameoffile) const
{
}

		//Rather than just write the employees name and year, this override will print those, 
		//with the employee's salary and duration.

Student::Student(string nameparam, int yearofbirthparam, string levelofstudyparam, double GPAparam, string majorparam)
	: Person(nameparam, yearofbirthparam)
{
	levelofstudy = levelofstudyparam;
	GPA = GPAparam;
	major = majorparam;
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

void Student::writeToOutput(string nameoffile) const
{
	//shit
}
		//Rather than just write the student's name and year, this override will print those, with the student's level of study, gpa, and major.