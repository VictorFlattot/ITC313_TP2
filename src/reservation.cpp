#include "reservation.h"
#include <utility>
#include <cassert>
#include <random>
#include <algorithm>

std::vector<std::string> idReservationUse = {};

Reservation::Reservation(Date dateBegin, std::string idHotel,
                         std::string idRoom, std::string idClient,
                         int nbNight, float pricePerNight) :
        _dateBegin(dateBegin), _idHotel(std::move(idHotel)),
        _idRoom(std::move(idRoom)),	_idClient(std::move(idClient)),
        _nbNight(nbNight), _pricePerNight(pricePerNight) {
    generateId();
    assert(isReservationValid(_dateBegin, _idHotel,_idRoom,
                              _idClient,_nbNight,_pricePerNight)
                              && "Reservation is not valid");
};

std::string Reservation::getId() const {return _id;};
const Date &Reservation::getDateBegin() const {return _dateBegin;};
std::string Reservation::getIdHotel() const {return _idHotel;};
std::string Reservation::getIdRoom() const {return _idRoom;};
std::string Reservation::getIdClient() const {return _idClient;};
int Reservation::getNbNight() const {return _nbNight;};
float Reservation::getPricePerNight() const {return _pricePerNight;};

float Reservation::getPriceTotal() const {return _nbNight * _pricePerNight;};

void Reservation::setId(const std::string& id) {_id = id;};
void Reservation::setDateBegin(const Date & dateBegin) {_dateBegin = dateBegin;};
void Reservation::setIdHotel(const std::string& idHotel) {_idHotel = idHotel;};
void Reservation::setIdRoom(std::string idRoom) {_idRoom = std::move(idRoom);};
void Reservation::setIdClient(std::string idClient) {_idClient = std::move(idClient);};
void Reservation::setPricePerNight(float pricePerNight) {_pricePerNight = pricePerNight;};
void Reservation::setNbNight(int nbNight) {_nbNight = nbNight;};

void Reservation::generateId() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distId(1,9999);

    std::string id;
    do{
        id = std::to_string(distId(rng));
    }
    while (std::find(idReservationUse.begin(), idReservationUse.end(), id) != idReservationUse.end());
    idReservationUse.push_back(id);
    _id = id;
}

std::string to_string(const Reservation &r) {
    return "Id : " + r.getId() + "\n" +
           "DateBegin : " + to_string(r.getDateBegin()) + "\n" +
           "DateEnd : " + to_string(r.getDateBegin() + r.getNbNight()) + "\n" +
           "Id Hotel : " + r.getIdHotel() + "\n" +
           "Id Room : " + r.getIdRoom() + "\n" +
           "Id Client : " + r.getIdClient() + "\n" +
           "Nb Night : " + std::to_string(r.getNbNight()) + "\n" +
           "Price per night : " + std::to_string(r.getPricePerNight()) + "\n" +
           "Price Total : " + std::to_string(r.getPriceTotal()) + "\n";
};

bool isReservationValid(Date dateBegin, const std::string& idHotel, const std::string& idRoom, const std::string& idHClient, int nbNight,
                        float priceTotal) {
    if (idHotel.empty() || idRoom.empty() || idHClient.empty()
        || nbNight <= 0 || priceTotal < 0) return false;
    return true;
}

bool isReservationValid(const Reservation &r) {
    return isReservationValid(r.getDateBegin(), r.getIdHotel(), r.getIdRoom(), r.getIdClient(), r.getNbNight(), r.getPriceTotal());
}

Reservation findReservation(const std::vector<Reservation> &reservations,const std::string& id) {
    return *std::find_if(reservations.begin(),reservations.end(),
                         [id](const Reservation& x) {return x.getId() == id;});
}

bool cancelReservation(std::vector<Reservation>& reservations, const Reservation& r){
    auto it = std::find(reservations.begin(), reservations.end(), r);
    if (it != reservations.end()) reservations.erase(it);
    return std::find(reservations.begin(), reservations.end(), r) != reservations.end();
}

std::string displayReservations(const std::vector<Reservation> &reservations, bool show){
    std::string ret;
    ret += "=======================================\n";
    ret += "\tReservations\n";
    ret += "=======================================\n";
    for (const auto & r : reservations) {
        ret += to_string(r) + "--------------------------------\n";
    }
    if (show) std::cout << ret << std::endl;
    return ret;
}

bool Reservation::operator == (const Reservation& r) const { // check for equality
    if ((_id == r.getId()) && (_dateBegin == r.getDateBegin()) && (_idHotel == r.getIdHotel()) &&
        (_idRoom == r.getIdRoom()) && _idClient == r.getIdClient() && _nbNight == r.getNbNight() &&
        _pricePerNight == r.getPricePerNight()) {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Reservation &r){
    os << to_string(r) << std::endl;
    return os;
};