CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
		 -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations \
		 -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual \
		 -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel \
		 -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

OBJECTS = main.o chborder.o

SOURCE = main.cpp chborder.cpp

out: $(OBJECTS)
	g++ $(OBJECTS) -o frame.exe

main: main.cpp
	g++ $(CFLAGS) -c main.cpp

chborder: chborder.cpp chborder.h
	g++ $(CFLAGS) -c chborder.cpp


touch_all:
	touch $(SOURCE)