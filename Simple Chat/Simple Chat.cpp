// Simple Chat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string MainPrompt;
	cout << "Welcome to Benargee's Simple Chat.\nType ""/server"" to host a chat server\nType ""/client"" to search for a Chat server\nType ""/help"" for list of accepted commands\nAll commands are case sensitive!" << endl;
	getline(std::cin,MainPrompt);//Puts whole line into variable with spaces http://stackoverflow.com/questions/5838711/c-cin-input-with-spaces
	if (MainPrompt == "/server")//TODO use hash with switch for commands http://stackoverflow.com/questions/16388510/evaluate-a-string-with-a-switch-in-c http://stackoverflow.com/questions/2535284/how-can-i-hash-a-string-to-an-int-using-c
	{
		cout <<"hosting server..." << endl;
	}
	else if (MainPrompt == "/client")
	{
		cout << "searching for server..." << endl;
	}
	else if (MainPrompt == "/help")
	{
		cout << "Help Menu:\nType ""/server"" to host a chat server\nType ""/client"" to search for a Chat server\nType ""/help"" for list of accepted commands\nAll commands are case sensitive!" << endl;
	}
	//cout  << MainPrompt[0] << endl;
	system("pause");//Replace with better pause function!
	return 0;
}

