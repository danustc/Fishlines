/*
 * linenode.h
 *
 *  Created on: Oct 27, 2016
 *      Author: sillycat
 */

#ifndef SRC_LINENODE_H_
#define SRC_LINENODE_H_


using namespace std;
typedef long int size_t;

struct line_node{
	size_t z_number;
	struct line_node* father;
	struct line_node* mother;
	string genotype;

};


struct line_node* Node(size_t, string);


#endif /* SRC_LINENODE_H_ */
