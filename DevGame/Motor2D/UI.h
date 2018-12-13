#ifndef __UI_H__
#define __UI_H__

#include "p2Point.h"
#include "SDL/include/SDL.h"

struct SDL_Texture;

class UI_Element
{

public:
	fPoint position;
	fPoint original_pos;

	SDL_Texture* atlas = nullptr;

	SDL_Texture* texture = nullptr;

	SDL_Rect debug_UI;

	SDL_Rect rect;

	UI_Element* parent;

public:

	//Constructor
	UI_Element() {}
	UI_Element(int x, int y, UI_Element* parent);

	//Destructor
	virtual ~UI_Element() {}

	// Called each loop iteration
	virtual bool Update(float dt);

	// Called each loop iteration
	virtual bool Draw();


	// Called before quitting
	virtual bool CleanUp();

	virtual bool MouseOnRect();

	virtual void UI_Interaction(UI_State state) {};
};

#endif //__UI__H