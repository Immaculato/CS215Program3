/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Implementation of the main function, which drives the entire program.
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Helpers.h"
#include "Person.h"
#include "PersonList.h"
#include "Student.h"
#include "Employee.h"
#include "Main.h"

using namespace std;

int main()
{
	
	string nameoffile;

	cout << "Please enter the data file name, or press enter to\ncontinue without one: "; 
	getline(cin, nameoffile); //get a name of a data file from the user
	


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
	while (!finishedwithprogram)		//start a loop for running the main commands of the program.
	{
		cout << "\nYou may view a [P]erson, [E]mployee or [S]tudent list, \n"
			<< "[F]ind a person, [A]dd a new person, [R]emove a person, \n"
			<< "sa[V]e the list, save as a [N]ew file, or [Q]uit." << endl
			<< "\nEnter a command: ";
		cin >> userchoice;
		userchoice = toupper(userchoice);   //get the user's choice for what they want to do.

		if (userchoice == 'P')   //if they want to print persons,
		{
			personlist.printPersons(); //print persons.
		}
		else if (userchoice == 'E')  //if they want to print employees,
		{
			personlist.printEmployees();  //print employees.
		}
		else if (userchoice == 'S')  //if they want to print students,
		{
			personlist.printStudents();  //print students.
		}
		else if (userchoice == 'F')  //if they want to find a person,
		{
			string personfirstname;
			string personlastname;
			cout << "Person's Name? "; 
			try          //try to get the person's name, and
			{
				cin >> personfirstname >> personlastname;
				cout << personlist.findIndexPerson(personfirstname + " " + personlastname) << "."; //find said person.
				personlist.findPerson(personfirstname + " " + personlastname)->write(); //also output it when found!
			}
			catch (runtime_error r)    //if the name can't be found,
			{
				cout << r.what() << "\n";  //report what happened, and ask again.
			}
		}
		else if (userchoice == 'A')  //if they wanted to add a person,
		{
			char personstatus;
			cout << "[E]mployee, or [S]tudent? ";
			cin >> personstatus;   //ask if they want to add an employee or student.
			while (true)
			{
				if (toupper(personstatus) == 'E')  //if they want to add an employee,
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
					cin >> durationofemployment;				//get all of the relevant data for an employee, and
					personlist.addPerson(new Employee((firstname + " " + lastname), stringToInt(yearofbirth),
						salary, stringToInt(durationofemployment)));   //add the new employee to the personlist.
					break;  //break the loop if this is done successfully!
				}
				else if (toupper(personstatus) == 'S') //if they want to add a student,
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
					cin >> major;				//get all of the info relevant to the student, and

					personlist.addPerson(new Student((firstname + " " + lastname), stringToInt(yearofbirth),
						levelofstudy, stringToDouble(GPA), major));   //create a new student with that data.
					break; //break the loop if this is done successfully!
				}
				else  //if they don't say they want to make a student or employee,
				{
					cout << "Unknown command: " << char(toupper(personstatus)) << endl;
					cout << "\n[E]mployee, or [S]tudent? ";
					cin >> personstatus;  //ask again, and try the process over.
				}
			}
		}

		else if (userchoice == 'R')  //if the user wants to remove a person,
		{
			int indexuser = 0;
			cout << "Please enter the number associated with the person [0-" << personlist.sizeOfList() - 1
				<< " or -1 to cancel]: ";
			cin >> indexuser;   //get the index associated with the person they want to remove.

			while (indexuser != -1)  //while they arent inputting -1,
			{
				try
				{
					personlist.removePerson(indexuser);    //try to remove the person.
					cout << "Person removed successfully.\n";  //if they get this far, it worked, so say so.
					break;  //break the loop if its removed successfully!
				}
				catch(range_error r)   //if it isnt successfully removed,
				{
					cout << r.what();  //output what went wrong, and...
				}
				cout << "Please enter the number associated with the person [0-10, -1 to cancel]: ";
				cin >> indexuser;	   //...ask again.
			}
		}

		else if (userchoice == 'V')  //if the user wants to save the current list of persons to their working file,
		{
			if (nameoffile != "")
			{
				personlist.printPersons(nameoffile); //print to the original file!
			}
			else  //if they didn't initially specify a working file,
			{
				cout << "You don't have a file you're working from to save to! \nSpecify a new file using [N].\n";
				//tell them that they don't have a working file! they need to create a new one.
			}
		}

		else if (userchoice == 'N')  //if the user wants to create a new file and save to it,
		{
			string newfilename;
			cout << "Please enter a file name: ";  //get the name of the new file they want to save to, and
			cin >> newfilename;					   //create and save to it.
			personlist.printPersons(newfilename);
		}


		else if (userchoice == 'Q') //if they user wants to quit,
		{
			finishedwithprogram = true;  //the user is done; break the loop and end the program.
		}

		else  //if the user didn't input a valid command,
		{
			cout << "Command not recognized; please enter a valid command." << endl;  
			//tell them and ask for a valid command again.
		}

	}
	system("pause");
	return 1;   //return 1 to indicate that the program quit successfully.

}