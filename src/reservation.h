#include <string>
#include <iostream>
#include "date.h"
#pragma once

class Reservation
{
private:
	Date _dateBegin;
	std::string _idHotel;
	std::string _idRoom;
	std::string _idClient;
	int _nbNight;
	float _priceTotal;
	float _pricePerNight;
public:
	Reservation(Date dateBegin, std::string idHotel, std::string idRoom, std::string idClient,int nbNight = 1, float pricePerNight = 0);

	const Date &getDateBegin() const;
	std::string getIdHotel() const;
	std::string getIdRoom() const;
	std::string getIdClient() const;
	int getNbNight() const;
	float getPricePerNight() const;
	float getPriceTotal() const;

	void setDateBegin(const Date& dateBegin);
	void setIdHotel(const std::string idHotel);
	void setIdRoom(const std::string idRoom);
	void setIdClient(const std::string idClient);
	void setNbNight(const int nbNight);
	void setPricePerNight(const float pricePerNight);
	void setPriceTotal(const float priceTotal);
};

bool isReservationValid(Date dateBegin, std::string idHotel,std::string idRoom,std::string idHClient, int _nbNight, float priceTotal);
bool isReservationValid(const Reservation& r);

std::string to_string(const Reservation &r);
std::ostream &operator<<(std::ostream &os, const Reservation &reservation);