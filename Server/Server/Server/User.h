#pragma once
#include <winsock.h>
#include <atomic>
#include <vector>

class User
{
public:
	SOCKET socket;
	int room_id;
	int server_id;

	void set_id(int id);
	User(SOCKET& socket);
};