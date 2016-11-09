/*
 * main.cpp

 *
 *  Created on: Oct 26, 2016
 *      Author: sillycat
 *      Last update: 11/09/2016
 */

#include "linenode.h"
#include "database_io.h"
#include <iostream>
#include <cstdlib>


int main(int argc, char *argv[]){
	cout << "argc = " << argc << endl;

	if(argc ==1){
		cout << "No arguments. Please enter your options and database filenames." <<endl;
		return 0;
	} // endif argc ==1

	else{
		//if the number of arguments is non-zero
		int ch = atoi(argv[1]); // catch the filename

		line_node *ptr = NULL;
		fish_catalog FC(ptr);

		switch(ch){
		case 0:
		{
			string fout;
			cout << "Choice" << ch << ": direct input of fish lines." <<endl;
			FC.terminal_input();
			cout << "Input complete!" <<endl;
			if(argc > 2)
				fout = argv[2];
			else{
				cout << "Please type in the database filename to save the line records: " <<endl;
				cin >> fout;
			}//end else
			catalog_write_spreadsheet(fout, &FC);
			break;
		}
		case 1:
		{
			cout << ch << "You selected reading from an existing database. " <<endl;
			string fin;
			if (argc > 2)
				fin = argv[2];
			else{
				cout << "Please type in the database filename: ";
				cin >> fin;
			}
			if (file_exists(fin)){
				cout << "The database file does not exist."<< endl;
				catalog_read_spreadsheet(fin, FC);
			}//
			else
				cout << "Error! The database file doesn't exist. " <<endl;
			break;
		}
		case 2:
		{
			cout << ch;
			break;
		}
		default:
			cout << ch;
			break;
		}//end switch

	} //end else
	return 0;
}
