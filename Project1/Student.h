#ifndef Student_H
#define Student_H

#include "Person.h"
#include <vector>
#include <string>

using namespace std;


class Student : public Person
{
public:
	Student(string nameparam, int yearofbirth, string levelofstudyparam, double GPAparam, string majorparam);
	~Student();
			//Create a student with the given level of study, GPA, and major. Sets student_status to True.
	string getLevelofstudy() const;
			//Return the level of study of the student as a string.
	double getGPA() const;
			//Return the GPA of the student as a double.
	string getMajor() const;
			//Return the major of the student as a string.
	virtual void write() const;
		//Rather than just print the student's name and year, this override will print those, with the student's level of study, gpa, and major.
	virtual string writeFormatted() const;
		//Rather than just write the student's name and year, this override will print those, with the student's level of study, gpa, and major.
private:
	string levelofstudy;
	double GPA;
	string major;

};

#endif