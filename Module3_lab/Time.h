#pragma once
#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    int days, hours, minutes, seconds;
    void normalize();

public:
    Time();
    Time(int d, int h, int m, int s);
    Time(int h, int m, int s);
    Time(int h, int m);
    Time(const Time& other);

    int getDays() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    void setTime(int d, int h, int m, int s);

    Time& operator=(const Time& right);
    Time operator+(const Time& right);
    Time operator-(const Time& right);

    bool operator>(const Time& right);
    bool operator<(const Time& right);
    bool operator>=(const Time& right);
    bool operator<=(const Time& right);
    bool operator==(const Time& right);

    friend ostream& operator<<(ostream& stream, const Time& t);
    operator int() const; 
};

#endif
