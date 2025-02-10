#pragma once

#include <string>
#include <iostream>

class User
{
private:
	int id;
	std::string email;

public:
	User(int id = 0, std::string email = "no_email");

	bool operator==(const User& obj);
	bool operator!=(const User& obj);

	friend std::ostream& operator<<(std::ostream& out, const User& user);
};


