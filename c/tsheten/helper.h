/** 
Program to write tsheten's video data into a file
**/

#ifndef helper_h
#define helper_h

typedef struct
{
	int frame_id;
	int mb_id;
	char *mb_type;
	char *mb_code_mode;
	int mv_x;
	int mv_y;
	int ref_list_idx;
	char *ref_pic;
} DataFormat;

int write_to_file(FILE *, DataFormat );

#endif
