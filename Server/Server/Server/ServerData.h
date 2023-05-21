#pragma once
#include "User.h"
#include "Room.h"
#include <vector>
#include <atomic>
#include <mutex>
#include <iostream>

class ServerData
{
private:
	std::atomic<int> numberOfUsers;
	std::vector <User> users;
	std::vector <Room> rooms;
	int max_users;
public:
	int get_users_online();
	int get_max_users();

	void add_user(User& user);
	void remove_user(User& user);

	int add_room(Room room);
	void delete_room(Room room);
	bool is_room_exist(std::string name);
	bool connect_room(std::string name, int connection);
	Room& get_room(int room_id);

	void change_max_users(int max_users);
	bool is_full();

	ServerData();
};

