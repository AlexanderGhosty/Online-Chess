#pragma once
#include <string>
#include <vector>
#include <set>

class Room
{
public:
	std::string name;
	std::string password;
	std::set <int> connections;

	bool isFull();

	void add_connection(int connection);
	void delete_connection(int connection);

	void start_room(); // Õ≈ Œ¡ﬂ«¿“≈À‹ÕŒ!!!

	Room(std::string name, std::string password);
};

