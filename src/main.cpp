#include <iostream>
#include <vector>
#include "client.h"
#include "hotel.h"
#include "reservation.h"
#include <algorithm>
#include <tuple>
#include <regex>




/**
 * @brief      Determines whether the specified string date is matching this
 *             pattern (yyyy-mm-dd).
 *
 * @param[in]  strDate  The string date
 *
 * @return     True if the specified string date is string date valid, False otherwise.
 */
bool isStrDateValid(const std::string& strDate) {
    std::regex self_regex(R"((^\d{4}\-(0?[1-9]|1[012])\-(0?[1-9]|[12][0-9]|3[01])))");
    return std::regex_search(strDate, self_regex);
}

/**
 * @brief      Choose the lenght of the stay
 *
 * @return     A std::tuple<Date, int> where "Date" represent the start date of the stay 
 *             and "int" the number of night
 */
std::tuple<Date, int> chooseLengthOfStay() {
    ;
    std::string strDateBegin;
    int nbNight = 1;
    std::cout 	<< "=======================================\n"
                 << "\tLenght of stay\n"
                 << "=======================================\n"
                 << "Please enter the following informations\n";

    bool isDateValid;
    do{
        std::cout << "Date reservation (yyyy-mm-dd):";
        std::cin >> strDateBegin;
        isDateValid = isStrDateValid(strDateBegin);
        if (!isDateValid) std::cout << "Erreur : Date is not valid\n"
                                    << "Try again\n";

    }while(!isDateValid);

    char delim= '-';
    std::vector<int> dateVector{};
    std::stringstream ss(strDateBegin);
    std::string s;
    while (std::getline(ss, s, delim)) {
        dateVector.push_back(std::stoi(s));
    }

    Date dateBegin = Date(dateVector.at(2),
                          dateVector.at(1),
                          dateVector.at(0));

    bool isNbNightValid;
    do{
        std::cout << "Nb night (>=1):";
        std::cin >> nbNight;
        isNbNightValid = nbNight >= 1;
        if (!isNbNightValid) std::cout << "Erreur : Nb night is not valid\n"
                                       << "Try again\n";
    }while(!isNbNightValid);
    std::cout << std::endl;
    return std::make_tuple(dateBegin, nbNight);
}

/**
 * @brief      Gets the rooms available by type and dates.
 *
 * @param[in]  hotel                 The hotel
 * @param[in]  reservations          The reservations
 * @param[in]  dateDebutReservation  The date debut reservation
 * @param[in]  dateFinReservation    The date fin reservation
 * @param[in]  type                  The type
 *
 * @return     The rooms available by type and dates.
 */
std::vector<Room> getRoomsAvailableByTypeAndDate(const Hotel &hotel,
                                                 const std::vector<Reservation> &reservations,
                                                 const Date &dateDebutReservation,
                                                 const Date &dateFinReservation,
                                                 const Type &type) {
    std::vector<Room> roomsAvailable = {};

    for (const Room& room : hotel.getRooms(type)) {
        std::string id = room.getNumber();
        if(!reservations.empty()){
            auto it = std::find_if(reservations.begin(), reservations.end(),
                                   [id](const Reservation &x){return x.getIdRoom() == id;});
            if (it!=reservations.end()) {
                if (dateFinReservation < it->getDateBegin() ||
                    dateDebutReservation > it->getDateBegin() + it->getNbNight()) {
                    roomsAvailable.push_back(room);
                }
            }else{
                roomsAvailable.push_back(room);
            }

        }else{
            return hotel.getRooms(type);
        }
    }

    return roomsAvailable;
}

/**
 * @brief      Gets the rooms available by type and lenght of the stay.
 *
 * @param[in]  hotel         The hotel
 * @param[in]  reservations  The reservations
 * @param[in]  type          The type
 * @param[in]  lengthOfStay  The length of stay
 *
 * @return     The rooms available by type and lenght of the stay.
 */
