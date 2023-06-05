#pragma once
#include <string>
#include <vector>
#include <set>

class Room
{
public:
	std::string name;
	std::string password;
	int host;
	int opponent;

	bool isFull();
	void add_connection(int connection);

	Room(std::string name, std::string password);
};

