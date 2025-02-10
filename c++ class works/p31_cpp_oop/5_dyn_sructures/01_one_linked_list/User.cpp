#include "User.h"

User::User(int pointsCount) :
	pointsCount{ pointsCount },
	points{ new int[pointsCount] }
{}