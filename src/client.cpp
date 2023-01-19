#include "client.h"
#include <cassert>

std::vector<std::string> idClientUse = {};

Client::Client(std::string id, std::string name, std::string surname):
	_id(id), _name(name), _surname(surname) {
	assert(isClientValid(id, name, surname) && "Client is not valid");
	idClientUse.push_back(id);
}

std::string Client::getId() const { return _id; }
std::string Client::getName() const { return _name;}
std::string Client::getSurname() const { return _surname;}

void Client::setId(std::string id) { _id = id; }
void Client::setName(std::string name) { _name = name;}
void Client::setSurname(std::string surname) {_surname = surname;}

bool isClientValid(std::string id, std::string name, std::string surname) {
	if (std::find(idClientUse.begin(), idClientUse.end(), id)
	        != idClientUse.end()) return false;
	if (id.empty()) return false;
	if (name.empty() && surname.empty()) return false;
	return true;
};

bool isClientValid(const Client& c) {
	return isClientValid(c.getId(), c.getName(), c.getSurname());
};

std::string to_string(const Client &c) {
	return "ID : " + c.getId() + "\n" +
	       "name : " + c.getName() + "\n" +
	       "surname : " + c.getSurname();

};

std::ostream &operator<<(std::ostream &os, const Client &client) {
	os << to_string(client) << std::endl;
	return os;
};