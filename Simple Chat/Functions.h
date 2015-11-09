#pragma once

#include "msgSC.h"

int doCMD(char input[]);

void inputChat(char *inputMessage, msgListHistorySC& ListHistoryOBJ, msgListDispSC& ListDisplayOBJ);//Locally add entry to chat. From here messages will be handled and displayed to chat.

void sendMessage();//TODO: using this command will send a message to all connected clients. it will be sent to the server and then distributed to the clients
