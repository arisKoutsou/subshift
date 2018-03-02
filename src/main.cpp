//
// Created by telis on 18/02/18.
//

#include <cstdlib>
#include <iostream>
#include <cstring>

#include "SrtShifter.h"
#include <unistd.h>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {

    string file;    // Subtitle file to open and process.
    int c;
    bool verbose = false;   // If this variable is set, the program logs output info.
    bool forwards;  // Indicates whether the subtitles are shifted forward.
    double shamt;   // The shift amount for the subtitles.
    stringstream s; // for reading the double shamt.

    while ((c = getopt (argc, argv, "f:b:v::")) != EOF)
        switch (c)
        {
            case 'f':
                forwards = true;
                s << optarg;
                s >> shamt;
                break;
            case 'b':
                forwards = false;
                s << optarg;
                s >> shamt;
                break;
            case 'v':
                verbose = true;
                break;
            case '?':
                if (optopt == 'f' || optopt == 'b')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                             "Unknown option character `\\x%x'.\n",
                             optopt);
                return 1;
            default:
                abort ();
        }

    if (optind < argc) {
        do {
            file = argv[optind];
        }
        while ( ++optind < argc);
    }

    if (verbose) {
        cout << "Initializing from file:\n\t"
             << file << endl << endl;
    }

    SrtShifter srtShifter(file);

    if (!srtShifter.ready()) {
        cerr << "Error opening file: " << file << endl;
        exit(EXIT_FAILURE);
    }

    if (verbose) {
        cout << "Done\n" << endl;
        cout << "Shifting the subtitles..." << endl;
        cout << "Shift amount: " << SrtTime(shamt).toString();
        cout << (forwards ? " forward" : " backward") << endl << endl;
    }

    if (forwards) {
        srtShifter.shiftForward(SrtTime(shamt));
    } else {
        srtShifter.shiftBackward(SrtTime(shamt));
    }

    if (verbose) cout << "Done" << endl;

//    srtShifter.shiftForward(SrtTime(4));
    return EXIT_SUCCESS;
}
