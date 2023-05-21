#include "Room.h"

bool Room::isFull()
{
	return connections.size() == 2;
}

Room::Room()
{

}
