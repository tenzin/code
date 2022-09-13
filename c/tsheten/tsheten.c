/** 
Program to write tsheten's video data into a file
**/

#include <stdio.h>
#include "helper.h"

int main ()
{
	/**test data**/
	DataFormat data;
	data.frame_id = 0;
	data.mb_id = 2;
	data.mb_type = "B";
	data.mb_code_mode = "intra";
	data.mv_x = -2;
	data.mv_y = 34;
	data.ref_list_idx = 5;
	data.ref_pic = "G";
	
	/** Open File  **/
	FILE *file;
	file = fopen("test-file.txt", "a+");
	
	/** Now write the data into the file **/
	if (write_to_file(file, data) > 0)  /** this function is defined in helper.c **/
		printf("File written successfully\n");
	else
		printf("Error writing file\n");
	fclose(file);
	return 0;
}
