CC=g++
exe=SDL_Game
libs=-lSDL

all:
	$(CC) -o $(exe) SDL_Game.cpp $(libs)

clean:
	rm -f $(exe)

