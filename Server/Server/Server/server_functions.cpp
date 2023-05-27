#include "server_functions.h"

void userHandler(User user, ServerData& serverData)
{
	serverData.add_user(user);
	// Getting information about creating or joining a room
	char name[65];
	recv(user.socket, name, sizeof(name), NULL);
	char password[255];
	recv(user.socket, password, sizeof(name), NULL);
	// bool isCreate{0};
	char isCreate[1];
	recv(user.socket, (char*)isCreate, sizeof(name), NULL);

	std::array<std::array<std::pair<int, int>, 16>, 2> receivingPositions;

	while (isCreate[0] == '1' and serverData.is_room_exist(name))
	{
		std::cout << "Room exist";

		bool notComplited = false;
		send(user.socket, (char*)notComplited, sizeof(notComplited), NULL);

		recv(user.socket, name, sizeof(name), NULL);
		recv(user.socket, password, sizeof(name), NULL);
		recv(user.socket, (char*)isCreate, sizeof(name), NULL);

		// ---------------------------------------
		// Добавить действия в интерфейсе и тд !!!
		// ---------------------------------------
	}

	// logs
	std::cout << name << ' ' << password << ' ' << isCreate[0] << std::endl;

	if (isCreate[0] == '1')
	{
		Room room(name, password);
		int room_id = serverData.add_room(room);
		serverData.get_room(room_id).add_connection(user.socket);

		bool complited = true;
		send(user.socket, (char*)complited, sizeof(complited), NULL);

		while (!serverData.get_room(room_id).isFull())
		{
			// Sleep for 5 seconds.
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}

		GameState gameState;

		// игра стартует

		while (true)
		{
			if (recv(user.socket, (char*)&receivingPositions, sizeof(receivingPositions), NULL) == -1)
			{
				closesocket(user.socket);
				closesocket(serverData.get_room(room_id).opponent);
				break;
			}
			std::cout << "recieved data from admin" << std::endl;
			if (send(serverData.get_room(room_id).opponent, (char*)&receivingPositions, sizeof(receivingPositions), NULL) == -1)
			{
				closesocket(user.socket);
				closesocket(serverData.get_room(room_id).opponent);
				break;
			}
			std::cout << "sended data to opponent" << std::endl;
			if (recv(serverData.get_room(room_id).opponent, (char*)&receivingPositions, sizeof(receivingPositions), NULL) == -1)
			{
				closesocket(user.socket);
				closesocket(serverData.get_room(room_id).opponent);
				break;
			}
			std::cout << "recieved data from opponent" << std::endl;

			if (send(user.socket, (char*)&receivingPositions, sizeof(receivingPositions), NULL) == -1)
			{
				closesocket(user.socket);
				closesocket(serverData.get_room(room_id).opponent);
				break;
			}
			std::cout << "send data to admin" << std::endl;
		}
		

	}
	else
	{
		while (true)
		{
			if (serverData.connect_room(name, user.socket, password))
			{
				std::cout << "connected complited";
				bool complited = true;
				send(user.socket, (char*)complited, sizeof(complited), NULL);
				// ---------------------------------------
				// Добавить действия в интерфейсе и тд !!!
				// ---------------------------------------
				break;
			}
			else
			{
				bool notComplited = false;
				send(user.socket, (char*)notComplited, sizeof(notComplited), NULL);
				// send(комната не найдена ввести заново)
			}
		}
		
	}

}