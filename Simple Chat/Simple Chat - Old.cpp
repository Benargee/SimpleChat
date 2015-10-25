// Simple Chat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int mainChat()
{
	string MainPrompt;
	getline(cin, MainPrompt);//Puts whole line into variable with spaces http://stackoverflow.com/questions/5838711/c-cin-input-with-spaces
	
	if (MainPrompt == "/server")//TODO use hash with switch for commands http://stackoverflow.com/questions/16388510/evaluate-a-string-with-a-switch-in-c http://stackoverflow.com/questions/2535284/how-can-i-hash-a-string-to-an-int-using-c
	{
		cout << "hosting server..." << endl;
		mainChat();
	}
	else if (MainPrompt == "/client")
	{
		cout << "searching for server..." << endl;
		mainChat();
	}
	else if (MainPrompt == "/help")
	{
		cout << "Help Menu:\nType ""/server"" to host a chat server\nType ""/client"" to search for a Chat server\nType ""/help"" for list of accepted commands\nType ""/exit"" to quit Simple Chat\nAll commands are case sensitive!" << endl;
		mainChat();
	}
	else if (MainPrompt == "")
	{
		cout << "ERROR: No text was received!" << endl;
		mainChat();
	}
	else if (MainPrompt == "/exit")
	{
		cout << "Exiting application" << endl;
		return 2;
	}
	else
	{
		cout << "ERROR: Invalid command!" << endl;
		mainChat();
	}
	//cout  << MainPrompt[0] << endl;
	//system("pause");//Replace with better pause function!
	
}

int main()
{
	cout << "Welcome to Benargee's Simple Chat.\nType ""/server"" to host a chat server\nType ""/client"" to search for a Chat server\nType ""/help"" for list of accepted commands\nAll commands are case sensitive!" << endl;
	int ret = mainChat();
	return ret;
}

