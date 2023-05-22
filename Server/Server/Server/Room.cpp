#include "Room.h"

bool Room::isFull()
{
	return opponent != -1;
}

void Room::add_connection(int connection)
{
	this->host = connection;
}

void Room::start_room()
{

}

void Room::delete_connection(int connection)
{
	opponent = -1;
}

Room::Room(std::string name, std::string password)
{
	this->name = name;
	this->password = password;
	opponent = -1;
}
