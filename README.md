# subshift
  A simple SubRip subtitle shifter.
  Reads ".srt" files and spits out the shifted ones.

### Installation
  Install with makefile provided, or CMake.
  the executable produced from is named "sshift"


### Usage
  $ ./sshift [FILE] [OPTION] ... 

  can run with various options:

  * -v : be more verbose
  * -f [SECONDS] : shift the subtitles forward [SECONDS]
  * -b [SECONDS] : shift the subtitles backward [SECONDS]
