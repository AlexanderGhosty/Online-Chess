#include "ServerData.h"
std::mutex users_mutex;
std::mutex rooms_mutex;

int ServerData::get_users_online()
{
	return this->numberOfUsers;
}

int ServerData::get_max_users()
{
	return this->max_users;
}

void ServerData::add_user(User& user)
{
	users_mutex.lock();
	user.set_id(this->users.size());
	this->users.emplace_back(user);
	// this->numberOfUsers += 1;
	users_mutex.unlock();
}

void ServerData::remove_user(User& user)
{
	users_mutex.lock();
	auto iterator = users.begin();
	while (iterator != users.end())
	{
		if (user.socket == iterator->socket)
		{
			users.erase(iterator);
		}
	}
	users_mutex.unlock();
}

int ServerData::add_room(Room room)
{
	rooms_mutex.lock();
	this->rooms.push_back(room);
	rooms_mutex.unlock();
	return rooms.size() - 1;
}

void ServerData::delete_room(Room room)
{
	rooms_mutex.lock();
	auto iterator = rooms.begin();
	while (iterator != rooms.end())
	{
		if (room.name == iterator->name)
		{
			rooms.erase(iterator);
		}
	}
	rooms_mutex.unlock();
}

bool ServerData::is_room_exist(std::string name)
{
	for (auto& room : rooms)
	{
		if (name == room.name)
		{
			return true;
		}
	}
	return false;
}

bool ServerData::connect_room(std::string name, int connection)
{
	for (auto& room : rooms)
	{
		if (name == room.name)
		{
			room.opponent = connection;
			// this->numberOfUsers += 1;
			return true;
		}
	}
	return false;
}

Room& ServerData::get_room(int room_id)
{
	Room& room_ref = rooms[room_id];
	return room_ref;
}

void ServerData::change_max_users(int max_users)
{
	this->max_users = max_users;
}

bool ServerData::is_full()
{
	return numberOfUsers >= max_users;
}

ServerData::ServerData()
{
	this->numberOfUsers = 0;
	this->max_users = 16;
}

void ServerData::add_number_of_users() {
	++this->numberOfUsers;
}