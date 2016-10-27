/*
 * linenode.cpp
 *
 *  Created on: Oct 26, 2016
 *      Author: sillycat
 */


#include<cstdlib>
#include<cstddef>
#include<string>

using namespace std;

typedef long int size_t;

struct line_node{
	size_t z_number;
	struct line_node* father;
	struct line_node* mother;
	string genotype;

};


//Initialize a new newline node.
struct line_node* Node(size_t z_new, string geno_new ){
	struct line_node* newline = new(struct line_node);
	newline -> father = NULL;
	newline -> mother = NULL;
	newline -> genotype = geno_new;

	return(newline);

}

void Father(struct line_node* F1, struct line_node* F0){
	F1 -> father = F0;
}


void Mother(struct line_node* F1, struct line_node* F0){
	F1 -> mother = F0;
}



