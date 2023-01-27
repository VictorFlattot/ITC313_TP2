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

    /**
     * @brief      Gets the identifier.
     *
     * @return     The identifier.
     */
    std::string getId() const;
    /**
     * @brief      Gets the date begin.
     *
     * @return     The date begin.
     */
    const Date &getDateBegin() const;
	/**
	 * @brief      Gets the identifier hotel.
	 *
	 * @return     The identifier hotel.
	 */
	std::string getIdHotel() const;
	/**
	 * @brief      Gets the identifier room.
	 *
	 * @return     The identifier room.
	 */
	std::string getIdRoom() const;
	/**
	 * @brief      Gets the identifier client.
	 *
	 * @return     The identifier client.
	 */
	std::string getIdClient() const;
	/**
	 * @brief      Gets the number of night.
	 *
	 * @return     The number of night.
	 */
	int getNbNight() const;
	/**
	 * @brief      Gets the price per night.
	 *
	 * @return     The price per night.
	 */
	float getPricePerNight() const;
	/**
	 * @brief      Gets the price total.
	 *
	 * @return     The price total.
	 */
	float getPriceTotal() const;

    /**
     * @brief      Sets the identifier.
     *
     * @param[in]  idHotel  The identifier hotel
     */
    void setId(const std::string& idHotel);
    /**
     * @brief      Sets the date begin.
     *
     * @param[in]  dateBegin  The date begin
     */
    void setDateBegin(const Date& dateBegin);
    /**
     * @brief      Sets the identifier hotel.
     *
     * @param[in]  idHotel  The identifier hotel
     */
    void setIdHotel(const std::string& idHotel);
	/**
	 * @brief      Sets the identifier room.
	 *
	 * @param[in]  idRoom  The identifier room
	 */
	void setIdRoom(std::string idRoom);
	/**
	 * @brief      Sets the identifier client.
	 *
	 * @param[in]  idClient  The identifier client
	 */
	void setIdClient(std::string idClient);
	/**
	 * @brief      Sets the number of night.
	 *
	 * @param[in]  nbNight  The number of night
	 */
	void setNbNight(int nbNight);
	/**
	 * @brief      Sets the price per night.
	 *
	 * @param[in]  pricePerNight  The price per night
	 */
	void setPricePerNight(float pricePerNight);

    /**
     * @brief      Generate a random id from 0 to 9999
     */
    void generateId();

    /**
     * @brief      Equality operator.
     *
     * @param[in]  r     The reservation
     *
     * @return     The result of the equality
     */
    bool operator == (const Reservation& r) const;
};

/**
 * @brief      Determines if reservation is valid.
 *
 * @param[in]  dateBegin   The date begin
 * @param[in]  idHotel     The identifier hotel
 * @param[in]  idRoom      The identifier room
 * @param[in]  idHClient   The identifier h client
 * @param[in]  nbNight     The number of night
 * @param[in]  priceTotal  The price total
 *
 * @return     True if reservation is valid, False otherwise.
 */
bool isReservationValid(Date dateBegin, const std::string& idHotel,const std::string& idRoom,const std::string& idHClient,
                        int nbNight, float priceTotal);
/**
 * @brief      Determines whether the specified reservation r is valid.
 *
 * @param[in]  r     the reservation
 *
 * @return     True if the specified reservation r is valid, False otherwise.
 */
bool isReservationValid(const Reservation& r);

/**
 * @brief      Finds a specified reservation by its id in a list of reservations.
 *
 * @param[in]  reservations  The reservations
 * @param[in]  id            The identifier
 *
 * @return     The specified reservation
 */
Reservation findReservation(const std::vector<Reservation> &reservations,const std::string& id);
/**
 * @brief      Cancel/remove a specified reservation in a list of reservations.
 *
 * @param      reservations  The reservations
 * @param[in]  r             the reservation to be canceled
 *
 * @return     true if the cancellation was successful, false otherwise 
 */
bool cancelReservation(std::vector<Reservation> &reservations, const Reservation& r);
/**
 * @brief      Display the list of reservations if show = true
 *
 * @param[in]  reservations  The reservations
 * @param[in]  show          The show
 *
 * @return     a string represent the list of reservations
 */
std::string displayReservations(const std::vector<Reservation> &reservations, bool show = false);

/**
 * @brief      Get a string description of the reservation r
 *
 * @param[in]  r the reservation
 *
 * @return     a string description of the reservation r
 */
std::string to_string(const Reservation &r);
/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os           The operating system
 * @param[in]  reservation  The reservation
 *
 * @return     The result of the bitwise left shift
 */
std::ostream &operator<<(std::ostream &os, const Reservation &reservation);