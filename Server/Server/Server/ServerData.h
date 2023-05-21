#pragma once
#include "User.h"
#include <vector>
#include <atomic>

class ServerData
{
private:
	std::atomic<int> numberOfUsers;
	std::vector <User> users;
	int max_users;
public:
	int get_users_online();
	int get_max_users();
	void add_user(User& user);
	void remove_user();
	void change_max_users(int max_users);
	bool is_full();

	ServerData();
};

