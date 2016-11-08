/*
 * linenode.h
 *
 *  Created on: Oct 27, 2016
 *      Author: sillycat
 */

#ifndef SRC_LINENODE_H_
#define SRC_LINENODE_H_

#include<cstddef>
#include<vector>
#include<string>
using namespace std;



struct line_node{
	std::size_t z_number;
	std::size_t zf, zm; // The z-number of parents
	struct line_node* father;
	struct line_node* mother;
	string genotype;
	std::size_t DOB[3]; // date of birth, month-date-year.
	bool comp_info;
};


struct line_node* Node(std::size_t, string);
string dob2string(struct line_node *ptr);

class fish_catalog{
public:
	fish_catalog(struct line_node *root); // constructor with no arguments
	int insert_line(struct line_node* node); // Insert a line
	bool search_catalog(std::size_t z_num); // search through the z_number list
	void write2file(string fname); // write all the lines into a spreadsheet file
	~fish_catalog(void); // destructor with no arguments


private:
	std::size_t n_count;
	vector<std::size_t> z_list;
	vector<line_node*> catalog;
};




#endif /* SRC_LINENODE_H_ */
