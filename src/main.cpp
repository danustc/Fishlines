/*
 * main.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: sillycat
 */

#include "linenode.h"
#include "database_io.h"
#include <iostream>
#include <unistd.h>


int main(int argc, char *argv[]){
	cout << "argc = " << argc << endl;
	string fname;
	if(argc > 1){
		//if the number of arguments is non-zero
		fname = argv[1]; // catch the filename
		if (!file_exists(fname))
			cout << "The database file does not exist."<<endl;
		else
			cout << "The database file exists." <<endl;
	}
	else{
		cout << "Please type in the database name:" <<endl;
		cin >> fname;
	}


	line_node *ptr = NULL;
	string ofname = fname + "_out";

	fish_catalog FC(ptr);
	catalog_read_spreadsheet(fname, FC);
	catalog_write_spreadsheet(ofname, &FC);



	return 0;
}
