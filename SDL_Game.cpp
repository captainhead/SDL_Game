#include <iostream>
#include <sstream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Character.h"

using namespace std;


SDL_Surface *screen;
SDL_Event event;

const int TICK_RATE = 25; // Number of times to update the screen every second
const int TICK_RATE_INV = 1000/TICK_RATE;

// Player character properties
Character *player_character = NULL;
int player_start_x = 0; // Starting x,y position of the character
int player_start_y = 0;
int player_width = 64; // Width, height of the displayed character sprite (actual loaded sprite image will likely be larger)
int player_height = 64;
int player_speed = 5; // Pixels per frame the character moves
int player_xVel = 0; // Current x,y speed of the character (the distance the sprite is moved in the next frame)
int player_yVel = 0;



// Load an image file into a display formatted surface
SDL_Surface * load_image(const char* filename){
	SDL_Surface *loaded_image = IMG_Load(filename);
	if(loaded_image == NULL)
		return NULL;
		
	SDL_Surface *display_surface = SDL_DisplayFormat(loaded_image);
	SDL_FreeSurface(loaded_image);
	if(display_surface == NULL)
		return NULL;
		
	return display_surface;
}



int main(int argc, char **argv){
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create the window and paint it greenish
	screen = SDL_SetVideoMode(800,600, 32, SDL_SWSURFACE);
	//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x22, 0x88, 0x11));
	
	// Load in the character sprite
	SDL_Surface *character_sprite = load_image("assets/character.png");
	if(character_sprite == NULL){
		cout << SDL_GetError() << endl;
		return 1;
	}
	
	// Create the character object
	SDL_Rect player_pos;
	player_pos.x=player_start_x;
	player_pos.y=player_start_y;
	// Set purple background (255,0,255) to be transparent
	SDL_SetColorKey(character_sprite, SDL_SRCCOLORKEY, SDL_MapRGB(character_sprite->format, 0xFF, 0, 0xFF));
	player_character = new Character(character_sprite, player_width, player_height);
	
	// Blit the character sprite to screen
	//SDL_BlitSurface(player_character->sprite, &player_character->clip, screen, &player_pos);
	
	
	if(SDL_Flip(screen) == -1){
		cout << SDL_GetError() << endl;
		return 1;
	}

	// Run the event loop
	bool quit = false;
	Uint32 start_tick = 0;
	int loops;
	
	while(!quit){
		start_tick = SDL_GetTicks();
		
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.sym){
					case(SDLK_RIGHT):
						player_xVel += player_speed;
						break;
					case(SDLK_LEFT):
						player_xVel -= player_speed;
						break;
				}
			}
			else if(event.type == SDL_KEYUP){
				switch(event.key.keysym.sym){
					case(SDLK_RIGHT):
						player_xVel -= player_speed;
						break;
					case(SDLK_LEFT):
						player_xVel += player_speed;
						break;
				}
			}
			// Detect quit event and break out of game loop
			else if(event.type == SDL_QUIT)
				quit = true;
		}
	
	
		// Move the character
		player_pos.x += player_xVel;
		if(player_xVel != 0){
			if(player_character->clip.x == 0)
				player_character->clip.x = 65;
			else
				player_character->clip.x = 0;
		}
		else
			player_character->clip.x = 0;
		
		
		// Redraw the screen
		SDL_FillRect(screen,  NULL, SDL_MapRGB(screen->format, 0x77, 0x77, 0x77));
		SDL_BlitSurface(player_character->sprite, &player_character->clip, screen, &player_pos);
	
		if(SDL_Flip(screen) == -1){
			cout << SDL_GetError() << endl;
			return 1;
		}
		
		// Delay until the next frame should be drawn
		if(SDL_GetTicks() - start_tick < TICK_RATE_INV)
			SDL_Delay(TICK_RATE_INV - (SDL_GetTicks()-start_tick));
	}

	SDL_Quit();

	return 0;
}

