#include "server_functions.h"

void userHandler(User user, ServerData& serverData)
{
	serverData.add_user(user);

	// Getting information about creating or joining a room
	char name[65];
	recv(user.socket, name, sizeof(name), NULL);
	char password[255];
	recv(user.socket, password, sizeof(name), NULL);
	bool isCreate{0};
	recv(user.socket, (char*)isCreate, sizeof(name), NULL);

	// logs
	std::cout << name << ' ' << password << ' ' << isCreate << std::endl;

	if (isCreate)
	{
		// create room, set name and password, transmitting user information
	}
	else
	{
		// Search for a room with the specified parameters
	}

}