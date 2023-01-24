#include "hotel.h"

Hotel::Hotel(std::string id, std::string name, std::string city, std::vector<Chambre> rooms) :
	_id(id), _name(name), _city(city), _rooms(rooms) {};

std::string Hotel::getId() const {return _id;};
std::string Hotel::getName() const {return _name;};
std::string Hotel::getCity() const {return _city;};
std::vector<Chambre> Hotel::getRooms() const {return _rooms;};
std::vector<Chambre> Hotel::getRooms(const Type &type) const {
	std::vector<Chambre> roomsAvailable;
	std::copy_if(_rooms.begin(),_rooms.end(), 
		std::back_inserter(roomsAvailable), 
		[type](Chambre x) {return x.getType() == type;});
	return roomsAvailable;
};



void Hotel::setId(std::string id) {_id = std::move(id);};
void Hotel::setName(std::string name) {_name = std::move(name);};
void Hotel::setCity(std::string city) {_city = std::move(city);};
void Hotel::setRooms(std::vector<Chambre> rooms) {_rooms = std::move(rooms);};

bool Hotel::addRoom(Chambre room) {
	if (find (_rooms.begin(), _rooms.end(), room) == _rooms.end()) _rooms.push_back(room);
	return find (_rooms.begin(), _rooms.end(), room) == _rooms.end();
};
bool Hotel::removeRoom(Chambre room) {
	auto it = find (_rooms.begin(), _rooms.end(), room);
	if (it != _rooms.end()) _rooms.erase(it);
	return find (_rooms.begin(), _rooms.end(), room) != _rooms.end();
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

std::ostream &operator<<(std::ostream &os, const Hotel &hotel){
	os << to_string(hotel) << std::endl;
    return os;
};