#include <string>
#include <vector>
#include "chambre.h"

#pragma once

class Hotel
{
private:
	std::string _id;
	std::string _name;
	std::string _city;
	std::vector<Chambre> _rooms;

public:
	Hotel(std::string id, std::string name = {}, std::string city = {}, std::vector<Chambre> rooms = {});

	std::string getId() const;
	std::string getName() const;
	std::string getCity() const;
	std::vector<Chambre> getRooms() const;

	void setId(std::string id);
	void setName(std::string name);
	void setCity(std::string city);
	void setRooms(std::vector<Chambre> rooms);

	bool addRoom(Chambre room);
	bool removeRoom(Chambre room);

};

std::string displayRooms(bool show = true);
bool isHotelValid(std::string id);
bool isHotelValid(const Hotel& h);

std::string to_string(const Hotel &c);
std::ostream &operator<<(std::ostream &os, const Hotel &hotel);