#include "Time.h"

Time::Time() : days(0), hours(0), minutes(0), seconds(0) {}
Time::Time(int d, int h, int m, int s) : days(d), hours(h), minutes(m), seconds(s) { normalize(); }
Time::Time(int h, int m, int s) : days(0), hours(h), minutes(m), seconds(s) { normalize(); }
Time::Time(int h, int m) : days(0), hours(h), minutes(m), seconds(0) { normalize(); }
Time::Time(const Time& other) : days(other.days), hours(other.hours), minutes(other.minutes), seconds(other.seconds) {}

void Time::normalize() {
    minutes += seconds / 60; seconds %= 60;
    hours += minutes / 60; minutes %= 60;
    days += hours / 24; hours %= 24;
}

int Time::getDays() const { return days; }
int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

void Time::setTime(int d, int h, int m, int s) {
    days = d; hours = h; minutes = m; seconds = s;
    normalize();
}

Time& Time::operator=(const Time& right) {
    if (this != &right) {
        days = right.days;
        hours = right.hours;
        minutes = right.minutes;
        seconds = right.seconds;
    }
    return *this;
}

Time Time::operator+(const Time& right) {
    return Time(days + right.days, hours + right.hours, minutes + right.minutes, seconds + right.seconds);
}

Time Time::operator-(const Time& right) {
    int diff = int(*this) - int(right);
    return Time(0, 0, 0, diff);
}

bool Time::operator>(const Time& right) { return int(*this) > int(right); }
bool Time::operator<(const Time& right) { return int(*this) < int(right); }
bool Time::operator>=(const Time& right) { return int(*this) >= int(right); }
bool Time::operator<=(const Time& right) { return int(*this) <= int(right); }
bool Time::operator==(const Time& right) { return int(*this) == int(right); }

ostream& operator<<(ostream& stream, const Time& t) {
    stream << t.days << "d " << t.hours << "h " << t.minutes << "m " << t.seconds << "s";
    return stream;
}

Time::operator int() const {  
    return (((days * 24 + hours) * 60 + minutes) * 60 + seconds);
}
