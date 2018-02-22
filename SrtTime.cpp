//
// Created by aris on 21/02/18.
//
#include <sstream>
#include <iomanip>

#include "SrtTime.h"

SrtTime::SrtTime(
        int h,
        int m,
        int s,
        int ms
) : hours(h), minutes(m), seconds(s), milliSeconds(ms)
{}

int SrtTime::getHours() const {
    return hours;
}

int SrtTime::getMinutes() const {
    return minutes;
}

int SrtTime::getSeconds() const {
    return seconds;
}

int SrtTime::getMilliSeconds() const {
    return milliSeconds;
}


void SrtTime::operator+=(const SrtTime &srtTime) {

    int remainingSeconds = 0;
    int remainingMinutes = 0;
    int remainingHours = 0;

    int totalMilliSeconds = srtTime.getMilliSeconds()
                            + this->getMilliSeconds();

    remainingSeconds = totalMilliSeconds/1000;  // 1000ms in 1sec.
    this->milliSeconds = totalMilliSeconds%1000;

    int totalSeconds = srtTime.getSeconds()
                       + this->getSeconds()
                       + remainingSeconds;

    remainingMinutes = totalSeconds/60; // 60sec in 1 min.
    this->seconds = totalSeconds%60;

    int totalMinutes = srtTime.getMinutes()
                       + this->getMinutes()
                       + remainingMinutes;

    remainingHours = totalMinutes/60;
    this->minutes = totalMinutes%60;

    this->hours = srtTime.getHours()
                  + this->getHours()
                  + remainingHours;

}

void SrtTime::operator-=(const SrtTime &srtTime) {
    if (*this > srtTime) {
        // Shift the Time.
        if (this->milliSeconds > srtTime.milliSeconds) {
            milliSeconds = this->milliSeconds - srtTime.milliSeconds;
        } else {
            this->seconds--;
            milliSeconds = 1000 + (this->milliSeconds - srtTime.milliSeconds);
        }

        if (this->seconds > srtTime.seconds) {
            seconds = this->seconds - srtTime.seconds;
        } else {
            this->minutes--;
            seconds = 60 + (this->seconds - srtTime.seconds);
        }

        if (this->minutes > srtTime.minutes) {
            minutes = this->minutes - srtTime.minutes;
        } else {
            this->hours--;
            minutes = 60 + (this->minutes - srtTime.minutes);
        }

        hours = this->hours - srtTime.hours;

    } else {
        // throw exception.
    }
}

bool SrtTime::operator>(const SrtTime& srtTime) {
    if (this->hours > srtTime.hours) {
        return true;
    } else if (this->hours == srtTime.hours) {

        if (this->minutes > srtTime.minutes) {
            return true;
        } else if (this->minutes == srtTime.minutes) {

            if (this->seconds > srtTime.seconds) {
                return true;
            } else if (this->seconds == srtTime.seconds) {

                return this->milliSeconds > srtTime.milliSeconds;

            } else {
                return false;
            }

        } else {
            return false;
        }

    } else {
        return false;
    }
}

string SrtTime::toString() const {
    stringstream result;

    result << setw(2) << setfill('0') << hours;
    result << ":";
    result << setw(2) << setfill('0') << minutes;
    result << ":";
    result << setw(2) << setfill('0') << seconds;
    result << ",";
    result << setw(3) << setfill('0') << milliSeconds;

    return result.str();
}