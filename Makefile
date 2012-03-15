CC=g++
exe=game
libs=-lSDL

all:
	$(CC) -o $(exe) SDL_Game.cpp $(libs)

clean:
	rm -f $(exe)

