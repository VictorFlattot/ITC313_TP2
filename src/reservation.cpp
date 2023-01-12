#include "reservation.h"

// Reservation::Reservation(Date dateBegin, std::string idHotel,
//                          std::string idRoom, std::string idClient,
//                          int nbNight = 1, float priceTotal = 0);

const Date &Reservation::getDateBegin() const {return _dateBegin;};
std::string Reservation::getIdHotel() const {return _idHotel;};
std::string Reservation::getIdRoom() const {return _idRoom;};
std::string Reservation::getIdClient() const {return _idClient;};
int Reservation::getNbNight() const {return _nbNight;};
float Reservation::getPriceTotal() const {return _priceTotal;};

// void Reservation::setDateBegin(const Date & dateBegin);
// void Reservation::setIdHotel(const std::string idHotel);
// void Reservation::setIdName(const std::string idName);
// void Reservation::setIdClient(const std::string idClient);
// void Reservation::setNbNight(const int nbNight);
// void Reservation::setPriceTotal(const float priceTotal);