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
	string comments;
};


struct line_node* Node(std::size_t znum, std::size_t zf, std::size_t zm, string geno, int*);
void add_comments(struct line_node *ptr);
string dob2string(struct line_node *ptr);
void string2dob(string dob, int *DOB);



class fish_catalog{
public:
	fish_catalog(struct line_node *root); // constructor with no arguments
	int insert_line(struct line_node* node); // Insert a line
	int delete_line(std::size_t z_num);
	void sort_line(void); // sort the fish lines
	void catalog_merge(fish_catalog *f_source, char sort_method);
	int search_catalog(std::size_t z_num); // search through the z_number list
	int get_size(void);
	line_node* get_node(int pos);
	int terminal_input(void);
	~fish_catalog(void); // destructor with no arguments


private:
	int n_count;
	vector<std::size_t> z_list;
	vector<line_node*> catalog;
};





#endif /* SRC_LINENODE_H_ */
