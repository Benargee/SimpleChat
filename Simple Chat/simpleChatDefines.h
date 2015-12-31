#define DEBUG_MODE 0 //Use for application wide debug mode
#define CHAT_LOGGING 0 //Determines if chat logging to file is enabled

#define USERNAME_MAX_SIZE 10 // Maximum amount of characters username can have 
#define MESSAGE_HISTORY_SIZE 40 //Determines the maximum amount of messages saved in chat history. Older history will be saved to log file
#define MESSAGE_DISPLAY_SIZE 20 //Determines the amount of messages displayed on screen.
#define MESSAGE_MAX_SIZE 70 //determines the maximum message size for the whole application

#define DEFAULT_PORT 0
#define DEFAULT_IP "localhost"

//Application Modes
#define NO_CONNECTION 0 //Program is not connected to or hosting a chat. Program will be in the main menu
#define CONNECTED_CLIENT 1 //Program is currently connected to a server
#define HOSTING_SERVER 2 //Program is hosting a server

