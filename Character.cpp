#include "Character.h"

Character::Character(SDL_Surface *character_sprite, int width, int height){
	sprite = character_sprite;
	clip.x=65;
	clip.y=0;
	clip.w=width;
	clip.h=height;
}


Character::~Character(){
	SDL_FreeSurface(sprite);
}
