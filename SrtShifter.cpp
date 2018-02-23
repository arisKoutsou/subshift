//
// Created by telis on 18/02/18.
//

#include <iostream>
#include "SrtShifter.h"

SrtShifter::SrtShifter(const string& subtitleFile)
        : in(subtitleFile.c_str()), out((subtitleFile+".shifted").c_str())
{
    if (!in.is_open()) {
        cout << "Could not open the subtitle file." << endl;
    }

}

SrtShifter::Subtitle::Subtitle(
        const unsigned int i,
        const SrtTime &start,
        const SrtTime &end,
        const string &sub
) : id(i), startTime(start), endTime(end), subtitle(sub)
{}


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
        if (line.empty()) break;
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
}
