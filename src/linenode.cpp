/*
 * linenode.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: sillycat
 */


#include<cstdlib>
#include<cstddef>
#include<string>
#include<iostream>
#include<sstream>
#include "linenode.h"


//Initialize a new newline node.
struct line_node* Node(std::size_t z_new, std::size_t zf, std::size_t zm, string geno_new, int *dob){
	struct line_node* newline = new(struct line_node);
	newline -> z_number = z_new;
	newline -> zf = zf;
	newline -> zm = zm;
	newline -> father = NULL;
	newline -> mother = NULL;
	newline -> genotype = geno_new;

	for(int ii = 0; ii < 3; ++ii)
		newline -> DOB[ii] = dob[ii];

	return newline;

}

void Father(struct line_node* F1, struct line_node* F0){
	if (F1 -> father == NULL)
		F1 -> father = F0;
	else
		cout<<"The father of " << F1->z_number << " has been assigned."<<endl;
} // end Father assignment


void Mother(struct line_node* F1, struct line_node* F0){
	if(F1 -> mother == NULL)
		F1 -> mother = F0;
	else
		cout<<"The mother of " << F1->z_number << " has been assigned."<<endl;
} // end Mother assignment


void add_comments(struct line_node* ptr){
	cout << "Comments for" << ptr->z_number << endl;
	cin >> ptr->comments;
}



string dob2string(struct line_node *ptr){
	std::ostringstream dob_str;
	dob_str << ptr->DOB[0] << '/'<<ptr-> DOB[1] <<'/' << ptr->DOB[2];
	return dob_str.str();
}


void string2dob(std::string dob, int *DOB){
	std::istringstream dob_str(dob);
	char delim[2];
	dob_str >> DOB[0] >> delim[0] >> DOB[1] >> delim[1] >> DOB[2];
}
