CC=g++
exe=game
libs=-lSDL -lSDL_image

all: SDL_Game Character
	$(CC) -o $(exe) SDL_Game.o Character.o $(libs)

SDL_Game: SDL_Game.cpp Character.h
	$(CC) -c SDL_Game.cpp $(libs)

Character: Character.h Character.cpp
	$(CC) -c Character.cpp $(libs)

clean:
	rm -f $(exe)
	rm -f *.o

