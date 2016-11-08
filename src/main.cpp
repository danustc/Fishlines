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
	if(argc > 0){
		//if the number of arguments is non-zero
		fname = argv[0]; // catch the filename
		if (!file_exists(fname))
			cout << "The database file does not exist."<<endl;
		else
			cout << "The database file exists." <<endl;
	}
	else{
		cin >> fname;
	}


	fish_catalog FC;
	std::size_t z_num, zf, zm;
	cout << "Please enter the fish number"<<endl;
	cin >> z_num;
	cout << "The new z_number is: " << z_num << endl;
	cout <<

	FC.write2file(fname);

	return 0;
}
