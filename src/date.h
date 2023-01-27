#include <string>
#include <ctime>
#include <ostream>

#pragma once

class Date {
private:
    //Variables
    int _day;
    int _month;
    int _year;
public:
    /**
     * @brief      Constructs a new instance with today parameter.
     */
    Date();
    /**
     * @brief      Constructs a new instance.
     *
     * @param[in]  day    The day
     * @param[in]  month  The month
     * @param[in]  year   The year
     */
    Date(int day, int month, int year);

    /**
     * @brief      Gets the day.
     * 
     * @return     The day.
     */
    int getDay() const;
    /**
     * @brief      Gets the month.
     * 
     * @return     The month.
     */
    int getMonth() const;
    /**
     * @brief      Gets the year.
     * 
     * @return     The year.
     */
    int getYear() const;

    /**
     * @brief      Sets the day.
     * 
     * @param[in]  day   The new value
     */
    void setDay(int day);

    /**
     * @brief      Sets the month.
     * 
     * @param[in]  month  The month
     */
    void setMonth(int month);
    /**
     * @brief      Sets the year.
     * 
     * @param[in]  year  The year
     */
    void setYear(int year);


    /**
     * @brief      Equality operator : d1 == d2.
     * 
     * @param[in]  d     The date
     * 
     * @return     The result of the equality
     */
    bool operator == (const Date& d) const;

    /**
     * @brief      Inequality operator : d1 != d2.
     *
     * @param[in]  d     The date
     *
     * @return     The result of the inequality
     */
    bool operator != (const Date& d) const;

    /**
     * @brief      Less-than comparison operator : d1 <  d2.
     *
     * @param[in]  d     The date
     *
     * @return     The result of the less-than comparison
     */
    bool operator < (const Date& d) const;

    /**
     * @brief      Greater-than comparison operator : d1 >  d2.
     *
     * @param[in]  d     The date
     *
     * @return     The result of the greater-than comparison
     */
    bool operator > (const Date& d) const;

    /**
     * @brief      Less-than-or-equal comparison operator : d1 <= d2.
     *
     * @param[in]  d     The date
     *
     * @return     The result of the less-than-or-equal comparison
     */
    bool operator <= (const Date& d) const; 

    /**
     * @brief      Greater-than-or-equal comparison operator : d1 <= d2.
     *
     * @param[in]  d     The date
     *
     * @return     The result of the greater-than-or-equal comparison
     */
    bool operator >= (const Date& d) const; 

    /**
     * @brief      Addition operator : d1 + integer.
     *
     * @param[in]  days  The days
     *
     * @return     The result of the addition
     */
    Date operator + (int days) const;

    /**
     * @brief      Subtraction operator : d1 - integer.
     *
     * @param[in]  days  The days
     *
     * @return     The result of the subtraction
     */
    Date operator - (int days) const; /

    /**
     * @brief      Prefix increment operator: ++date.
     *
     * @return     The result of the increment
     */
    Date operator ++ (); 

    /**
     * @brief      Prefix decrement operator: --date.
     *
     * @return     The result of the decrement
     */
    Date operator -- ();

    /**
     * @brief      Postfix increment operator: date++.
     *
     * @param      int parameter
     *
     * @return     The result of the increment
     */
    Date operator ++ (int);

    /**
     * @brief      Postfix decrement operator: date--
     *
     * @param      int parameter
     *
     * @return     The result of the decrement
     */
    Date operator -- (int);
};

/**
 * @brief      Determines if date is valid.
 *
 * @param[in]  year   The year
 * @param[in]  month  The month
 * @param[in]  day    The day
 *
 * @return     True if date is valid, False otherwise.
 */
bool isDate(int year,int month, int day);
/**
 * @brief      Determines whether the specified Date d is valid.
 *
 * @param[in]  d     The date
 *
 * @return     True if the specified d is date, False otherwise.
 */
bool isDate(const Date& d);
/**
 * @brief      Gets the number of days in a month.
 *
 * @param[in]  month  The month
 *
 * @return     The number of days in a month.
 */
int getDaysInMonth(int month);
/**
 * @brief      Gets the day of the year
 *
 * @param[in]  d     The date
 *
 * @return     the day of the year
 */
int dayOfYear(Date d);

/**
 * @brief      Get a string description of the date d
 *
 * @param[in]  d The date
 *
 * @return     a string description of the date d
 */
std::string to_string(const Date& d);

/**
 * @brief      Bitwise left shift operator.
 *
 * @param      os     The operating system
 * @param[in]  date  The date
 *
 * @return     The result of the bitwise left shift
 */
std::ostream& operator<<(std::ostream& os, const Date& date);
