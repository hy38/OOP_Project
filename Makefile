OBJECTS = main.o AppController.o Login.o Member.o  UndergraduateStudent.o GraduateStudent.o Student.o Professor.o Request.o ClassroomRentRequest.o ImprovementRequest.o ConsultingRequest.o CertificateIssuing.o

CC = g++
CFLAGS = -c
TARGET = Main

$(TARGET): $(OBJECTS)
	$(CC) -o3 -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)

main.o: main.cpp
AppController.o: AppController.cpp
Login.o : Login.cpp
Member.o : Member.cpp
Professor.o : Professor.cpp
Student.o : Student.cpp
UndergraduateStudent.o : UndergraduateStudent.cpp
GraduateStudent.o : GraduateStudent.cpp
Request.o : Request.cpp
ClassroomRentRequest.o : ClassroomRentRequest.cpp
ImprovementRequest.o : ImprovementRequest.cpp
ConsultingRequest.o : ConsultingRequest.cpp
CertificateIssuing.o : CertificateIssuing.cpp