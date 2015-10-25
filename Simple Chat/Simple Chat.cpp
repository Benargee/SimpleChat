// Simple Chat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <curses.h>
#include <thread>
#include <windows.h>

using namespace std;

int ch, inx, iny, outx, outy;
int row, col, cursx, cursy;
char mesg[500];


//constantly output incrementing numbers untill program is closed
void outputTimer() {
	int mynum;

	for (mynum = 0; mynum <= 15; mynum++)
	{
		//getyx(stdscr, cursy, cursx);
		mvprintw(outy, 0, "Sample message %i", mynum);
		outy++;
		//printw("%i %i %i\n", mynum, cursy, iny);
		move(row - 1, inx);
		refresh();
		Sleep(3000);

	}
	//refresh();
	/*add function to start printing from bottom and shift rows up. history could be stored in a pointer array  to strings of 500 character lengths. struct could be used for this?
	data will be stored in memory and then printed from memory.*/
}


void submain1()
{
	//char mychar;
	ch = getch();
	//mvaddch(20, 5, ch);

	switch (ch)  //if enter is pressed, delete input line and reset input cursor position
	{
	case 13:   //if enter is pressed, delete input line and reset input cursor position
		mvprintw(outy, 0, "%s", mesg);	// print message to chat
		move(row - 1, 0);
		memset(mesg, 0, sizeof mesg); //empty mesg[80] and get it ready for a new input message
		clrtoeol();
		refresh();
		iny = row - 1;
		inx = 0;


		outy++;
		submain1();

	case 8: //backspace						
		if (inx > 0) // if cursor is already at the start of the line, do not bother backspacing characters
		{
			inx--;
			mvprintw(iny, inx, "%c", 32);
			move(row - 1, inx);
			mesg[inx] = '\0';//set charachter to null
		}
		refresh();
		submain1();


	default:
		mvprintw(20, 20, "%i %i", ch, inx);	 //debug, print character as an integer on screen
		mvprintw(iny, inx, "%c", ch);
		mesg[inx] = ch;
		inx++;
		refresh();
		submain1();
	}

}

int main()
{
	outy = 0;
	char str[80];
	initscr();			/* Start curses mode 		*/

	getmaxyx(stdscr, row, col);
	move(row - 1, 0);// move cursor to bottom left of screen
	refresh();
	iny = row - 1;
	inx = 0;
	//curs_set(2); //cursor visibility
	raw();				/* Line buffering disabled	*/
						//keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */


	thread outputThread(outputTimer);

	submain1();

	refresh();
	endwin();

	//main();
	return 0;
}

