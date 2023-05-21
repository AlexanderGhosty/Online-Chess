#include "Room.h"

bool Room::isFull()
{
	return connections.size() == 2;
}

void Room::add_connection(int connection)
{
	connections.insert(connection);
}

void Room::start_room()
{

}

void Room::delete_connection(int connection)
{
	connections.erase(connection);
}

Room::Room(std::string name, std::string password)
{
	this->name = name;
	this->password = password;
}
