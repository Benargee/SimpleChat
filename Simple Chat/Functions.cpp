#include "Functions.h"
#include "stdafx.h"

//Get command name and store it
//get arguments and store them. String literals are a single argument
//BUG!! When just typing in "/" program will crash! look at _stricmp()
int doCMD(char input[MessageMaxSize]) {
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
		mvprintw(3 + argCount, 20, "split: %s-%s:%s", command, next_token, splitInput);//debug TODO
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
	refresh();
	return 0;
}

//Currently this function makes a local copy of the object instead of modifying the original object http://stackoverflow.com/questions/1698660/when-i-change-a-parameter-inside-a-function-does-it-change-for-the-caller-too
/**/
void inputChat(char *inputMessage, msgListHistorySC& ListHistoryOBJ, msgListDispSC& ListDisplayOBJ){
	ListDisplayOBJ.addMsg(inputMessage);

}