//TODO: Rename file appropriately
#include "stdafx.h"
#include "msgSC.h"


msgSC::msgSC()
{
}


msgSC::~msgSC()
{
}


// Extra classes. May need to be moved to new file or just have file renamed.
//msgListHistorySC
msgListHistorySC::msgListHistorySC()
{
	lastMessage = 0;
	firstMessage = 0;
}


msgListHistorySC::~msgListHistorySC()
{
}

void msgListHistorySC::addMsg()
{
	lastMessage++;
	if (lastMessage >= MessageHistorySize) {
		lastMessage = 0;
	}
}

//msgListDispSC
msgListDispSC::msgListDispSC()
{
	//lastMessage = 0;
	//firstMessage = 0;
	//Add code to fill list with objects

}

msgListDispSC::~msgListDispSC()
{
}

void msgListDispSC::addMsg(char message[MessageMaxSize])
{
	//msgSC* newMSG = new msgSC;//http://stackoverflow.com/questions/6337294/creating-an-object-with-or-without-new
	strncpy_s(messageList[lastMessage].message, MessageMaxSize, message, _TRUNCATE);
	//messageList[lastMessage].message = message;
	lastMessage++;
	if (lastMessage >= MessageDisplaySize) {
		lastMessage = 0;
	}

}
void msgListDispSC::scroll(int value)
{
}
