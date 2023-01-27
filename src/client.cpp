#include "client.h"
#include <cassert>
#include <utility>

std::vector<std::string> idClientUse = {};

Client::Client(std::string id, std::string name, std::string surname):
	_id(std::move(id)), _name(std::move(name)), _surname(std::move(surname)) {
	assert(isClientValid(_id, _name, _surname)
           && "Client is not valid");
	idClientUse.push_back(_id);
}

std::string Client::getId() const { return _id; }
std::string Client::getName() const { return _name;}
std::string Client::getSurname() const { return _surname;}

void Client::setId(std::string id) { _id = std::move(id); }
void Client::setName(std::string name) { _name = std::move(name);}
void Client::setSurname(std::string surname) {_surname = std::move(surname);}

Client findClient(const std::vector<Client> &clients, std::string surname,bool show) {

    if(surname.empty()){
        std::cout << "=======================================\n"
                  << "\tInformation Customer\n"
                  << "=======================================\n";
        std::cout << "customer's name : ";
        std::cin >> surname;
    }

    auto it = std::find_if(clients.begin(), clients.end(),
                           [surname](Client const & x) {return x.getSurname() == surname;});
    if (it != clients.end()) {
        if (show){
            std::cout << *it;
        }
        return *it;
    } else
    {

        std::string idNewClient;
        std::string nameNewClient;
        std::string surnameNewClient = std::move(surname);
        std::cout 	<< "=======================================\n"
                     << "\t\tNew Customer\n"
                     << "=======================================\n"
                     << "Please enter the following informations\n"
                     << "Id : ";
        std::cin >> idNewClient;
        std::cout << "Name : ";
        std::cin >> nameNewClient;
        Client newClient(idNewClient, nameNewClient, surnameNewClient);
        return  newClient;
    }
}

bool isClientValid(const std::string& id,
                   const std::string& name,
                   const std::string& surname) {
    if (id.empty()) return false;
    if (std::find(idClientUse.begin(), idClientUse.end(), id)
	        != idClientUse.end()) return false;
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