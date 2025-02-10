#include "ListItem.h"
#include "ListItem.cpp"

#include "List.h"
#include "List.cpp"

#include "Queue.h"
#include "Queue.cpp"

#include "User.h"


template class ListItem<int>;
template class List<int>;
template class Queue<int>;

template class ListItem<User>;
template class List<User>;
template class Queue<User>;

