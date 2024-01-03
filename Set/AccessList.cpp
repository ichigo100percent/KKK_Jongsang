#include "AccessList.h"

using namespace std;

AccessList::AccessList(std::initializer_list<std::string_view> initlist)
{
	mAllowed.insert(begin(initlist), end(initlist));
}

void AccessList::addUser(std::string_view user)
{
	mAllowed.emplace(user);
}

void AccessList::removeUser(std::string_view user)
{
	mAllowed.erase(string(user));
}

bool AccessList::isAllowed(std::string_view user) const
{
	return (mAllowed.count(string(user)) != 0);
}

std::vector<std::string> AccessList::getAllUsers() const
{
	return { begin(mAllowed), end(mAllowed) };
}
