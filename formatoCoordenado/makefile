CC = g++
CFLAGS = -Wall
TARGET = a
SRCDIR = /home/larata/Escritorio/ProyectoCalrare/formatoCoordenado
SRCS = $(SRCDIR)/main.cpp $(SRCDIR)/matrizDispersa.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
