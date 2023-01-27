#include <string>
#include <vector>
#include "room.h"

#pragma once

class Hotel
{
private:
	std::string _id;
	std::string _name;
	std::string _city;
	std::vector<Room> _rooms;

public:
    /**
     * @brief      Constructs a new instance.
     *
     * @param[in]  id     The identifier
     * @param[in]  name   The name
     * @param[in]  city   The city
     * @param[in]  rooms  The rooms
     */
	explicit Hotel(std::string id, std::string name = {}, std::string city = {}, std::vector<Room> rooms = {});

	/**
	 * @brief      Gets the identifier.
	 *
	 * @return     The identifier.
	 */
	std::string getId() const;
	/**
	 * @brief      Gets the name.
	 *
	 * @return     The name.
	 */
	std::string getName() const;
    /**
     * @brief      Gets the city.
     *
     * @return     The city.
     */
    std::string getCity() const;
	/**
	 * @brief      Gets the rooms.
	 *
	 * @return     The rooms.
	 */
	std::vector<Room> getRooms() const;
    /**
     * @brief      Gets the rooms filtered by a certain type.
     *
     * @param[in]  type  The type
     *
     * @return     The filtered rooms.
     */
	std::vector<Room> getRooms(const Type& type) const;

	/**
	 * @brief      Sets the identifier.
	 *
	 * @param[in]  id    The new value
	 */
	void setId(std::string id);
	/**
	 * @brief      Sets the name.
	 *
	 * @param[in]  name  The name
	 */
	void setName(std::string name);
	/**
	 * @brief      Sets the city.
	 *
	 * @param[in]  city  The city
	 */
	void setCity(std::string city);
	/**
	 * @brief      Sets the rooms.
	 *
	 * @param[in]  rooms  The rooms
	 */
	void setRooms(std::vector<Room> rooms);

    /**
     * @brief      Adds a room to the rooms.
     *
     * @param[in]  room  The room
     *
     * @return     true if the room was correctly added false otherwise
     */
	bool addRoom(const Room& room);
    /**
     * @brief      Removes a room from the rooms.
     *
     * @param[in]  room  The room
     *
     * @return     true if the room was correctly deleted false otherwise
     */
	bool removeRoom(const Room& room);

    Room getRoom(const std::string& id) const;

};

/**
 * @brief      display the rooms
 *
 * @param[in]  h     The hotel
 * @param[in]  show  If true print the rooms in the terminal
 *
 * @return     the string that represent the rooms
 */
std::string displayRooms(const Hotel &h,bool show);

/**
 * @brief      Determines if hotel is valid.
 *
 * @param[in]  id    The identifier
 * @param[in]  name  The name
 * @param[in]  city  The city
 *
 * @return     True if hotel is valid, False otherwise.
 */
bool isHotelValid(const std::string& id,
                  const std::string& name,
                  const std::string& city);
/**
 * @brief      Determines whether the specified hotel h is valid.
 *
 * @param[in]  h 	The hotel
 *
 * @return     True if the specified h is hotel valid, False otherwise.
 */
bool isHotelValid(const Hotel& h);


/**
 * @brief      Get a string description of the Hotel h
 *
 * @param[in]  h The hotel
 *
 * @return     a string description of the Hotel h
 */
std::string to_string(const Hotel &h);
/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os     The operating system
 * @param[in]  hotel  The hotel
 *
 * @return     The result of the bitwise left shift
 */
std::ostream &operator<<(std::ostream &os, const Hotel &hotel);