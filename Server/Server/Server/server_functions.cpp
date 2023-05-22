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

	if (isCreate == true and serverData.is_room_exist(name))
	{
		std::cout << "Room exist";

		// нужен enum с кодами возврата
		// send (комната не создана ввести заново)
		// ---------------------------------------
		// Добавить действия в интерфейсе и тд !!!
		// ---------------------------------------
	}

	// logs
	std::cout << name << ' ' << password << ' ' << isCreate << std::endl;

	if (isCreate)
	{
		Room room(name, password);
		int room_id = serverData.add_room(room);
		serverData.get_room(room_id).add_connection(user.socket);

		while (!serverData.get_room(room_id).isFull())
		{
			// Sleep for 5 seconds.
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}

		// игра стартует
		enum message_type{ step , flag};
		recv(user.socket, );
		send(serverData.get_room(room_id).opponent, );
		recv(serverData.get_room(room_id).opponent, );
		send(user.socket, );

	}
	else
	{
		// ИСПОЛЬЗУЕМ FIND_ROOM!
		while (true)
		{
			if (serverData.connect_room(name, user.socket))
			{
				std::cout << "connected complited";
				// send(комната существует, пользователь добавлен)
				// ---------------------------------------
				// Добавить действия в интерфейсе и тд !!!
				// ---------------------------------------
				break;
			}
			else
			{
				// send(комната не найдена ввести заново)
			}
		}
		
	}

}