#include <string>
#include <array>
#include <iostream>
#include <algorithm>

#pragma once

enum Type{Single, Double, Suite};
std::array<std::string, 3> const language_str ={"Single", "Double", "Suite"};

class Chambre
{
private:
	std::string _number;
	Type _type;
	float _pricePerNight;
public:
	Chambre(std::string number, Type type, float pricePerNight);

	std::string getNumber() const;
	Type getType() const;
	float getPricePerNight() const;

	void setNumber(std::string _number);
	void setType(Type type);
	void setPricePerNight(float price);

	bool operator == (const Chambre& c) const; // d1 == d2
};

bool isChamberValid(std::string number, Type type, float pricePerNight);
bool isChamberValid(const Chambre& c);

std::string to_string(const Chambre &c);
std::ostream &operator<<(std::ostream &os, const Chambre &chambre);