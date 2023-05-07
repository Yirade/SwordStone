CC=g++
CFLAGS=-I./libs/SFML/include
LDFLAGS=-L./libs/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
SRC=./source/main.cpp
OBJ=$(SRC:.cpp=.o)
EXECUTABLE=./source/game

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
