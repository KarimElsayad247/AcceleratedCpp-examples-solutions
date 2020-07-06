CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
		 -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations \
		 -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual \
		 -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel \
		 -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

OBJECTS = grade.o main.o median.o Student_info.o

SOURCE = Student_info.cpp median.cpp grade.cpp main.cpp

out: $(OBJECTS)
	g++ $(OBJECTS) -o calcGrades.exe

main: main.cpp
	g++ $(CFLAGS) -c main.cpp

grade: grade.cpp grade.h
	g++ $(CFLAGS) -c grade.cpp	

median: median.cpp median.h
	g++ $(CFLAGS) -c median.cpp

Student_info: Student_info.cpp Student_info.h
	g++ $(CFLAGS) -c Student_info.cpp


touch_all:
	touch $(SOURCE)