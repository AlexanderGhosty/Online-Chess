#include "user.h"

void User::set_id(int id)
{
	this->server_id = id;
}

User::User(SOCKET& socket)
{
	this->socket = socket;
}