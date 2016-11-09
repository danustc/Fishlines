/*
 * catalog.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: sillycat
 */


#include<iostream>
#include<algorithm>
#include<vector>
#include"linenode.h"


fish_catalog::fish_catalog(struct line_node *root){
	n_count = 0;
	if(root !=NULL){
		z_list.push_back(root->z_number);
		catalog.push_back(root);
		n_count++;
	}


}// Initialization of the class


int fish_catalog::search_catalog(std::size_t z_num){
	// Search through the z-number list to check if the line represented by z_num exists.
	return (std::find(z_list.begin(), z_list.end(), z_num) - z_list.begin());
} // return true or false




int fish_catalog::insert_line(struct line_node *new_node){
/*
 *assume new_node is not empty: it has all the essential informations: z-number, zf, zm, DOB, genotype.
 */
	int status = -1;

	if(search_catalog(new_node->z_number) == n_count){
		// if the new_node's z-number is not in the data base
		z_list.push_back(new_node->z_number);
		std::size_t zf = new_node->zf;
		std::size_t zm = new_node->zm;

		int pos_f = search_catalog(zf);
		if(pos_f < n_count){
			cout <<"father line found. "<<endl;
			new_node->father = catalog[pos_f];
		} //endif

		int pos_m = search_catalog(zm);
		if(pos_m < n_count){
			cout <<"mother line found. "<<endl;
			new_node->mother = catalog[pos_m];
		}
		catalog.push_back(new_node);
		n_count ++;
		status = 0;
	}

	return status;
} // insert a line


int fish_catalog::delete_line(std::size_t z_num){
	int status = -1;
	int z_pos = search_catalog(z_num);
	if(z_pos < n_count){
		catalog[z_pos]->father = NULL;
		catalog[z_pos]->mother = NULL;
		catalog.erase(catalog.begin()+z_pos);
		z_list.erase(z_list.begin()+z_pos);
		n_count--;
		status = 0;
	}

	return status;
} // delete a line


int fish_catalog::get_size(void){
	int n_size = n_count;
	return n_size;
}//getsize

line_node* fish_catalog::get_node(int pos){
	line_node *ptr = catalog[pos];
	return ptr;
}



fish_catalog::~fish_catalog(void){
	z_list.clear();
	for(std::vector<line_node*>::iterator iit = catalog.begin(); iit!=catalog.end(); ++iit)
		delete *iit;
	catalog.clear();

}
