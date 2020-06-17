output: main.o urlops.o
	g++ main.o urlops.o -o findURL.exe

main.o: main.cpp
	g++ -Wall -c main.cpp

urlops.o: urlops.cpp urlops.h
	g++ -Wall -c urlops.cpp