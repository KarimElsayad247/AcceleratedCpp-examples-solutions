CFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
		 -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations \
		 -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual \
		 -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel \
		 -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

OBJECTS = grade.o main.o median.o Student_info.o analyze_grades.o average.o 

SOURCE = Student_info.cpp median.cpp grade.cpp analyze_grades.cpp main.cpp average.cpp

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

analyze_grades: analyze_grades.cpp analyze_grades.h
	g++ $(CFLAGS) -c analyze_grades.cpp

average: average.cpp average.h
	g++ $(CFLAGS) -c average.cpp


touch_all:
	touch $(SOURCE)