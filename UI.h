#pragma once

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "PasswordGenerator.h"

class UI
{
public:
	UI(PasswordGenerator& pg);
	void Run();


private:
	sf::RenderWindow window;
	tgui::Gui gui;

	bool chekCheckBox(tgui::CheckBox::Ptr checkBox);
	int getPassSize(tgui::EditBox::Ptr editBox);
	bool isEmpty(tgui::EditBox::Ptr editBox);

};