std::vector<Room> getRoomsAvailableByTypeAndDate(const Hotel &hotel,
                                                 const std::vector<Reservation> &reservations,
                                                 const Type &type,
                                                 const std::tuple<Date, int> &lengthOfStay){
    return getRoomsAvailableByTypeAndDate(hotel, reservations,
                                          std::get<0>(lengthOfStay),
                                          std::get<0>(lengthOfStay) +
                                          std::get<1>(lengthOfStay),
                                          type);
}

/**
 * @brief      Gets the first available room for a type and a period.
 *
 * @param[in]  hotel         The hotel
 * @param[in]  reservations  The reservations
 * @param[in]  type          The type
 * @param[in]  lengthOfStay  The length of stay
 * @param[in]  show          The show
 *
 * @return     The first available room for a type and a period.
 */
Room * GetFirstAvailableRoomForATypeAndAPeriod(const Hotel &hotel,
                                               const std::vector<Reservation> &reservations,
                                               Type type,
                                               std::tuple<Date, int> lengthOfStay =
                                               std::make_tuple(Date(1,1,1), 0),
                                               bool show = false){
    if (show || type == Type::NullType){
        std::cout << "=======================================\n"
                  << "\tType of the Room\n"
                  << "=======================================\n";
    }
    if(type == Type::NullType) {
        bool isTypeValid;
        std::string strType;
        do {
            std::cout << "Enter 1)Single\n      2)Double\n      3)Suite\n";
            std::cin >> strType;
            isTypeValid = stoi(strType) >= 1 && stoi(strType) <= 3;
            if (!isTypeValid)
                std::cout << "Erreur : Type is not valid\n"
                          << "Try again\n";
        } while (!isTypeValid);

        switch (stoi(strType)) {
            case 1:
                type = Single;
                break;
            case 2:
                type = Double;
                break;
            case 3:
                type = Suite;
                break;
        }
    }

    if (lengthOfStay == std::make_tuple(Date(1,1,1), 0))
        lengthOfStay = chooseLengthOfStay();

    auto roomsAvailable = getRoomsAvailableByTypeAndDate(hotel,reservations,
                                                         type, lengthOfStay);
    Room *room = nullptr;
    if (!roomsAvailable.empty()){
        room = new Room((roomsAvailable.at(0)));
        if(show) std::cout << "First Room available : \n" << *room;
    }else if(show) std::cout << "No Room available\n";
    return room;

}

/**
 * @brief      Creates a reservation.
 *
 * @param[in]  hotel         The hotel
 * @param[in]  reservations  The reservations
 * @param[in]  clients       The clients
 * @param[in]  surname       The surname
 * @param[in]  lengthOfStay  The length of stay
 * @param[in]  type          The type
 * @param[in]  show          The show
 *
 * @return     a pointer to a new reservation
 */
Reservation * createReservation(const Hotel &hotel,
                                const std::vector<Reservation> &reservations,
                                const std::vector<Client> &clients,
                                const std::string &surname = "",
                                std::tuple<Date, int> lengthOfStay =
                                std::make_tuple(Date(1,1,1), 0),
                                const Type &type = Type::NullType,
                                bool show = false) {
    if(show){
        std::cout << "=======================================\n"
                  << "\tNew Reservation\n"
                  << "=======================================\n";
    }
    Client client = findClient(clients,surname,show);
    if (std::get<0>(lengthOfStay) == Date(1,1,1) && std::get<1>(lengthOfStay) == 0){
        lengthOfStay = chooseLengthOfStay();
    }
    Date date = std::get<0>(lengthOfStay);
    int nbNight = std::get<1>(lengthOfStay);
    if (show){
        std::cout << "=======================================\n"
                  << "\tLenght of stay\n"
                  << "=======================================\n"
                  << "Date: " << date << "\n"
                  << "Number of Night: " << nbNight << "\n";
    }
    auto proom = GetFirstAvailableRoomForATypeAndAPeriod(hotel, reservations, type, lengthOfStay, show);
    Reservation *reservation = nullptr;
    bool reservationCanceled = true;
    if(proom != nullptr){
        reservation = new Reservation(date,hotel.getId(),(*proom).getNumber(),
                                      client.getId(),nbNight,(*proom).getPricePerNight());
        reservationCanceled = false;
    }
    if (show){
        std::cout <<"=======================================\n"
                  << "\tBooking Summary\n"
                  << "=======================================\n"
                  << *reservation << "\n";
        if(reservationCanceled) std::cout << "Cancel\n";
    }
    return reservation;
}

