#include <string>
#include <iostream>
#include "date.h"
#include <vector>
#pragma once

class Reservation
{
private:
	Date _dateBegin;
    std::string _id;
	std::string _idHotel;
	std::string _idRoom;
	std::string _idClient;
	int _nbNight;
	float _priceTotal{};
	float _pricePerNight;
public:
	Reservation(Date dateBegin, std::string idHotel, std::string idRoom,
                std::string idClient,int nbNight = 1, float pricePerNight = 0);

    std::string getId() const;
    const Date &getDateBegin() const;
	std::string getIdHotel() const;
	std::string getIdRoom() const;
	std::string getIdClient() const;
	int getNbNight() const;
	float getPricePerNight() const;
	float getPriceTotal() const;

    void setId(const std::string& idHotel);
    void setDateBegin(const Date& dateBegin);
    void setIdHotel(const std::string& idHotel);
	void setIdRoom(std::string idRoom);
	void setIdClient(std::string idClient);
	void setNbNight(int nbNight);
	void setPricePerNight(float pricePerNight);

    void generateId();

    bool operator == (const Reservation& c) const;
};

bool isReservationValid(Date dateBegin, std::string idHotel,std::string idRoom,std::string idHClient,
                        int _nbNight, float priceTotal);
bool isReservationValid(const Reservation& r);

Reservation findReservation(const std::vector<Reservation> &reservations,const std::string& id);
bool cancelReservation(std::vector<Reservation> &reservations, const Reservation& r);
std::string displayReservations(const std::vector<Reservation> &reservations, bool show = false);

std::string to_string(const Reservation &r);
std::ostream &operator<<(std::ostream &os, const Reservation &reservation);