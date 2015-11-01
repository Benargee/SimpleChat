#include "Functions.h"
#include "stdafx.h"

//Get command name and store it
//get arguments and store them. String literals are a single argument
int doCMD(char input[MessageMaxSize]) {
	input++; //ignore "/"
	char *splitInput;//Command and arguments for strtok_s
	int argCount = 0;
	char *next_token = NULL;//(strtok_s)
	char seps[] = " ";
	
	mvprintw(2, 2, "CMD %s ", input);//debug TODO
	splitInput = strtok_s(input, seps, &next_token);
	char *command = splitInput;//stores the command
	while (splitInput != NULL)
	{
		mvprintw(3 + argCount, 20, "split: %s-%s:%s", command, next_token, splitInput);//debug TODO
		splitInput = strtok_s(NULL, seps, &next_token);

		argCount++;
	}

	if (strcmp (command,"exit") == 0)
	{
		//Exit application
		//mvprintw(3 + argCount, 20, "EXIT");//debug TODO]
		return 1;
	}else if (strcmp(command, "help") == 0)
	{
		//Open help window
		mvprintw(3 + argCount, 20, "HELP");//debug TODO
	}

	refresh();
	refresh();
	return 0;
}

