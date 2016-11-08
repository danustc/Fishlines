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
#include<sys/stat.h>
#include "linenode.h"


// write a node into a file
void write_node(struct line_node* Node, ofstream &file_os){
	if(!Node) return;
	file_os << Node->z_number << '\t' << Node->genotype << '\t';
	file_os << Node->father->z_number << '\t' << Node->mother->z_number <<endl;

}

bool file_exists(const std::string & fname){
	struct stat buf;
	if (stat(fname.c_str(), &buf)!= -1)
		return true;
	return false;
}



// read a new node from a file


