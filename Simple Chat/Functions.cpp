#include "Functions.h"
#include "stdafx.h"

//Get command name and store it
//get arguments and store them. String literals are a single argument
//BUG!! When just typing in "/" program will crash! look at _stricmp()
int doCMD(char input[MessageMaxSize], msgListHistorySC& ListHistoryOBJ, msgListDispSC& ListDisplayOBJ) {
	input++; //ignore "/"
	char *splitInput;//Command and arguments for strtok_s
	int argCount = 0;
	char *next_token = NULL;//(strtok_s)
	char seps[] = " ";
	
	//mvprintw(2, 2, "CMD %s ", input);//debug TODO
	splitInput = strtok_s(input, seps, &next_token);
	char *command = splitInput;//stores the command
	while (splitInput != NULL)
	{
		mvprintw(3 + argCount, 20, "cmd: %s arg:%i SI:%s", command, argCount, splitInput);//debug TODO
		splitInput = strtok_s(NULL, seps, &next_token);

		argCount++;
	}

	if (_stricmp(command,"exit") == 0)//Case insensitive string comparison
	{
		//Exit application
		//mvprintw(3 + argCount, 20, "EXIT");//debug TODO]
		return 1;
	}else if (_stricmp(command, "help") == 0)
	{
		//Open help window
		mvprintw(3 + argCount, 20, "HELP");//debug TODO
	}

	refresh();
	return 0;
}

//(FIXED)Currently this function makes a local copy of the object instead of modifying the original object http://stackoverflow.com/questions/1698660/when-i-change-a-parameter-inside-a-function-does-it-change-for-the-caller-too
/**/

//input entry into chat and update display. 
void inputChat(char *inputMessage, msgListHistorySC& ListHistoryOBJ, msgListDispSC& ListDisplayOBJ){
	ListDisplayOBJ.addMsg(inputMessage);
	updateDisplay(ListDisplayOBJ); //after msg has been added, update display

}



void updateDisplay(msgListDispSC& ListDisplayOBJ){
//do a for loop for each display line and mvprint() accordingly. then refresh.
	for (int x = 0; x < MessageDisplaySize; x++) {
		mvprintw(x, 0, "%s", ListDisplayOBJ.getMessage(x));
		clrtoeol();
	}
};


