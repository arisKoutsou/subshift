# makefile
#

CC=g++
CFLAGS= -std=c++98 -ggdb -Wall
SOURCES = $(shell find -name "*.cpp")
HEADERS = $(shell find -name "*.h")

sshift : $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o sshift

.PHONY: clean

clean:
	rm -f sshift
