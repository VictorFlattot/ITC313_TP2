#include "date.h"
#include <cassert>
#include <iostream>

std::string months[12] = {"Jan", "Feb", "March", "April", "May", "June",
                          "July", "Aug", "Sept", "Oct", "Nov", "Dec"
                        };

Date::Date() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    _day = now->tm_mday;
    _month = now->tm_mon + 1;
    _year =  now->tm_year + 1900;
}

Date::Date(int day, int month, int year):
    _day(day), _month(month), _year(year) {
    assert(isDate(year, month, day) && "Date is not valid");
}

int Date::getDay() const { return _day; }
int Date::getMonth() const { return _month; }
int Date::getYear() const { return _year; }

void Date::setDay(int day) { _day = day; assert(isDate(*this) && "Date is not valid");}
void Date::setMonth(int month) { _month = month; assert(isDate(*this) && "Date is not valid");}
void Date::setYear(int year) { _year = year; assert(isDate(*this) && "Date is not valid");}

Date Date::operator + (int days) const {
    if (days < 0) { //if days <0, we call Date - (-days)
        return *this - (-days);
    }
    Date tmp = *this; // the current date
    int new_day = tmp._day + days; // the new day is ok if new_day < end of months
    int new_month = tmp._month;
    int new_year = tmp._year;
    int days_in_month = getDaysInMonth(tmp._month);
    while (new_day > days_in_month) { // end of the months
        new_day -= days_in_month; // the day in the next months
        ++new_month;
        if (new_month > 12) { // end of the year
            ++new_year;
            new_month = 1;

        }
        //tmp.updateMonth(new_month);
        //days_in_month = getDaysInMonth(tmp._month);
        days_in_month = getDaysInMonth(new_month);
    }
    return {new_day, new_month, new_year};
}

Date Date::operator ++(int) { // postfix increment
    Date tmp = *this;
    *this = tmp + 1;
    return tmp;
}

Date Date::operator --(int) { // postfix decrement
    Date tmp = *this;
    *this = *this - 1;
    return tmp;
}

Date Date::operator ++() { // prefix increment
    *this = *this + 1;
    return *this;
}

Date Date::operator --() { // prefix decrement
    *this = *this - 1;
    return *this;
}

Date Date::operator - (int days) const {
    if (days < 0) { //if days <0, we call Date + (-days)
        return *this + (-days);
    }
    int new_year = _year;
    int new_month = _month;
    int new_day = _day - days; // the new day is ok if > 0
    while (new_day <= 0) {
        if (new_month == 1) { // beginning of the year
            new_year--;
            new_month = 12; // in december
            new_day = 31 + new_day;

        }
        else { // other months than january
            int days_in_previous_month = getDaysInMonth(Date(1,new_month - 1, new_year)._month);
            new_day = days_in_previous_month + new_day;
            new_month--;
        }
    }
    // std::cout<< new_day << "/" << new_month << "/" << new_year << std::endl;

    return {new_day, new_month , new_year};
}

bool Date::operator == (const Date& d) const { // check for equality
    if ((_day == d._day) && (_month == d._month) && (_year == d._year)) {
        return true;
    }
    return false;
}

bool Date::operator !=(const Date& d) const {
    return !(*this == d);
}


bool Date::operator < (const Date& d) const {
    if (_year < d.getYear()) {
        return true;
    }
    else if (_year > d.getYear()) {
        return false;
    } else { //same year
        if (_month < d.getMonth()) {
            return true;
        }
        else if (_month > d.getMonth()) {
            return false;
        }
        else { // same months
            if (_day < d.getDay()) {
                return true;
            }
            else {
                return false;
            }
        }
    }

    return false;
}

bool Date::operator > (const Date& d) const {
    if (*this == d) {
        return false;
    }
    if (*this < d) {
        return false;
    }
    return true;
}

bool Date::operator <=(const Date& d) const {
    if (*this == d) {
        return true;
    }
    return (*this < d);
}

bool Date::operator >=(const Date& d) const {
    if (*this == d) {
        return true;
    }
    return (*this > d);
}


bool isDate(int year, int month, int day) {
    if ((day < 1) || (day > 31)) return false;
    if ((month < 1) || (month > 12)) return false;
    if ((month == 2) && (day > 28)) return false;
    if ((year < 0) || (year > 9999)) return false;
    if (((month == 4) || (month == 6) ||
            (month == 9) || (month == 11)) && (day > 30)) return false;
    return true;
}

bool isDate(const Date& d){
    return isDate(d.getYear(), d.getMonth(), d.getDay());
}

int getDaysInMonth(int month)  {
    assert(((month >= 1) && (month <= 12)) && "Month is not valid");
    if (month == 2) return 28;
    if ((month == 1 || month == 3 || month == 5 || month == 7
            || month == 8 || month == 10 || month == 12)) return 31;
    return 30;
}

int dayOfYear(Date d) {
    auto day = 0;
    for (auto i = 1; i < d.getMonth(); i++) {
        day += getDaysInMonth(i);
    }
    day += d.getDay();
    return day;
}

std::string to_string(const Date& d){
    if (d.getDay() == 1 && d.getMonth() == 1 && d.getYear() == 0) return "Unknown";
    return months[d.getMonth() - 1] + "/" + std::to_string(d.getDay()) + "," + std::to_string(d.getYear());
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << to_string(date);
    return os;
}
