/*
 * catalog.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: sillycat
 */


#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include"linenode.h"


fish_catalog::fish_catalog(void){
	n_count = 0;


}// Initialization of the class


bool fish_catalog::search_catalog(std::size_t z_num){
	// Search through the z-number list to check if the line represented by z_num exists.
	return (std::find(z_list.begin(), z_list.end(), z_num) != z_list.end());
} // return true or false




int fish_catalog::insert_line(struct line_node *new_node){
/*
 *assume new_node is not empty: it has all the essential informations: z-number, zf, zm, DOB, genotype.
 */
	int status = -1;

	if(!search_catalog(new_node->z_number)){
		// if the new_node's z-number is not in the data base
		z_list.push_back(new_node->z_number);
		std::size_t zf = new_node->zf;
		std::size_t zm = new_node->zm;

		std::size_t pos_f = std::find(z_list.begin(), z_list.end(), zf) - z_list.begin();
		if(pos_f < n_count)
			new_node->father = catalog[pos_f];

		std::size_t pos_m = std::find(z_list.begin(), z_list.end(), zm) - z_list.begin();
		if(pos_m < n_count)
			new_node->mother = catalog[pos_m];

		catalog.push_back(new_node);
		n_count ++;
		status = 0;
	}

	return status;
} // insert a line


void fish_catalog::write2file(string fname){
	line_node* ptr = NULL;

	for(std::vector<line_node*>::iterator line_it = catalog.begin(); line_it!=catalog.end(); ++line_it){
		ptr = *line_it;
		cout<< ptr->z_number <<'\t'<< ptr->zf << '\t' << ptr->zm <<endl;
	} //end for
	cout << "The data base saved as " << fname.c_str() << endl;
}// write into a file


fish_catalog::~fish_catalog(void){
	z_list.clear();
	for(std::vector<line_node*>::iterator iit = catalog.begin(); iit!=catalog.end(); ++iit)
		delete *iit;
	catalog.clear();

}
