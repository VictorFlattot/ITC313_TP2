#include <string>
#include <vector>
#include <iostream>

#pragma once

class Client{
	private :
		std::string _id;
		std::string _name;
		std::string _surname;

	public :
		Client(std::string id, std::string name, std::string surname);

		std::string getId() const;
		std::string getName() const;
		std::string getSurname() const;

		void setId(std::string id);
		void setName(std::string name);
		void setSurname(std::string surname);

};

bool isClientValid(std::string id, std::string name, std::string surname);
bool isClientValid(const Client& c);

std::string to_string(const Client &c);
std::ostream &operator<<(std::ostream &os, const Client &client);
