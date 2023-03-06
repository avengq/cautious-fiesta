#include <iostream>
#include <string>
#include "PasswordGenerator.h"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

using namespace std;

bool chekCheckBox(tgui::CheckBox::Ptr checkBox) 
{
    return checkBox->isChecked();
}

int getPassSize(tgui::EditBox::Ptr editBox)
{
    string input = editBox->getText().toStdString();
    return stoi(input);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    sf::RenderWindow window(sf::VideoMode(250, 200), "My window");
    tgui::Gui gui(window);

    PasswordGenerator pg;

    auto checkBox = tgui::CheckBox::create();
    auto button = tgui::Button::create();
    auto editBox = tgui::EditBox::create();
    auto resultBox = tgui::EditBox::create();

    checkBox->setText("Special chars");
    checkBox->setPosition(30, 30);
    
    button->setText("Generate");
    button->setPosition(30, 60);

    editBox->setSize(70, 20);
    editBox->setText("Pass Size");
    editBox->setInputValidator(tgui::EditBox::Validator::Int);
    editBox->setPosition(150, 30);

    resultBox->setSize(150, 20);
    resultBox->setPosition(30, 100);
    resultBox->setText("Result");
    
    
    gui.add(editBox);
    gui.add(button);
    gui.add(checkBox);
    gui.add(resultBox);

    button->onClick([checkBox, editBox, resultBox, &pg]() {
        pg.Run(getPassSize(editBox), chekCheckBox(checkBox));
        resultBox->setText(pg.printPassword());
        });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            gui.handleEvent(event);
        }
        
        window.clear(tgui::Color::White);
        gui.draw();
        window.display();
    }

    return 0;
}