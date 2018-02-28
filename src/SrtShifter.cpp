//
// Created by telis on 18/02/18.
//

#include <iostream>
#include "SrtShifter.h"

SrtShifter::SrtShifter(const string& subtitleFile)
        : in(subtitleFile.c_str())
{
    if (in.is_open()) {
        out.open((subtitleFile + ".shifted").c_str());
    }
}

SrtShifter::Subtitle::Subtitle(
        const unsigned int i,
        const SrtTime &start,
        const SrtTime &end,
        const string &sub
) : id(i), startTime(start), endTime(end), subtitle(sub)
{}


bool SrtShifter::ready() const {
    return in.is_open() && out.is_open();
}


SrtShifter::Subtitle SrtShifter::nextSubtitle() {

    if (in.eof()) {
        throw EndOfFileException();
    }

    unsigned int subtitleId;
    in >> subtitleId;
    in.ignore(256, '\n');

    int sh, sm, ss, sl;
    int eh, em, es, el;
    char c;
    in >> sh >> c >> sm >> c >> ss >> c >> sl;
    in >> c >> c >> c;
    in >> eh >> c >> em >> c >> es >> c >> el;
    in.ignore(256, '\n');

    string text;
    while (true) {
        string line;
        getline(in, line);
        if (line.empty() || line == "\r") break;
        else {
            text.append(line);
            text.append("\n");
        }
    }
    while (in.peek() == '\n')
        in.get();

    return Subtitle(
            subtitleId,
            SrtTime(sh, sm, ss, sl),
            SrtTime(eh, em, es, el),
            text
    );

}

void SrtShifter::printSubtitle(const SrtShifter::Subtitle &subtitle) {
    out << subtitle.id << endl;
    out << subtitle.startTime.toString() << " --> "
        << subtitle.endTime.toString() << endl;
    out << subtitle.subtitle << endl;
}

void SrtShifter::shiftForward(const SrtTime &shamt) {
    while (true) {
        try {
            Subtitle currentSubtitle = nextSubtitle();

            currentSubtitle.startTime += shamt;
            currentSubtitle.endTime += shamt;

            printSubtitle(currentSubtitle);

        } catch (EndOfFileException e) {
            break;
        }
    }

    in.clear(); // Go to beginning of file for more
    in.seekg(0, ios::beg);  // Shifts...
}

void SrtShifter::shiftBackward(const SrtTime &shamt) {
    while (true) {
        try {
            Subtitle currentSubtitle = nextSubtitle();

            if (currentSubtitle.startTime > shamt) {
                currentSubtitle.startTime -= shamt;
                currentSubtitle.endTime -= shamt;
            } else {
                currentSubtitle.startTime -= currentSubtitle.startTime;
                currentSubtitle.endTime -= currentSubtitle.startTime;
            }

            printSubtitle(currentSubtitle);

        } catch (EndOfFileException e) {
            break;
        }
    }

    in.clear(); // Go to beginning of file for more
    in.seekg(0, ios::beg);  // Shifts...
}