/**
 * @brief      Display the list of reservations for a specified Client by its name or id
 *
 * @param[in]  reservations    The reservations
 * @param[in]  clients         The clients
 * @param[in]  nameOrIdClient  The name or identifier client
 * @param[in]  show            The show
 *
 * @return     a string represent the list of reservations for a specified Client by its name or id
 */ 
std::string displayReservations(const std::vector<Reservation> &reservations,const std::vector<Client> &clients,
                                const std::string& nameOrIdClient, bool show = false) {
    std::string ret;
    ret += "=======================================\n";
    ret += "\tReservations\n";
    ret += "=======================================\n";

    auto c = *std::find_if(clients.begin(), clients.end(),
                           [nameOrIdClient](Client const & x) {
                               return (x.getSurname() == nameOrIdClient || x.getId() == nameOrIdClient);});
    std::string id = c.getId();
    std::cout << id << std::endl;
    std::vector<Reservation> reservationsClient;
    std::copy_if(reservations.begin(),reservations.end(),
                 std::back_inserter(reservationsClient),
                 [id](const Reservation& x) {return x.getIdClient() == id;});

    for (const auto & r : reservationsClient) {
        ret += to_string(r) + "--------------------------------\n";
    }
    if (show) std::cout << ret << std::endl;
    return ret;
}

int main(int argc, char const *argv[])
{
    Hotel hotel("OCEAN11", "Le Bellagio", "Las Vegas", {
            Room("001", Type::Single, 100),
            Room("002", Type::Single, 100),
            Room("003", Type::Single, 100),
            Room("004", Type::Double, 125),
            Room("101", Type::Double, 125),
            Room("102", Type::Double, 125),
            Room("103", Type::Double, 125),
            Room("201", Type::Double, 125),
            Room("202", Type::Suite, 210),
            Room("303", Type::Suite, 210),
    });

    std::vector<Client> clients = {
            Client("1", "Victor", "Flattot"),
            Client("2", "Julien", "Cos")
    };


    std::vector<Reservation> reservations = {};


    Reservation *r1 = createReservation(hotel,reservations,clients,"Flattot",std::make_tuple(Date(), 2),Type::Single);
    if(r1 != nullptr) reservations.push_back(*r1);
    Reservation *r2 = createReservation(hotel,reservations,clients,"Flattot",std::make_tuple(Date(), 5),Type::Single);
    if(r2 != nullptr) reservations.push_back(*r2);
    Reservation *r3 = createReservation(hotel,reservations,clients,"Cos",std::make_tuple(Date(), 8),Type::Single);
    if(r3 != nullptr) reservations.push_back(*r3);
    Reservation *r4 = createReservation(hotel,reservations,clients,"Cos",std::make_tuple(Date(), 2),Type::Single);
    if(r4 != nullptr) reservations.push_back(*r4);
//    Reservation *r5 = createReservation(hotel,reservations,clients);
//    if(r5 != nullptr) reservations.push_back(*r5);
    displayReservations(reservations, true);
//    Reservation *r6 = createReservation(hotel,reservations,clients,"Cos",std::make_tuple(Date(10,15,2015), 2),Type::Single);
//    if(r6 != nullptr) reservations.push_back(*r6);

    std::cout << displayReservations(reservations,clients,"1") << std::endl;

//    std::string id;
//    std::cout << "Id Reservation to cancel : ";
//    std::cin >> id;
//    cancelReservation(reservations,findReservation(reservations,id));
//    displayReservations(reservations, true);
    return 0;
}
