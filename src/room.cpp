#include "room.h"

#include <utility>

Room::Room(std::string number, Type type, float pricePerNight) :
_number(std::move(number)), _type(type), _pricePerNight(pricePerNight) {};

std::string Room::getNumber() const {return _number;};
Type Room::getType() const {return _type;};
float Room::getPricePerNight() const {return _pricePerNight;};

void Room::setNumber(std::string number) { _number = std::move(number);}
void Room::setType(Type type) { _type = type;}
void Room::setPricePerNight(float price) { _pricePerNight = price; }
bool Room::operator == (const Room& c) const { // check for equality
    if ((_number == c.getNumber()) && (_type == c.getType()) && (_pricePerNight== c.getPricePerNight())) {
        return true;
    }
    return false;
}

std::string to_string(const Room &r) {
	return "Number : " + r.getNumber() + "\n" +
	       "Type : " + language_str[r.getType()] + "\n" +
	       "Price per night: " + std::to_string(r.getPricePerNight()) + " EUR";

};

std::ostream &operator<<(std::ostream &os, const Room &room){
	os << to_string(room) << std::endl;
    return os;
};