// main.cpp : Defines the entry point for the console application.
//

//TODO: Add basic network functionality
//TODO: Add basic command parsing as it was in the old iostream based proof of concept

#include "stdafx.h"



//using namespace std;//-TODO: Refrain from using std

//TODO: Properly name variables and comment their functions
int ch, inx, iny, outx, outy; 
int row, col, cursx, cursy;
char mesg[MessageMaxSize];//text buffer for message input
bool command = false;//determines if chat input is in command mode or not

msgListHistorySC mainChatHistory;
msgListDispSC mainChatList;





//constantly output incrementing numbers until program is closed for debug purposes
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

//TODO: clean up input handling
int submain1()//TODO: Rename to more suitable name
{
	int cmdRet;
	bool runChat = true;
	while (runChat)
	{
		ch = getch();

		switch (ch)  //Take appropriate action when special characters are used
		{
		case 13:   //if enter is pressed, delete input line and reset input cursor position
			if (!command)//if chat is in command mode, do not print message to chat 
			{
				mvprintw(outy, 0, "%s", mesg);	// print message to chat
				inputChat(mesg,mainChatHistory,mainChatList);//New function to handle chat input
				//mainChatList.addMsg(mesg);
				outy++;//increment text output row
			}
			else 
			{
				command = false;
				//Launch command function here
				cmdRet =  doCMD(mesg);//TODO: temp name
				//break;
				if (cmdRet == 1)
					return 0;
				//runChat = false;
			}

			move(row - 1, 0);//return cursor to left of screen
			memset(mesg, 0, sizeof mesg); //empty mesg[MessageMaxSize] and get it ready for a new input message
			clrtoeol(); //clear to end of line
			iny = row - 1;
			inx = 0;

			break;

		case 8: //backspace						
			if (inx > 0) // if cursor is already at the start of the line, do not bother backspacing characters
			{
				inx--;
				mvprintw(iny, inx, "%c", 32);
				move(row - 1, inx);
				mesg[inx] = '\0';//set character to null

				if (inx == 0 && command)//if at first character and command mode is enabled
					command = false;//disable command mode
			}
			break;

		case 47:// "/" used for command mode. When first character is a "/" chat goes into command mode

			if (inx == 0)//if at first character, enter command mode
			{
				command = true;//enable command mode
			}
			//break;

		default:
			if (inx < MessageMaxSize)
			{
				mvprintw(iny, inx, "%c", ch);
				mesg[inx] = ch;
				inx++;
			}
		}
		mvprintw(row - 2, 0, "Character limit:%i/%i %i ", inx, MessageMaxSize, command); //Output current character count/maximum character count
		move(row - 1, inx);//return cursor to text entry field for visual purposes
		refresh();
	}
	return 0;	
}

int main()
{
	outy = 0;
	initscr();			/* Start curses mode 		*/

	getmaxyx(stdscr, row, col);//get terminal size/resolution
	move(row - 1, 0);// move cursor to bottom left of screen
	refresh();
	iny = row - 1;
	inx = 0;
	//curs_set(0); //cursor visibility
	raw();				/* Line buffering disabled	*/
	//keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */


	//std::thread outputThread(outputTimer);

	submain1();
	
	//TODO: need proper thread termination http://stackoverflow.com/questions/19744250/c11-what-happens-to-a-detached-thread-when-main-exits
	//outputThread.detach();
	//outputThread.~thread();

	refresh();
	endwin();

	//main();
	return 0;
}

