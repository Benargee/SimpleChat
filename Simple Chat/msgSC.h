//TODO: Rename file appropriately  

#pragma once

#include "simpleChatDefines.h"
#include "stdafx.h"

class msgSC //Single message
{
	char userName[UserNameMaxSize];//Username variable
	
	char time[20];//Delivery time of message. TODO: use different type for storing time
public:
	char message[MessageMaxSize];//Actual message text//TODO: Move back to private? //example access mainChatList.messageList[7].message
	msgSC();
	~msgSC();
};



//
//==============================================================================//
// Extra classes. May need to be moved to new file or just have file renamed.

//Have an array of pointers to objects http://www.tutorialspoint.com/cplusplus/cpp_array_of_pointers.htm https://www.gidforums.com/t-12539.html
class msgListHistorySC //Message history list. There will only be a single instance of this object at a time.
{
	int lastMessage = 0; //Points to the most recent message stored in the chat history
	int firstMessage = 0; //Points to the oldest message in chat history. This will be the next message deleted out of the queue
	msgSC messageList[MessageHistorySize]; //This is the array that stores pointers to each message object (msgSC)
public:
	msgListHistorySC();
	~msgListHistorySC();
	void addMsg();
};

//TODO: Add class/structure for the chat display. This will manage displayed chat history from overall chat history

class msgListDispSC //Message display list. There will only be a single instance of this object at a time.
{
	int lastMessage = 0;
	int firstMessage = 0;
	
public:
	msgSC messageList[MessageDisplaySize];//TODO move back to private ^^
	msgListDispSC();
	~msgListDispSC();
	void addMsg(char message[MessageMaxSize]);
	void scroll(int value);
	char* getMessage(int messageNumber); //gets messages in their intended order. getMessage(0) gets the most recent message

};


