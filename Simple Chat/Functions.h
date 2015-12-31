#pragma once

#include "msgSC.h"

int doCMD(char input[], msgListHistorySC& ListHistoryOBJ, msgListDispSC& ListDisplayOBJ);

void inputChat(char *inputMessage, msgListHistorySC& ListHistoryOBJ, msgListDispSC& ListDisplayOBJ);//Locally add entry to chat. From here messages will be handled and displayed to chat.

void updateDisplay(msgListDispSC& ListDisplayOBJ);

void sendMessage();//TODO: using this command will send a message to all connected clients. it will be sent to the server and then distributed to the clients

void switchAppMode(int mode); // mode can be: NO_CONNECTION CONNECTED_CLIENT HOSTING_SERVER
