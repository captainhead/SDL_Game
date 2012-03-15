#include <iostream>
#include <SDL/SDL.h>

using namespace std;



SDL_Event event;



int main(int argc, char **argv){
	cout << "HELLO" << endl;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Surface *screen = SDL_SetVideoMode(800,600, 32, SDL_SWSURFACE);

	// Run the event loop
	bool quit = false;
	while(!quit){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				quit = true;
		}
	}

	SDL_Quit();

	return 0;
}
