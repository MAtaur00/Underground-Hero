#include "Settings.h"
#include "j1Gui.h"
#include "j1Textures.h"
#include "j1Render.h"
#include "p2Log.h"
#include "j1Window.h"
#include "j1App.h"
#include "Menu.h"
#include "Brofiler/Brofiler.h"

Settings::Settings()
{
	name.create("credits");
}

Settings::~Settings() {}

bool Settings::Awake(pugi::xml_node& conf)
{
	bool ret = true;
	return ret;
}

bool Settings::Start()
{
	bg_image = (Image*)App->gui->AddImage(0, 0, { 0, 0, 1024, 640 }, NULL, this);

	vsync_checkbox = (CheckBox*)App->gui->AddCheckbox(200, 200, { 1419, 562, 26, 27 }, { 1452, 562, 26, 27 }, "VSYNC",  NULL, this);

	button_back = (Button*)App->gui->AddButton(550, 300, { 1595, 71, 246, 59 }, { 1595, 327, 246, 59 }, { 1595, 190, 246, 59 }, "Back", NULL, this);

	return true;
}

bool Settings::PreUpdate()
{
	return true;
}

bool Settings::Update(float dt)
{
	return true;
}

void Settings::CallBack(UI_Element* element)
{
	if (element == button_back)
	{
		active = false;
		App->menu->active = true;
		CleanUp();
		App->menu->Start();
	}
}

bool Settings::PostUpdate()
{
	return true;
}

bool Settings::CleanUp()
{
	if (has_started)
	{
		App->gui->UI_elements.del(App->gui->UI_elements.At(App->gui->UI_elements.find(bg_image)));
		App->gui->UI_elements.del(App->gui->UI_elements.At(App->gui->UI_elements.find(button_back->text)));
		App->gui->UI_elements.del(App->gui->UI_elements.At(App->gui->UI_elements.find(button_back)));
		App->gui->UI_elements.del(App->gui->UI_elements.At(App->gui->UI_elements.find(vsync_checkbox->text)));
		App->gui->UI_elements.del(App->gui->UI_elements.At(App->gui->UI_elements.find(vsync_checkbox)));

		delete bg_image;
		delete button_back;
		delete vsync_checkbox;

		has_started = false;
	}

	return true;
}