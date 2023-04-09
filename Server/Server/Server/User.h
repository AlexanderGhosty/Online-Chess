#pragma once
#include <winsock.h>
#include <atomic>
#include <vector>

class Users
{
private:
	class User
	{
	public:
		SOCKET socket;
		int roomId;
		User(SOCKET& socket);
	};

	int numberOfUsers;

public:
	std::vector <User> users;

	void add_user(SOCKET& socket);
	int get_size();

	Users();
};





