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
	/**
	 * @brief      Constructs a new instance.
	 *
	 * @param[in]  number         The number
	 * @param[in]  type           The type
	 * @param[in]  pricePerNight  The price per night
	 */
	Room(std::string number, Type type, float pricePerNight);

	/**
	 * @brief      Gets the number.
	 *
	 * @return     The number.
	 */
	std::string getNumber() const;
	/**
	 * @brief      Gets the type.
	 *
	 * @return     The type.
	 */
	Type getType() const;
	/**
	 * @brief      Gets the price per night.
	 *
	 * @return     The price per night.
	 */
	float getPricePerNight() const;

	/**
	 * @brief      Sets the number.
	 *
	 * @param[in]  _number  The number
	 */
	void setNumber(std::string _number);
	/**
	 * @brief      Sets the type.
	 *
	 * @param[in]  type  The type
	 */
	void setType(Type type);
	/**
	 * @brief      Sets the price per night.
	 *
	 * @param[in]  price  The price
	 */
	void setPricePerNight(float price);

	/**
	 * @brief      Equality operator : r1 == r2.
	 *
	 * @param[in]  r     The room
	 *
	 * @return     The result of the equality
	 */
	bool operator == (const Room& r) const;
};


/**
 * @brief      Determines if the room is valid.
 *
 * @param[in]  number         The number
 * @param[in]  type           The type
 * @param[in]  pricePerNight  The price per night
 *
 * @return     True if room is valid, False otherwise.
 */
bool isRoomValid(std::string number, Type type, float pricePerNight);
/**
 * @brief      Determines whether the specified room r is valid.
 *
 * @param[in]  r     The room
 *
 * @return     True if the specified room r is valid, False otherwise.
 */
bool isRoomValid(const Room& r);

/**
 * @brief      Get a string description of the room r
 *
 * @param[in]  r the room
 *
 * @return     a string description of the room r
 */
std::string to_string(const Room &r);
/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os     The operating system
 * @param[in]  room  The room
 *
 * @return     The result of the bitwise left shift
 */
std::ostream &operator<<(std::ostream &os, const Room &room);