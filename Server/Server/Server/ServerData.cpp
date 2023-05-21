#include "ServerData.h"

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
	user.set_id(this->users.size());
	this->users.emplace_back(user);
	this->numberOfUsers += 1;
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
