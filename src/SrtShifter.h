//
// Created by aris on 18/02/18.
//

#ifndef SUBSHIFT_SRTSHIFTER_H
#define SUBSHIFT_SRTSHIFTER_H

#include <string>
#include <fstream>

#include "SrtTime.h"

using namespace std;

class SrtShifter {

public:
    /*
     * Constructor provided with
     * the appropriate "srt" file
     * containing the subtitles.
     */
    explicit SrtShifter(const string& subtitleFile);

    /*
     * Shifts the subtitle file
     * <seconds> in time. If <seconds>
     * is negative, the subtitles are
     * shifted back in time. When positive
     * the subtitles are shifted forward in time
     */
    void shiftForward(const SrtTime& shamt);
    void shiftBackwards(const SrtTime& shamt);

    bool ready() const;

//    class FileNotFoundException{};

private:
    class EndOfFileException{}; // Exception about eof.

    class Subtitle {
    public:
        const unsigned int id; // Number of the subtitle, starting from 1.

        SrtTime startTime;
        SrtTime endTime;

        string subtitle;

        Subtitle(
                unsigned int id,
                const SrtTime& startTime,
                const SrtTime& endTime,
                const string& subtitle
        );

    };

    ifstream in;    // The subtitle input file stream.
    ofstream out;   // The new subtitle file (probably with the same name).

    /*
     * Returns the next Subtitle of the file
     * Including it's id, start time, end time.
     * i.e:
     * -------------------
     * 2
     * 3 --> 4
     * This is a subtitle.
     * -------------------
     * This member function also
     * increases the get-pointer of
     * the <in>(ifstream).
     */
    Subtitle nextSubtitle();

    /*
     * This function prints a subtitle
     * (the shifted one...)
     * to the <out>(ofstream)
     */
    void printSubtitle(const Subtitle& subtitle);

};


#endif //SUBSHIFT_SRTSHIFTER_H
