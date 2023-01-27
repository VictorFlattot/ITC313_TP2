#include "hotel.h"
#include <cassert>
#include <utility>

std::vector<std::string> idHotelUse = {};

Hotel::Hotel(std::string id, std::string name, std::string city,
             std::vector<Room> rooms) :
	_id(std::move(id)), _name(std::move(name)),
    _city(std::move(city)), _rooms(std::move(rooms)) {
    assert(isHotelValid(_id, _name, _city) && "Client is not valid");
    idHotelUse.push_back(_id);
};

std::string Hotel::getId() const {return _id;};
std::string Hotel::getName() const {return _name;};
std::string Hotel::getCity() const {return _city;};
std::vector<Room> Hotel::getRooms() const {return _rooms;};

std::vector<Room> Hotel::getRooms(const Type &type) const {
	std::vector<Room> roomsAvailable;
	std::copy_if(_rooms.begin(),_rooms.end(), 
		std::back_inserter(roomsAvailable), 
		[type](const Room& x) {return x.getType() == type;});
	return roomsAvailable;
};

void Hotel::setId(std::string id) {_id = std::move(id);};
void Hotel::setName(std::string name) {_name = std::move(name);};
void Hotel::setCity(std::string city) {_city = std::move(city);};
void Hotel::setRooms(std::vector<Room> rooms) { _rooms = std::move(rooms);};


bool Hotel::addRoom(const Room& room) {
	if (std::find (_rooms.begin(), _rooms.end(), room) == _rooms.end()) _rooms.push_back(room);
	return std::find (_rooms.begin(), _rooms.end(), room) == _rooms.end();
};

bool Hotel::removeRoom(const Room& room) {
	auto it = std::find (_rooms.begin(), _rooms.end(), room);
	if (it != _rooms.end()) _rooms.erase(it);
	return std::find (_rooms.begin(), _rooms.end(), room) != _rooms.end();
}

Room Hotel::getRoom(const std::string& id) const {
    return *std::find_if(_rooms.begin(), _rooms.end(), [id](const Room& x) {return x.getNumber() == id;});
}

std::string displayRooms(const Hotel &h,bool show) {
    std::string ret;
    for (int i = 0; i < h.getRooms().size(); ++i) {
        ret += std::to_string(i) + " : \n" + to_string(h.getRooms().at(i)) + "\n";
    }
    if (show) std::cout << ret << std::endl;
    return ret;
}

std::string to_string(const Hotel &h){
	return "ID : " + h.getId() + "\n" +
	       "Name : " + h.getName() + "\n" +
	       "City : " + h.getCity() + "\n"
	       "Rooms : " + displayRooms(h,false);
}

bool isHotelValid(const std::string &id,
                  const std::string &name,
                  const std::string &city) {
    if (id.empty()) return false;
    if (std::find(idHotelUse.begin(), idHotelUse.end(), id)
        != idHotelUse.end()) return false;
    if (name.empty()) return false;
    if (city.empty()) return false;
    return true;
}



bool isHotelValid(const Hotel &h) {
    return isHotelValid(h.getId(), h.getName(), h.getCity());
}

std::ostream &operator<<(std::ostream &os, const Hotel &hotel){
	os << to_string(hotel) << std::endl;
    return os;
};