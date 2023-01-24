#include <iostream>
#include <vector>
#include "client.h"
#include "hotel.h"
#include "reservation.h"
#include <algorithm>
#include <tuple>
#include <regex>

/**
 * @brief      Finds a client. Display information if found, create a new one if
 *             not
 *
 * @param[in]  clients  The clients
 */
void findClient(const std::vector<Client> &clients) {
	std::string surname = "";
	std::cout << "customer's name : ";
	std::cin >> surname;
	auto it = std::find_if(clients.begin(), clients.end(),
	[surname](Client const & x) {return x.getSurname() == surname;});
	if (it != clients.end()) {
		std::cout << *it;
	} else
	{

		std::string idNewClient = "";
		std::string nameNewClient = "";
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
		std::cout << newClient;
	}
}


/**
 * @brief      Determines whether the specified string date is matching this
 *             pattern (yyyy-mm-dd).
 *
 * @param[in]  strDate  The string date
 *
 * @return     True if the specified string date is string date valid, False otherwise.
 */
bool isStrDateValid(const std::string strDate) {
	std::regex self_regex("(^\\d{4}\\-(0?[1-9]|1[012])\\-(0?[1-9]|[12][0-9]|3[01]))");
	return std::regex_search(strDate, self_regex);
}

int main(int argc, char const *argv[])
{
	Hotel hotel("OCEAN11", "Le Bellagio", "Las Vegas", {
		Chambre("001", Type::Single, 100),
		Chambre("002", Type::Single, 100),
		Chambre("003", Type::Single, 100),
		Chambre("004", Type::Double, 125),
		Chambre("101", Type::Double, 125),
		Chambre("102", Type::Double, 125),
		Chambre("103", Type::Double, 125),
		Chambre("201", Type::Double, 125),
		Chambre("202", Type::Suite, 210),
		Chambre("303", Type::Suite, 210),
	});

	std::vector<Client> clients = {
		Client("1", "Victor", "Flattot"),
		Client("2", "Julien", "Cos")
	};

	std::vector<Reservation> reservations = {Reservation(Date(), "OCEAN11", "001", "1", 3, 100)};

	// std::cout << reservations.at(0);

	// std::cout << hotel;
	// for (auto it = clients.begin(); it != clients.end(); ++it){
	// 	std::cout << *it;
	// };
	// findClient(clients);
	std::cout << std::boolalpha;
	for(Chambre c : hotel.getRooms(Type::Suite)){
		std::cout << c << std::endl;	
	}
	
	return 0;
}
