#pragma once
#include <winsock.h>
#include <atomic>
#include <vector>

class User
{
public:
	SOCKET socket;
	int room_id;
	User(SOCKET& socket);
};