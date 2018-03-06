# makefile
#

CC=g++
CFLAGS= -std=c++98 -ggdb -Wall
SOURCES = src/main.cpp src/SrtTime.cpp src/SrtShifter.cpp
HEADERS = src/SrtTime.h src/SrtShifter.h

sshift : $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) $(CFLAGS) -o sshift

.PHONY: clean

clean:
	rm -f sshift
