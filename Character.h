#include <SDL/SDL.h>


class Character{
private:
	SDL_Surface *sprite;
	
public:
	int x,y;
	
	Character(SDL_Surface *character_sprite);
	~Character();
};
