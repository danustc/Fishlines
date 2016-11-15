/*
 * database_io.h
 *
 *  Created on: Nov 8, 2016
 *      Author: sillycat
 */

#ifndef INCLUDES_DATABASE_IO_H_
#define INCLUDES_DATABASE_IO_H_



bool file_exists(const std::string & fname);
line_node* catalog_input_line(void);
void catalog_printout(fish_catalog *FC);
void catalog_write_spreadsheet(const std::string & fname, fish_catalog *FC);
void catalog_read_spreadsheet(const std::string & fname, fish_catalog *FC);

#endif /* INCLUDES_DATABASE_IO_H_ */
