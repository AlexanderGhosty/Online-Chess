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
	void delete_connection(int connection); // �� �����

	void start_room(); // �� �����������!!!

	Room(std::string name, std::string password);
};

