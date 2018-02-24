//
// Created by aris on 21/02/18.
//

#ifndef SUBSHIFT_SRTTIME_H
#define SUBSHIFT_SRTTIME_H

#include <string>

using namespace std;

class SrtTime {
    // Pretty self-explanatory
    int hours;
    int minutes;
    int seconds;
    int milliSeconds;

public:
    SrtTime(
            int hours,
            int minutes,
            int seconds,
            int milliSeconds
    );

    /*
     * Adds 2 time objects
     * and returns the result to
     * this time object. (+=).
     */
    void operator+=(const SrtTime& srtTime);
    void operator-=(const SrtTime& srtTime);

    /*
     * Overloaded operator of comparison
     * for the SrtTime type.
     */
    bool operator>(const SrtTime& srtTime);

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    int getMilliSeconds() const;

    string toString() const;   // format: HH:MM:SS,LLL


};


#endif //SUBSHIFT_SRTTIME_H
