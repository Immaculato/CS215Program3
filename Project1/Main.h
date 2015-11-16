/* Tristan Basil
 * CS 215, Fall 2015
 * Programming assignment 3
 * Nov 15, 2015
 *
 * Main header
 */

#ifndef Main_h
#define Main_h

/* int main() - Drives the main function of the program. Allows the user to interact with a vector of Persons
	 *			(employees and students).
	 *
	 * Description: 
	 *  Loads a file specified by the user, or initializes a new vector for the user to add new Employees and
	 *  Students to via the interface of the program. After, asks the user what they want to do 
	 *  (P, E, S, F, A, R, V, N or Q; these correspond to printing the whole person list, printing employees, 
	 *  printing students, finding a person, adding a person, removing a person, saving the file, 
	 *  saving the vector to a new file, and quitting) and carries it out.
	 *
	 * Inputs:
	 *   A file specified by the user (or a lack thereof), and a character corresponding to a command
	 *   (P, E, S, F, A, R, V, N or Q; these correspond to printing the whole person list, printing employees, 
	 *   printing students, finding a person, adding a person, removing a person, saving the file, 
	 *   saving the vector to a new file, and quitting)
	 *
	 * Outputs:
	 *   returns the integer 1 upon successfuly quitting use of the program.
	 *
	 * Side-effects:
	 *   Outputs a number of different types of data to standard output depending on what command was specified.
	 *   Can also output directly to a specified file (which can be new).
	 *
	 * Exceptions:
	 *   None.
	 *
	 * Notes:
	 *   None.
	 */
int main();

#endif