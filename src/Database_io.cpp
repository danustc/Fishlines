/*
 * Database_io.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: sillycat
 *      This file deals with input-output of the database.
 */

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sys/stat.h>
#include "linenode.h"
#include "database_io.h"


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


line_node* catalog_input_line(){
	char accept;
	line_node *nptr = new line_node; //Initialize a new node
	do{
		cout << "Please enter the z-number of the new line, father, mother: "<<endl;
		cin >> nptr->z_number >> nptr->zf >> nptr->zm;
		cout << "The new line has the z_number:" << nptr->z_number << endl;
		cout << "The parental lines are:" << nptr->zf << '\t' << nptr->zm << endl;
		cout << "put in the new-line? Yes(Y/y), No(N/n): ";
		cin >> accept;
	}while(accept!='Y' && accept!='y');

	accept = 'n';

	do{
		cout << "Please enter the date of birth in the format of mm, dd, yy "<<endl;
		cin >> nptr->DOB[0] >> nptr->DOB[1] >> nptr->DOB[2];
		cout << "The new line has the date of birth:" << '\t' ;
		cout << nptr->DOB[0]<<'/'<<nptr->DOB[1]<<'/'<<nptr->DOB[2]<<endl;
		cout << "DOB correct? Yes(Y/y), No(N/n): ";
		cin >> accept;
	}while(accept!='Y' && accept!='y');

	accept = 'n';

	do{
		cout << "Please enter the genotype of the line:"<< endl;
		cin >> nptr->genotype;
		cout << "The entered genotype is:" << nptr->genotype.c_str() <<endl;
		cout << "genotype correct? Yes(Y/y), No(N/n): ";
		cin >> accept;
	}while(accept !='Y' && accept!='y');


	nptr->father = NULL;
	nptr->mother = NULL;

	return nptr;
} // input



void catalog_write_spreadsheet(const std::string & fname, fish_catalog *FC){
	std::ofstream outfile(fname.c_str());
	line_node* ptr = NULL;
	int n_size = FC->get_size();
	outfile<< "#line" <<'\t'<< "#father" << '\t' << "#mother" << '\t';
	outfile<< "Date of birth" << '\t'<< "Genotype" <<endl;

	for(int ii = 0; ii < n_size; ii++){
		ptr = FC->get_node(ii);
		outfile<< ptr->z_number <<'\t'<< ptr->zf << '\t' << ptr->zm << '\t';
		outfile<< dob2string(ptr)<< '\t' << ptr->genotype <<'\n';
		cout << dob2string(ptr)<<endl;
	} //end for


	cout << "The data base saved as " << fname.c_str() << endl;
	outfile.close();
}


// read a new node from a file

void catalog_read_spreadsheet(const std::string & fname, fish_catalog &FC){
	std::ifstream infile(fname.c_str());
	std::size_t z_num, zf, zm;
	std::string dobs, genotype;
	string line;
	int DOB[3];
	std::getline(infile, line);
	cout << line <<endl;

	while(infile >> z_num >> zf >> zm >> dobs){
		std::getline(infile, genotype);
		genotype.erase(genotype.end()-1, genotype.end());
		string2dob(dobs, DOB);
		line_node *new_node = Node(z_num, zf, zm, genotype, DOB);
		FC.insert_line(new_node);
	};


	infile.close();
}
