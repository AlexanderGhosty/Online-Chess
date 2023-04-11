#include "server_functions.h"

void userHandler(User user, ServerData& serverData)
{
	char msg[] = "Hello world!";
	send(user.socket, msg, sizeof(msg), NULL);
}