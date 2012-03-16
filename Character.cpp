#include "Character.h"

Character::Character(SDL_Surface *character_sprite){
	x=y=0;
	
	sprite = character_sprite;
}


Character::~Character(){
	SDL_FreeSurface(sprite);
}
