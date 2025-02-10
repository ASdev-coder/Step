#include "User.h"

User::User(int id, std::string email) :
	id{ id },
	email{ email }
{}

bool User::operator==(const User & obj)
{
	return this->id == obj.id;
}

bool User::operator!=(const User& obj)
{
	return this->id != obj.id;
}



std::ostream& operator<<(std::ostream& out, const User& user)
{
	out << user.id << ": " << user.email;

	return out;
}