//
// Created by aris on 18/02/18.
//

#ifndef SUBSHIFT_SRTSHIFTER_H
#define SUBSHIFT_SRTSHIFTER_H

#include <string>

using namespace std;

class SrtShifter {

public:
    /*
     * Constructor provided with
     * the appropriate "srt" file
     * containing the subtitles.
     */
    SrtShifter(const string& subtitleFile);

    /*
     * Shifts the subtitle file
     * <seconds> in time. If <seconds>
     * is negative, the subtitles are
     * shifted back in time. When positive
     * the subtitles are shifted forward in time
     */
    void shift(double seconds);

private:
    string file;    // The subtitle file in a string.

};


#endif //SUBSHIFT_SRTSHIFTER_H
