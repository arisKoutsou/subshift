//
// Created by telis on 18/02/18.
//

#include <cstdlib>
#include <iostream>

#include "SrtShifter.h"
#include "SrtTime.h"


using namespace std;

int main(int argc, char* argv[]) {

    cout << "This is the Subtitle Shifter!" << endl;
    cout << "But it's still being constructed..." << endl;
    cout << endl;

    SrtShifter srtShifter("../eternal-sunshine.srt");

    srtShifter.shiftForward(SrtTime(00, 00, 01, 000));

    return EXIT_SUCCESS;
}
