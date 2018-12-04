OBJECTS = main.o Login.o Member.o  UndergraduateStudent.o GraduateStudent.o Student.o Professor.o 

CC = g++
CFLAGS = -c
TARGET = Main

$(TARGET): $(OBJECTS)
	$(CC) -g -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)

main.o: main.cpp
Login.o : Login.cpp
Member.o : Member.cpp
Professor.o : Professor.cpp
Student.o : Student.cpp
UndergraduateStudent.o : UndergraduateStudent.cpp
GraduateStudent.o : GraduateStudent.cpp