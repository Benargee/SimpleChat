//TODO: Rename file appropriately  
#pragma once
class msgSC //Single message
{
	char userName[UserNameMaxSize];//Username variable
	char message[MessageMaxSize];//Actual message text
	char time[20];//Delivery time of message. TODO: use different type for storing time
public:
	msgSC();
	~msgSC();
};



//
//==============================================================================//
// Extra classes. May need to be moved to new file or just have file renamed.

//Have an array of pointers to objects http://www.tutorialspoint.com/cplusplus/cpp_array_of_pointers.htm
class msgListSC //Message history list. There will only be a single instance of this object at a time.
{
	int lastMessage; //Points to the most recent message stored in the chat history
	int firstMessage; //Points to the oldest message in chat history. This will be the next message deleted out of the queue
	int *messageList[MessageHistorySize]; //This is the array that stores pointers to each message object
public:
	msgListSC();
	~msgListSC();
};

