#include "user.h"

Users::User::User(SOCKET& socket)
{
	this->socket = socket;
}

void Users::add_user(SOCKET& socket)
{
	users.emplace_back(User::User(socket));
	++numberOfUsers;
}

int Users::get_size()
{
	return this->numberOfUsers;
}

Users::Users()
{
	this->numberOfUsers = 0;
}
