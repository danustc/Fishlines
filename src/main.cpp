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

/*
 * flags:
 * -i <filename.txt> input the file name
 * -m <file1.txt> <file2.txt> ... <filen.txt> merge multiple database files
 * -c <file.txt> <line number> add comments to the line number:
 * -l <filename.txt> load an existing database
 */



int main(int argc, char *argv[]){
	cout << "argc = " << argc << endl;

	if(argc ==1){
		cout << "No arguments. Please enter your options and database filenames." <<endl;
		return 0;
	} // endif argc ==1

	else{
		//if the number of arguments is non-zero
		char* ch_flag = argv[1]; // flag
		char ch = ch_flag[1]; // the first character is dash
		if(ch_flag[0] != '-')
		{
			cout <<"Error! the flag cannot be interpreted."<<endl;
			return 1;
		} // endif



		switch(ch){
		case 'i':
		{
			string fout;
			line_node *ptr = NULL;
			fish_catalog FC(ptr);
			if(argc > 2){
				fout = argv[2];
				if(file_exists(fout)){
					cout << "Find the database file." <<endl;
					catalog_read_spreadsheet(fout, &FC);
				}
			}//endif
			else{
				cout << "Please type in the database filename to save the line records: " <<endl;
				cin >> fout;
			}//end else

			cout << "Choice" << ch << ": direct input of fish lines." <<endl;
			FC.terminal_input();
			cout << "Input complete!" <<endl;

			catalog_write_spreadsheet(fout, &FC);
			break;
		}
		case 'm':
		{
			string fin;
			int n_file = argc-2;
			if (argc <2){
				cout<<"Error! Insufficient number of datafiles. "<<endl;
				return -1;
			} // end if not sufficient number

			else{
				fish_catalog *FC_pools = new fish_catalog[n_file];
				for (int ia = 0; ia< n_file; ++ia){
					FC_pools[ia] = fish_catalog(NULL);
				}//end for
			}
			break;
		}
		case 'l':
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
