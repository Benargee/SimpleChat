#include "Functions.h"
#include "stdafx.h"

void doCMD(char input[MessageMaxSize]) {
	char * splitInput;//Command and arguments for strtok_s
	int argCount = 0;
	char *next_token = NULL;//(strtok_s)
	char seps[] = " ";
	
	mvprintw(2, 2, "CMD %s ", input);//debug TODO
	splitInput = strtok_s(input, seps, &next_token);
	while (splitInput != NULL)
	{
		mvprintw(3 + argCount, 20, "split: %X-%c:%X", splitInput, input, next_token);//debug TODO
		splitInput = strtok_s(NULL, seps, &next_token);

		argCount++;
	}

	refresh();
	refresh();

}

