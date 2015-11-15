#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>
#include "Helpers.h"
#include "Person.h"
#include "PersonList.h"

using namespace std;

int main()
{
	system("pause");
	
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
	personlist.printPersons();

	system("pause");

	bool finishedwithprogram = false;
	char userchoice;
	while (!finishedwithprogram)
	{
		cin >> userchoice;
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
			string personlookingfor;
			cout << "Person's Name? ";
			getline(cin, personlookingfor);
			personlist.findPerson(personlookingfor).write();
		}
		else if (userchoice == 'A')
		{
			char personstatus;
			cin >> personstatus;
			if (personstatus == 'E')
			{
				string name;
				string yearofbirth;
				string salary;
				string durationofemployment;
				cout << "Name: ";
				getline(cin, name);
				cout << "\nYear of Birth: ";
				cin >> yearofbirth;
				cout << "\nSalary: ";
				cin >> salary;
				cout << "\nDuration of employment";
				cin >> durationofemployment;
			}
		}
	}

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