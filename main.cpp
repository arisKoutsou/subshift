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

    SrtShifter srtShifter("../file.srt");

    srtShifter.printSubtitle(srtShifter.nextSubtitle());

    return EXIT_SUCCESS;
}
