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

#include "linenode.h"


//Initialize a new newline node.
struct line_node* Node(std::size_t z_new, string geno_new){
	struct line_node* newline = new(struct line_node);
	newline -> father = NULL;
	newline -> mother = NULL;
	newline -> genotype = geno_new;

	return(newline);

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






