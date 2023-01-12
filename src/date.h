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
    Date();
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    bool operator == (const Date& d) const; // d1 == d2
    bool operator != (const Date& d) const; // d1 != d2
    bool operator < (const Date& d) const;  // d1 <  d2
    bool operator > (const Date& d) const;  // d1 >  d2
    bool operator <= (const Date& d) const; // d1 <= d2
    bool operator >= (const Date& d) const; // d1 <= d2
    Date operator + (int days) const; // d1 + integer
    Date operator - (int days) const; // d1 - integer
    Date operator ++ (); // prefix increment: ++date
    Date operator -- (); // prefix decrement: --date
    Date operator ++ (int); // use int parameter for postfix increment: date++
    Date operator -- (int); // use int parameter for postfix decrement: date--
};

bool isDate(int year,int month, int day);
bool isDate(const Date& d);
int getDaysInMonth(int month);
int dayOfYear(Date d);

std::string to_string(const Date& d);
std::ostream& operator<<(std::ostream& os, const Date& date);
