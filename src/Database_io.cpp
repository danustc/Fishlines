/*
 * Database_io.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: sillycat
 *      This file deals with input-output of the database.
 */

#include<iostream>
#include<fstream>
#include<string>
#include "linenode.h"


void Load_spreadsheet(string fname, struct line_node* base_hand){
	ifstream spreadsheet(fname);
	string line;
	if (spreadsheet.is_open()){
		while (getline(spreadsheet,line)){
		      cout << line << '\n';
		      /*
		       * should I add some python string parsing functions here?
		       */

		    }
		spreadsheet.close();

	} //endif
}

