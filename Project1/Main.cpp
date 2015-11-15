#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>
#include "Helpers.h"
#include "Person.h"
#include "PersonList.h"
#include "Student.h"
#include "Employee.h"

using namespace std;

int main()
{
	
	string nameoffile;

	cout << "Please enter the data file name: "; //get a name of a data file from the user
	getline(cin, nameoffile);
	


	PersonList personlist;

	while (true)			//until the file is proven to work,
	{
		try						//attempt to load the file into the database
		{
			if (nameoffile == "")	//if the name of the file is empty,
			{
				break; //break the loop; it should be initialized as empty!
			}
			personlist = PersonList(nameoffile);
			break;	// otherwise, if it is an actual string and works, break the loop because its been initialized.
		}
		catch(runtime_error &e)	//if it doesn't work, and therefore throws a runtime error,
		{
			cout << e.what() << "\nPlease enter the data file name: "; //cout the runtime error description,
			cin.clear();	//clear the failing state, and
			getline(cin, nameoffile); //ask for a valid file name again.
		}
	}

	bool finishedwithprogram = false;
	char userchoice;
	while (!finishedwithprogram)
	{
		cout << "\nYou may view a [P]erson, [E]mployee or [S]tudent list, \n"
			<< "[F]ind a person, [A]dd a new person, [R]emove a person, \n"
			<< "sa[V]e the list, save as a [N]ew file, or [Q]uit." << endl
			<< "\nEnter a command: ";
		cin >> userchoice;
		userchoice = toupper(userchoice);

		if (userchoice == 'P')
		{
			personlist.printPersons();
		}
		else if (userchoice == 'E')
		{
			personlist.printEmployees();
		}
		else if (userchoice == 'S')
		{
			personlist.printStudents();
		}
		else if (userchoice == 'F')
		{
			string personfirstname;
			string personlastname;
			cout << "Person's Name? ";
			try
			{
				cin >> personfirstname >> personlastname;
				cout << personlist.findIndexPerson(personfirstname + " " + personlastname) << ".";
				personlist.findPerson(personfirstname + " " + personlastname)->write();
			}
			catch (runtime_error r)
			{
				cout << r.what() << "\n";
			}
		}
		else if (userchoice == 'A')
		{
			char personstatus;
			cout << "[E]mployee, or [S]tudent? ";
			cin >> personstatus;
			while (true)
			{
				if (toupper(personstatus) == 'E')
				{
					string firstname;
					string lastname;
					string yearofbirth;
					string salary;
					string durationofemployment;
					cout << "Name: ";
					cin >> firstname >> lastname;
					cout << "\nYear of birth: ";
					cin >> yearofbirth;
					cout << "\nSalary: ";
					cin >> salary;
					cout << "\nDuration of employment: ";
					cin >> durationofemployment;
					personlist.addPerson(new Employee((firstname + " " + lastname), stringToInt(yearofbirth),
						salary, stringToInt(durationofemployment)));
					break;
				}
				else if (toupper(personstatus) == 'S')
				{
					string firstname;
					string lastname;
					string yearofbirth;
					string levelofstudy;
					string GPA;
					string major;
					cout << "Name: ";
					cin >> firstname >> lastname;
					cout << "Year of birth: ";
					cin >> yearofbirth;
					cout << "Level of study: ";
					cin >> levelofstudy;
					cout << "GPA: ";
					cin >> GPA;
					cout << "Major: ";
					cin >> major;

					personlist.addPerson(new Student((firstname + " " + lastname), stringToInt(yearofbirth),
						levelofstudy, stringToDouble(GPA), major));
					break;
				}
				else
				{
					cout << "Unknown command: " << char(toupper(personstatus)) << endl;
					cout << "\n[E]mployee, or [S]tudent? ";
					cin >> personstatus;
				}
			}

			//string nameparam, int yearofbirthparam,
					//string levelofstudyparam, double GPAparam, string majorparam
		}
		else if (userchoice == 'R')
		{
			int indexuser = 0;
			while (indexuser != -1)
			{
				try
				{
					cout << "Please enter the number associated with the person [0-10, -1 to cancel]: ";
					cin >> indexuser;
					personlist.removePerson(indexuser);
					break;
				}
				catch(range_error r)
				{
					cout << r.what();
				}
			}
		}
		else if (userchoice == 'V')
		{
			personlist.printPersons(nameoffile);
		}

		else if (userchoice == 'N')
		{
			string newfilename;
			cout << "Please enter a file name: ";
			cin >> newfilename;
			personlist.printPersons(newfilename);
		}


		else if (userchoice == 'Q')
		{
			finishedwithprogram = true;
		}

	}
	system("pause");
	return 1;

}
/*
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