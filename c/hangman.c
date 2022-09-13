/** a game program
 ** @tenzin
 ** 25/04/2004
 ** -----------
 **colors and border applied - 1/05/2004
 **/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define CHV '|'
#define CHH '_'
#define CRH '\\'
#define CLH '/'

struct key_rec
{
	char keys[26];
	int index;
};

struct key_rec record;
bool ALIVE;
bool WIN;
static int X;
static int Y;
static char string[20];
static char fname[20];
static int LEN;
static int HIT;

void display_gallows();
void wrong_key(int);
bool is_keyed(short);
void init_game();
void display_fields();
void start_game();

int main(int argc, char *argv[])
{
	char *message = "A HANGMAN IMPLEMENTATION BY TENZIN";
	int y, x;
	if(argc == 1)
		strcpy(fname,"file");
	else
		strcpy(fname,argv[1]);

	srand((int)time((long *)0));
	short ch = 'y';
	while(ch == 'y' || ch == 'Y')
	{
		init_game(argc);
		initscr();
		raw();
		noecho();
		start_color();
		keypad(stdscr, TRUE);

		y = 4;
		x = (int)((COLS - strlen(message)) / 2);
		clear();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		
		attron(COLOR_PAIR(1) | A_BOLD);
		box(stdscr, 0, 0);
		attroff(COLOR_PAIR(1) | A_BOLD);
		attron(COLOR_PAIR(2) | A_BOLD);
		mvprintw(y, x, "%s", message);
		attroff(COLOR_PAIR(2) | A_BOLD);
		display_gallows();
		display_fields();
		start_game();
		if(WIN)
		{
			attron(A_BOLD | A_BLINK);
			mvprintw(7,40,"You Win!");
			attroff(A_BLINK);
			mvprintw(9,35,"Congragulations!");
			attroff(A_BOLD);
		}
		else
		{
			attron(A_BOLD | A_BLINK);
			mvprintw(7,40,"You Lose!");
			attroff(A_BLINK);
			mvprintw(9,33,"The correct answer is :");
			//attron(A_UNDERLINE);
			mvprintw(11,35,"\"%s\"",string);
			//attroff(A_UNDERLINE);
			attroff(A_BOLD);
		}
		mvprintw(Y+5,X-7,"Do you want to play again? ");
		ch=getch();
		refresh();
		endwin();
	}
}
void display_fields()
{
	int i;
	X=45-(LEN/2);
	for(i=0;i<(LEN*2);i=i+2)
		mvprintw(Y,X+i,"%c",CHH);
	mvprintw(Y+4,X,"Key-in a letter");
	mvprintw(1, COLS - 20, "Press F1 to exit.");
	refresh();
}

void start_game()
{
	short ch;
	bool b,match,clear=TRUE;
	int i,x;
	int error=1;
	while(ALIVE)
	{
		match=FALSE;
		ch=getch();
		if(ch == KEY_F(1))
		{
			endwin();
			exit(1);
		}
		b=is_keyed(ch);
		if(b)
		{
			mvprintw(Y+6,X-5,"key already entered");
			clear=FALSE;
			continue;
		}
		else
		{
			if(!clear)
				mvprintw(Y+6,X-5,"                   ");
			for(i=0;i<LEN;i++)
			{
				if(ch==string[i] || ch==toupper(string[i]))
				{
					HIT++;
					x=X+(2*i);
					mvprintw(Y-1,x,"%c",ch);
					refresh();
					if(!match)
						match=TRUE;
					if(HIT==LEN)
					{
						ALIVE=FALSE;
						WIN = TRUE;
					}
				}
			}
		}
		if(!match)
		{
			wrong_key(error);
			refresh();
			error++;
		}
	}
}


void display_gallows() /* gallows */
{
	int i,j;
	for(j=8;j<19;j++) /* horizontal line */
		mvprintw(10,j,"%c",CHH);
	for(i=9;i<20;i++) /* vertical line */
		mvprintw(i,10,"%c",CHV);
	attron(A_BOLD);
	mvprintw(21,9,"The Gallows !");
	attroff(A_BOLD);
	refresh();
}


void wrong_key(int err)
{
	/*the actual action*/
	int i,j;
	switch(err)
	{
		case 1 :for(i=10;i<12;i++) /* noose */
			mvprintw(i,16,"%c",CHV);
			refresh();
			break;

		case 2 :mvprintw(12,15,"(");/* head */
			mvprintw(12,17,")");
			refresh();
			break;

		case 3 :for(i=13;i<17;i++)/* body */
			mvprintw(i,16,"%c",CHV);
			refresh();
			break;

		case 4 :j=15;/* right hand */
			for(i=14;i>12;i--)
			{
				mvprintw(i,j,"%c",CRH);
				j--;
			}
			refresh();
			break;

		case 5 :j=17;/* left hand */
			for(i=14;i>12;i--)
			{
				mvprintw(i,j,"%c",CLH);
				j++;
			}
			refresh();
			break;

		case 6 :j=15;/* right leg */
			for(i=17;i<19;i++)
			{
				mvprintw(i,j,"%c",CLH);
				j--;
			}
			refresh();
			break;

		case 7 :j=17;
			for(i=17;i<19;i++)
			{
				mvprintw(i,j,"%c",CRH);
				j++;
			}
			refresh();
			ALIVE=FALSE;
	}
}

void init_game()
{
	int i,j;
	FILE *fin;
	fin=fopen(fname,"r");
	if(!fin)
	{
		printf("error opening file %s\n",fname);
		exit(1);
	}
	i=rand()%15;
	for(j=0;j<i;j++)
	{
		if((fgets(string,20,fin)) == NULL)
		{
			printf("error reading file\n");
			exit(1);
		}
	}
	fclose(fin);
	string[strlen(string) - 1]='\0';
	LEN=strlen(string);
	record.index=-1;
	ALIVE = TRUE;
	WIN = FALSE;
	HIT = 0;
	Y = 15;
}

bool is_keyed(short ch)
{
	if(record.index==-1)
	{
		record.index++;
		record.keys[record.index]=ch;
		return FALSE;
	}
	else
	{
		int i;
		for(i=0;i<=record.index;i++)
		{
			if(record.keys[i] == ch)
				return TRUE;
		}
		record.index++;
		record.keys[record.index]=ch;
		return FALSE;
	}
}
