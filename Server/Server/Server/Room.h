#pragma once
#include <string>
#include <vector>

class Room
{
public:
	std::string name;
	std::string password;
	std::vector <int> connections;

	bool isFull();
	Room();
};

