#include "CheckBox.h"
#include "UI.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "Menu.h"
#include "j1Scene.h"
#include "j1Gui.h"


CheckBox::CheckBox(int x, int y, SDL_Rect idle, SDL_Rect click, UI_Element* parent, j1Module* CallBack) : UI_Element(x, y, parent, CallBack) 
{
	this->position.x = x;
	this->position.y = y;
	this->idle = idle;
	this->click = click;

	rect = idle;
}

bool CheckBox::CleanUp()
{
	return true;
}

void CheckBox::UI_Interaction(UI_State state)
{
	switch (state)
	{
	case IDLE:
		rect = idle;
		break;

	case CLICK:
		rect = click;
		break;
	}
}

bool CheckBox::Draw() {
	if (atlas != nullptr)
	{
		App->render->Blit(atlas, position.x, position.y, &rect);
	}
	return true;
}

bool CheckBox::Update(float dt)
{
	if (Intersection())
	{
		if (App->input->GetMouseButtonDown(1))
		{
			rect = click;
			App->scene->vsyncCont = App->config.child("vsync").append_attribute("value").as_bool();
			App->scene->vsyncCont = !App->scene->vsyncCont;
		}
		else rect = idle;
	}

	return true;
}