#include <SDL/SDL.h>

/*
*
* Character
*
* Class to manage the player character
*
*/

class Character{
private:
	
public:
	SDL_Surface *sprite;
	SDL_Rect clip; // Clip area of the sprite to currently display
	
	
	// Create a character with a given sprite sheet, and display dimension of widthxheight
	Character(SDL_Surface *character_sprite, int width, int height);
	~Character();
};
