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
#include"database_io.h"

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
			new_node->father->father_of.push_back(new_node->z_number);
		} //endif

		int pos_m = search_catalog(zm);
		if(pos_m < n_count){
			cout <<"mother line found. "<<endl;
			new_node->mother = catalog[pos_m];
			new_node->mother->mother_of.push_back(new_node->z_number);
		}

		// Now, check the offsprings
		if(!new_node->father_of.empty()){
			int n_search;
			for (vector<std::size_t>::iterator fit = new_node->father_of.begin(); fit!=new_node->father_of.end(); ++fit){
				n_search = search_catalog(*fit);
				if(n_search < n_count){
					line_node* nptr = catalog[n_search];
					nptr->father = new_node;
				} // endif
			}//end for

		} // update offspring - father - mother

		if(!new_node->mother_of.empty()){
			int n_search;
			for (vector<std::size_t>::iterator fit = new_node->mother_of.begin(); fit!=new_node->mother_of.end(); ++fit){
				n_search = search_catalog(*fit);
				if(n_search < n_count){
					line_node* nptr = catalog[n_search];
					nptr->mother = new_node;
				} // endif
			}//end for

		} // update offspring - father - mother



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


int fish_catalog::terminal_input(void){
	int cnt = 0, sta = -1;
	char status = 'y';
	do{

		line_node * ptr = catalog_input_line();
		sta = insert_line(ptr);
		if(sta == 0){
			cnt ++;
			cout << "Input successful! Input more lines? Yes(Y/y), No (N/n): ";
			cin >> status;
		}
		else
			break; // break from the while loop
	}while(status =='Y' || status =='y');


	return cnt;
} // terminal_input



int fish_catalog::get_size(void){
	int n_size = n_count;
	return n_size;
}//getsize

line_node* fish_catalog::get_node(int pos){
	line_node *ptr = catalog[pos];
	return ptr;
}


void fish_catalog::catalog_merge(fish_catalog *fc_source, char sort_method = 'd'){
	/*
	 * Merge two catalog's contents; check for duplication and save all the contents in fc_dest.
	 * start from the z_lists. check if the elements in fc_source exists in the local database.
	 */
	int icount, n_source = fc_source->get_size();
	int status = -1;
	line_node* ptr = NULL;
	for (icount = 0; icount < n_source; ++icount){
		ptr = fc_source->get_node(icount);
		if(search_catalog(ptr->z_number) == n_count)
			status = insert_line(ptr);
		if(status ==-1)
			break;
	}//end for

} // merge two catalogs.


void fish_catalog::output_lineage(std::size_t z_num, bool ifsave = false){
	/*
	 * Output the lineage of the selected line z_num
	 * Trace back first, then trace down.
	 */
	int pos = search_catalog(z_num);
	if(pos == n_count)
		cout<< "Error! The line "<< z_num << " is not in the data base." <<endl;
	else{ // output the ancestors of the output:
		line_node *zptr = get_node(pos);
		cout<< "The paternal ancestors of the line " << z_num <<':'<<endl;
		cout<< zptr-> zf <<endl;
		if(zptr->father!=NULL)


		cout<< "The naternal ancestors of the line " << z_num <<':'<<endl;
		cout<< zptr-> zm <<endl;

	} // end else

}




fish_catalog::~fish_catalog(void){
	z_list.clear();
	for(std::vector<line_node*>::iterator iit = catalog.begin(); iit!=catalog.end(); ++iit)
		delete *iit;
	catalog.clear();

}


