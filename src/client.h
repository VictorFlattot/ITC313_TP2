#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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
/**
 * @brief      Find a client. Display information if found, create a new if not
 *
 * @param[in]  clients  The clients
 */
Client findClient(const std::vector<Client> &clients, std::string surname = "",bool show = false);

bool isClientValid(const std::string& id, const std::string& name, const std::string& surname);
bool isClientValid(const Client& c);

std::string to_string(const Client &c);
std::ostream &operator<<(std::ostream &os, const Client &client);
