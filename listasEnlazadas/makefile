CC = g++
CFLAGS = -Wall
SOURCES = main.cpp matrizDispersa.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = a.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
