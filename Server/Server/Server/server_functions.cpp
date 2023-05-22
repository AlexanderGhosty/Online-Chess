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

	do 
	{
		std::cout << "Room exist";

		bool notComplited = false;
		send(user.socket, (char*)notComplited, sizeof(notComplited), NULL);

		recv(user.socket, name, sizeof(name), NULL);

		// ---------------------------------------
		// �������� �������� � ���������� � �� !!!
		// ---------------------------------------
	} while (isCreate == true and serverData.is_room_exist(name));

	// logs
	std::cout << name << ' ' << password << ' ' << isCreate << std::endl;

	if (isCreate)
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

		// ���� ��������
		
		while (true)
		{
			recv(user.socket, (char*)&gameState, sizeof(gameState), NULL);
			if (!gameState.get_isWin())
			{
				break;
			}
			send(serverData.get_room(room_id).opponent, (char*)&gameState, sizeof(gameState), NULL);
			recv(serverData.get_room(room_id).opponent, (char*)&gameState, sizeof(gameState), NULL);
			if (!gameState.get_isWin())
			{
				break;
			}
			send(user.socket, (char*)&gameState, sizeof(gameState), NULL);
		}
		

	}
	else
	{
		while (true)
		{
			if (serverData.connect_room(name, user.socket))
			{
				std::cout << "connected complited";
				bool complited = true;
				send(user.socket, (char*)complited, sizeof(complited), NULL);
				// ---------------------------------------
				// �������� �������� � ���������� � �� !!!
				// ---------------------------------------
				break;
			}
			else
			{
				bool notComplited = false;
				send(user.socket, (char*)notComplited, sizeof(notComplited), NULL);
				// send(������� �� ������� ������ ������)
			}
		}
		
	}

}