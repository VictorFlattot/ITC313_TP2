#include <string>
#include <array>
#include <iostream>
#include <algorithm>

#pragma once

enum Type{NullType,Single, Double, Suite};
std::array<std::string, 3> const language_str ={"Single", "Double", "Suite"};

class Room
{
private:
	std::string _number;
	Type _type;
	float _pricePerNight;
public:
	Room(std::string number, Type type, float pricePerNight);

	std::string getNumber() const;
	Type getType() const;
	float getPricePerNight() const;

	void setNumber(std::string _number);
	void setType(Type type);
	void setPricePerNight(float price);

	bool operator == (const Room& c) const;
};

bool isChamberValid(std::string number, Type type, float pricePerNight);
bool isChamberValid(const Room& c);

std::string to_string(const Room &c);
std::ostream &operator<<(std::ostream &os, const Room &chambre);