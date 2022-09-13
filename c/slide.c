/** another game program
 ** by tenzin
 ** 3/04/2004
 **/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define HEIGHT 3
#define WIDTH 5
#define HIGHLIGHT 2
#define NORMAL 1

typedef struct _block
{
	WINDOW *win;
	int startx, starty;
	short symbol;
}BLOCK;

static BLOCK *block;

bool ALIVE = TRUE;
bool WIN = FALSE;
static int border_x;
static int border_y;
int input_index;
int blankpos;

static short input[4][16] = {
				{3,5,7,1,0,14,9,12,15,2,4,13,6,8,10,11},
			     	{12,3,14,7,6,9,2,11,1,15,0,4,13,5,8,10},
			     	{9,15,8,12,6,14,10,13,1,2,11,3,7,4,0,5},
			 	{0,1,2,3,4,5,6,7,8,9,10,11,12,13,15,14}
			    };

static char conmess[] = "Congratulations!, You have done it!!";

void draw_border();
void allocate_and_draw_blocks();
void draw_block(BLOCK, int);
void start_game();
bool check_status();

int main()
{
	srand((int)time((long *)0));
	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	input_index = rand() % 4;
	draw_border();
	allocate_and_draw_blocks();
	start_game();
	if(WIN)
	{
		attron(COLOR_PAIR(3) | A_BOLD);
		mvprintw(LINES - 3,(COLS - strlen(conmess)) / 2,"%s", conmess);
		attroff(COLOR_PAIR(3) | A_BOLD);
	}
	getch();
	free(block);
	endwin();
}

void draw_border()
{
	WINDOW *win;
	int height, width, y, x;
	height = 17; width = 30;
	border_y = (LINES - height) / 2;
	border_x = (COLS - width) / 2;
	attron(COLOR_PAIR(5) | A_BOLD);
	box(stdscr, 0, 0);
	attroff(COLOR_PAIR(5) | A_BOLD);
	attron(COLOR_PAIR(3));
	mvprintw(1,1,"F9 to move block, F1 to exit.");
	attroff(COLOR_PAIR(3));
	refresh();
	win = newwin(height, width, border_y, border_x);
	wattron(win, COLOR_PAIR(4));
	box(win, 0, 0);
	wattroff(win, COLOR_PAIR(4));
	wrefresh(win);
}

void allocate_and_draw_blocks()
{
	int i, j, color;
	//init_pair(1, COLOR_RED, COLOR_BLACK);
	block = (BLOCK *)malloc(16 * sizeof(BLOCK));
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			int k = (i * 4) + j;
			block[k].starty = border_y + (HEIGHT * i) + (1 * (i + 1));
			block[k].startx = border_x + (WIDTH * j) + (2 * (j + 1));
			block[k].win = newwin(HEIGHT, WIDTH, block[k].starty, block[k].startx );
			if(input[input_index][k] != 15)
			{
				block[k].symbol = (65 + input[input_index][k]);
				color = NORMAL;
			}
			else
			{
				block[k].symbol = 32;
				blankpos = k;
				color = HIGHLIGHT;
			}
			draw_block(block[k], color);
		}
	}
}

void draw_block(BLOCK blk, int color)
{
	wattron(blk.win, COLOR_PAIR(color));
	box(blk.win, 0, 0);
	wattroff(blk.win, COLOR_PAIR(color));
	mvwprintw(blk.win, 1, 2, "%c", blk.symbol);
	wrefresh(blk.win);
}

void start_game()
{
	int old = blankpos;
	int new;
	short ch, temp;
	bool modify;
	ch = getch();
	while(ALIVE)
	{
		modify = TRUE;
		switch(ch)
		{
			case KEY_F(1) : free(block);
					endwin();
					exit(1);
			case KEY_UP : 	if((new = (old - 4)) < 0)
						new = old + 12;
					break;
			case KEY_DOWN : if((new = (old + 4)) > 15)
						new = old - 12;
					break;
			case KEY_LEFT : if((new = (old - 1)) < 0)
						new = 15;
					break;
			case KEY_RIGHT : if((new = (old + 1)) > 15)
						new = 0;
					 break;
			case KEY_F(9)   :if(old == blankpos)
					{
						modify = FALSE;
						break;
					}
					else
					{
						if(old < blankpos)
						{
							if(old == 3 || old == 7 || old == 11)
							{
								if(blankpos  == old + 4 )
									new = old + 4;
								else
									modify = FALSE;
							}
							else
							{
								if(old == 12 | old == 13 | old == 14)
								{
									if(blankpos == old + 1)
										new = old + 1;
									else
										modify = FALSE;
								}
								else
								{
									if(blankpos == old + 1)
										new = old + 1;
									else
									{
										if(blankpos == old + 4)
											new = old + 4;
										else
											modify = FALSE;
									}
								}
							}
						}
						else
						{
							if(old == 1 || old == 2 || old == 3)
							{
								if(blankpos == old - 1)
									new = old - 1;
								else
									modify = FALSE;
							}
							else
							{
								if(old == 4 || old == 8 || old ==12)
								{
									if(blankpos == old - 4)
										new = old - 4;
									else
										modify = FALSE;
								}
								else
								{
									if(blankpos == old - 1)
										new = old - 1;
									else
									{
										if(blankpos == old - 4)
											new = old - 4;
										else
											modify = FALSE;
									}
								}
							}
						}
					}
					if(modify)
					{
						block[new].symbol = block[old].symbol;
                        			block[old].symbol = 32;
						blankpos = old;
					}
					break;
			default :  modify = FALSE;
		}
		if(modify)
		{
			draw_block(block[old], NORMAL);
			draw_block(block[new], HIGHLIGHT);
			old = new;
		}
		WIN = check_status();
		if(WIN)
			ALIVE = FALSE;
		else
			ch = getch();
	}
					
}

bool check_status()
{
	int i;
	for(i = 0; i < 15; i++)
	{
		if(block[i].symbol != 65 + i)
			return FALSE;
	}
	return TRUE;
}
