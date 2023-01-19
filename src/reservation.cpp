#include "reservation.h"

Reservation::Reservation(Date dateBegin, std::string idHotel,
                         std::string idRoom, std::string idClient,
                         int nbNight, float pricePerNight) :
	_dateBegin(dateBegin), _idHotel(idHotel), _idRoom(idRoom),
	_idClient(idClient), _nbNight(nbNight), _pricePerNight(pricePerNight) {};

const Date &Reservation::getDateBegin() const {return _dateBegin;};
std::string Reservation::getIdHotel() const {return _idHotel;};
std::string Reservation::getIdRoom() const {return _idRoom;};
std::string Reservation::getIdClient() const {return _idClient;};
int Reservation::getNbNight() const {return _nbNight;};
float Reservation::getPricePerNight() const {return _pricePerNight;};

float Reservation::getPriceTotal() const {return _nbNight * _pricePerNight;};

void Reservation::setDateBegin(const Date & dateBegin) {_dateBegin = dateBegin;};
void Reservation::setIdHotel(const std::string idHotel) {_idHotel = idHotel;};
void Reservation::setIdRoom(const std::string idRoom) {_idRoom = idRoom;};
void Reservation::setIdClient(const std::string idClient) {_idClient = idClient;};
void Reservation::setPricePerNight(const float pricePerNight) {_pricePerNight = pricePerNight;};
void Reservation::setNbNight(const int nbNight) {_nbNight = nbNight;};

std::string to_string(const Reservation &r) {
	return "DateBegin : " + to_string(r.getDateBegin()) + "\n" +
	       "Id Hotel : " + r.getIdHotel() + "\n" +
	       "Id Room : " + r.getIdRoom() + "\n" +
	       "Id Client : " + r.getIdClient() + "\n" +
	       "Nb Night :" + std::to_string(r.getNbNight()) + "\n" +
	       "Price per night : " + std::to_string(r.getPricePerNight()) + "\n" +
	       "Price Total : " + std::to_string(r.getPriceTotal()) + "\n";

};

std::ostream &operator<<(std::ostream &os, const Reservation &r){
	os << to_string(r) << std::endl;
    return os;
};