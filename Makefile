OBJECTS = main.o Login.o Member.o Professor.o Student.o UndergraduateStudent.o GraduateStudent.o

CC = g++
CFLAGS = -c
TARGET = Main

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)

main.o: main.cpp
Login.o : Login.cpp
Member.o : Member.cpp
Professor.o : Professor.cpp
Student.o : Student.cpp
UndergraduateStudent.o : UndergraduateStudent.cpp
GraduateStudent.o : GraduateStudent.cpp