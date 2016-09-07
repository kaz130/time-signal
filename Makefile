# Makefile
# Copyright Kazuki Aizawa, 2016-09-07
SHELL = /bin/sh

INC_DIR = include
LIB_DIR = lib

INC =
SRC = time_signal.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = time-signal

CXXFLAGS = -c -O2 -Wall -I$(HOME)/include -I.
LIBS = -lwiringPi -lpthread

CXX = g++

.cpp.o:
	$(CXX) $(CXXFLAGS) $<

all:$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ) *~

$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LIBS)

