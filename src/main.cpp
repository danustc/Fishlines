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
		cin >> fname;
	}



	line_node *ptr = catalog_input_line();
	// OK, here
	fish_catalog FC(ptr);
	FC.insert_line(ptr);
	for (int ic =0; ic< 3; ++ic){
		ptr = catalog_input_line();
		FC.insert_line(ptr);
	}

	FC.write2file(fname);

	return 0;
}
