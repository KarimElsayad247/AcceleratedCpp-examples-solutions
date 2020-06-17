CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
		 -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations \
		 -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual \
		 -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel \
		 -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

OBJECTS = main.o split.o table.o

SOURCE = main.cpp split.cpp table.cpp

out: $(OBJECTS)
	g++ $(OBJECTS) -o crossReference.exe

main: main.cpp
	g++ $(CFLAGS) -c main.cpp

split: split.cpp split.h
	g++ $(CFLAGS) -c split.cpp

table: table.cpp table.h
	g++ $(CFLAGS) -c table.cpp	

touch_all:
	touch $(SOURCE)