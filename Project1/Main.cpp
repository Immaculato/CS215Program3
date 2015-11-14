#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	system("pause");
}
/*
Design for Programming Assignment 3
Name: Tristan Basil
Oct 22, 2015

Classes:

Person: A person in a person list.
Data members:
	string name: a string containing the first and last name of the person.
	int yearofbirth: an integer containing the year of birth of the person
	bool employee_status: a boolean containing the status of the person as an employee. False by default.
	bool student_status: a boolean containing the status of the person as a student. False by default.
Methods:
	person(str name, int yearofbirth)
		Create a person with a given string name and a given int year of birth.
	str personName()
		Return the name of the person.
	int personYear()
		Return the int year of birth of the person.
	void write()
		Print the given person's name and year of birth to standard output stream.
	void writeToOutput(ofstream outputstream)
		Write the given person's name and year of birth to a given output stream.
	bool isEmployee()
		Return True if the user is an employee.
	bool isStudent()
		Return True if the user is a student.

Employee: A person who is an employee.
Inherits from class Person.
Data members:
	string salary: an integer containing the amount in dollars per year of the salary of the employee
	int duration: an integer representing the amount of time the employee has been employed in months.
Methods:
	Public:
		employee(int salary, int duration)
			Create an employee with the given int salary and int duration. Sets employee_status to True.
	Private:
		string salary()
			Return the int salary amount of the employee as a string.
		int duration()
			Return the int amount of time in months the employee has been employed.
Overrides:
	void write()
		Rather than just print the employees name and year, this override will print those, with the employee's salary and duration.
	void writeToOutput(ofstream outputstream)
		Rather than just write the employees name and year, this override will print those, with the employee's salary and duration.

Student: A person who is a student.
Inherits from class Person.
Data members:
	string levelofstudy: a string containing the level of study of the student.
	double GPA: a double containing the GPA of the student.
	string major: a string containing the major of the student.
Methods:
	Public:
		student(string levelofstudy, double GPA, string major)
			Create a student with the given level of study, GPA, and major. Sets student_status to True.
		string levelofstudy()
			Return the level of study of the student as a string.
	Private:
		double gpa()
			Return the GPA of the student as a double.
		string major()
			Return the major of the student as a string.
Overrides:
	void write()
		Rather than just print the student's name and year, this override will print those, with the student's level of study, gpa, and major.
	void writeToOutput(ofstream outputstream)
		Rather than just write the student's name and year, this override will print those, with the student's level of study, gpa, and major.

personList: a list of the persons in the program
Contains Person objects.
Data members:
	vector<*person> personlist: a vector of persons containing the persons in the program.
Methods:
	personList(infile givenfile)
		Initialize the personlist by parsing information from a given file.
	personList()
		Initialize the personlist as completely empty.
	void printPersons()
		Print all of the data for each relevant person in an easy-to-read format. Calls .write() method for each person.
	void printEmployees()
		Print all the data for each relevaant employee in an easy-to-read format. Calls .isEmployee() for each person, and .write() method for each employee.
	void printStudents()
		Print all the data for each relevant student in an easy-to-read format. Calls .isStudent() for each person, and .write() method for each student.
	person findPerson(string name)
		Search for a person with the given string name in the vector of persons. If found, return the person object corresponding to the given person name. Uses .personName() method to find the name of each person.
	void addPerson(person givenperson)
		Push back a given person to the personlist.
	void removePerson(person givenperson)
		Remove a given person from the personlist.

Nonmember functions:

int main():  Main driver program.
  No parameters.
  Always returns 0, indicating no error.

Pseudocode for main:
1. Prompt the user for the name of a person list file in a while loop.
2. While user hasn't supplied a valid name: try to load the file. If they don't supply a valid name, 
	clear the failing state and ask again. If they press enter without pushing anything, initialize 
	the person list as empty.
3. Ask the user what they want to do (P, E, S, F, A, R, or Q; these correspond to printing the 
	whole person list, printing employees, printing students, finding a person, adding a person, 
	removing a person, and quitting)
4. Carry out what the user wants to do: printPersons() for P, printEmployees() for E, printStudents() 
	for S, use findPerson() and then the methods relevant for that person's information for F, addPerson()
	for A, and removePerson for R. Quit if the user supplied Q by returning 0.

*/