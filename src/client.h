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
		/**
		 * @brief      Constructs a new instance.
		 *
		 * @param[in]  id       The identifier
		 * @param[in]  name     The name
		 * @param[in]  surname  The surname
		 */
		Client(std::string id, std::string name, std::string surname);

		/**
		 * @brief      Gets the identifier.
		 *
		 * @return     The identifier.
		 */
		std::string getId() const;
		/**
		 * @brief      Gets the name.
		 *
		 * @return     The name.
		 */
		std::string getName() const;
		/**
		 * @brief      Gets the surname.
		 *
		 * @return     The surname.
		 */
		std::string getSurname() const;

		/**
		 * @brief      Sets the identifier.
		 *
		 * @param[in]  id    The new identifier
		 */
		void setId(std::string id);
		/**
		 * @brief      Sets the name.
		 *
		 * @param[in]  name  The new name
		 */
		void setName(std::string name);
		/**
		 * @brief      Sets the surname.
		 *
		 * @param[in]  surname  The new surname
		 */
		void setSurname(std::string surname);

};
/**
 * @brief      Find a client. Display information if found, create a new if not
 *
 * @param[in]  clients  The clients
 */
Client findClient(const std::vector<Client> &clients, std::string surname = "",bool show = false);

/**
 * @brief      Determines if client is valid.
 *
 * @param[in]  id       The identifier
 * @param[in]  name     The name
 * @param[in]  surname  The surname
 *
 * @return     True if client is valid, False otherwise.
 */
bool isClientValid(const std::string& id, const std::string& name, const std::string& surname);
/**
 * @brief      Determines whether the specified client c is valid.
 *
 * @param[in]  c     The client
 *
 * @return     True if the specified client c is valid, False otherwise.
 */
bool isClientValid(const Client& c);

/**
 * @brief      Get a string description of the client c
 *
 * @param[in]  c The client
 *
 * @return     a string description of the client c
 */
std::string to_string(const Client &c);
/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os     The operating system
 * @param[in]  client  The client
 *
 * @return     The result of the bitwise left shift
 */
std::ostream &operator<<(std::ostream &os, const Client &client);
