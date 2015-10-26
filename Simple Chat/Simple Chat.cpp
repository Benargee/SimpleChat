// Simple Chat.cpp : Defines the entry point for the console application.
//

//TODO: Add basic network functionality
//TODO: Add basic command parsing as it was in the old iostream based proof of concept

#include "stdafx.h"
#include <curses.h>
#include <thread>
#include <windows.h>
#include "simpleChatDefines.h"

using namespace std;

//TODO: Properly name variables and comment their functions
int ch, inx, iny, outx, outy; 
int row, col, cursx, cursy;
char mesg[MessageMaxSize];


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
	
	ch = getch();
	
	switch (ch)  
	{
	case 13:   //if enter is pressed, delete input line and reset input cursor position
		mvprintw(outy, 0, "%s", mesg);	// print message to chat
		move(row - 1, 0);
		memset(mesg, 0, sizeof mesg); //empty mesg[80] and get it ready for a new input message
		clrtoeol();
		iny = row - 1; 
		inx = 0;
		outy++;
		break;

	case 8: //backspace						
		if (inx > 0) // if cursor is already at the start of the line, do not bother backspacing characters
		{
			inx--;
			mvprintw(iny, inx, "%c", 32);
			move(row - 1, inx);
			mesg[inx] = '\0';//set charachter to null
		}
		break;

	default:
		if (inx < MessageMaxSize)
		{
			mvprintw(iny, inx, "%c", ch);
			mesg[inx] = ch;
			inx++;
		}
	}
	mvprintw(row - 2, 0, "Character limit:%i/%i  ", inx, MessageMaxSize); //Output current character count/maximum character count
	move(row - 1, inx);
	refresh();
	submain1();
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

