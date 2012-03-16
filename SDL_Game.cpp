#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Character.h"

using namespace std;


SDL_Surface *screen;
SDL_Event event;



int main(int argc, char **argv){
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create the window and paint it greenish
	screen = SDL_SetVideoMode(800,600, 32, SDL_SWSURFACE);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x22, 0x88, 0x11));
	
	// Load in the character sprite
	SDL_Surface *loaded_image = IMG_Load("assets/character.png");
	if(loaded_image == NULL){
		cout << SDL_GetError() << endl;
		return 1;
	}
	SDL_Surface *character_sprite = SDL_DisplayFormat(loaded_image);
	if(character_sprite == NULL){
		cout << SDL_GetError() << endl;
		return 1;
	}
	SDL_FreeSurface(loaded_image);
	
	// Blit the character sprite to screen
	SDL_SetColorKey(character_sprite, SDL_SRCCOLORKEY, SDL_MapRGB(character_sprite->format, 0xFF, 0, 0xFF));
	SDL_Rect character_clip;
	character_clip.x = 0;
	character_clip.y = 0;
	character_clip.w = 63;
	character_clip.h = 63;
	SDL_BlitSurface(character_sprite, &character_clip, screen, NULL);
	
	
	if(SDL_Flip(screen) == -1){
		cout << SDL_GetError() << endl;
		return 1;
	}

	// Run the event loop
	bool quit = false;
	while(!quit){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT)
				quit = true;
		}
	}

	SDL_FreeSurface(character_sprite);
	SDL_Quit();

	return 0;
}
