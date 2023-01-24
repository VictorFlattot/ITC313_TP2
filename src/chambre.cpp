#include "chambre.h"

Chambre::Chambre(std::string number, Type type, float pricePerNight) : 
_number(number), _type(type), _pricePerNight(pricePerNight) {};

std::string Chambre::getNumber() const {return _number;};
Type Chambre::getType() const {return _type;};
float Chambre::getPricePerNight() const {return _pricePerNight;};

void Chambre::setNumber(std::string number) {_number = number;}
void Chambre::setType(Type type) {_type = type;}
void Chambre::setPricePerNight(float price) { _pricePerNight = price; }
bool Chambre::operator == (const Chambre& c) const { // check for equality
    if ((_number == c.getNumber()) && (_type == c.getType()) && (_pricePerNight== c.getPricePerNight())) {
        return true;
    }
    return false;
}

std::string to_string(const Chambre &c) {
	return "Number : " + c.getNumber() + "\n" +
	       "Type : " + language_str[c.getType()] + "\n" +
	       "Price : " + std::to_string(c.getPricePerNight());

};

std::ostream &operator<<(std::ostream &os, const Chambre &chambre){
	os << to_string(chambre) << std::endl;
    return os;
};