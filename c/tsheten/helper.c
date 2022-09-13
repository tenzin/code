/** 
Program to write tsheten's video data into a file
**/

#include <stdio.h>
#include "helper.h"

int write_to_file(FILE *file, DataFormat data)
{
	int value;
	if(file == NULL)
		return -1;
	else
	{
		value = fprintf(file, "%d %d %s %s %d %d %d %s\n", data.frame_id, data.mb_id, data.mb_type, data.mb_code_mode, data.mv_x, data.mv_y, data.ref_list_idx, data.ref_pic);
	}
	return value;
}
