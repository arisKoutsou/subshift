//
// Created by telis on 18/02/18.
//

#include <cstdlib>
#include <iostream>
#include <cstring>

#include "SrtShifter.h"

using namespace std;

int main(int argc, char* argv[]) {

    cout << "This is the Subtitle Shifter!" << endl;
    cout << "But it's still being constructed..." << endl;
    cout << endl;

    string file("./samples/eternal-sunshine.srt");

    while (--argc) {
        file = argv[argc];
    }

    SrtShifter srtShifter(file);

    if (!srtShifter.ready()) {
        cerr << "Error opening file: " << file << endl;
        exit(EXIT_FAILURE);
    }

    srtShifter.shiftForward(SrtTime(00, 00, 01, 000));
    srtShifter.shiftBackwards(SrtTime(00, 00, 01, 000));

    return EXIT_SUCCESS;
}
