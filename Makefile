

all: main

main: main.h main.cpp
	g++ -std=c++11 -o main main.cpp

