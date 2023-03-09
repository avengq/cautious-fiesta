#include "UI.h"
#include <string>
#include <iostream>

UI::UI(PasswordGenerator& pg) : window(sf::VideoMode(250, 200), "Password Generator"), gui(window)
{
    auto checkBox = tgui::CheckBox::create();
    auto button = tgui::Button::create();
    auto editBox = tgui::EditBox::create();
    auto resultBox = tgui::EditBox::create();
    auto label_passSize = tgui::Label::create();

    checkBox->setText("Special chars");
    checkBox->setPosition(30, 30);

    button->setText("Generate");
    button->setPosition(30, 60);


    label_passSize->setPosition(62, 5);
    label_passSize->setText("Password size");

    editBox->setSize(30, 20);
    editBox->setInputValidator(tgui::EditBox::Validator::Int);
    editBox->setPosition(30, 5);

    resultBox->setSize(150, 20);
    resultBox->setPosition(30, 100);
    resultBox->setDefaultText("Result");
    resultBox->setReadOnly();


    gui.add(editBox);
    gui.add(button);
    gui.add(checkBox);
    gui.add(resultBox);
    gui.add(label_passSize);

    button->onClick([label_passSize, &pg, editBox, checkBox, resultBox, this]() {
        if (editBox->getText().empty())
        {
            label_passSize->setText("<<<< FILL");
        }
        else
        {
            pg.Run(getPassSize(editBox), chekCheckBox(checkBox));
            resultBox->setText(pg.printPassword());
            label_passSize->setText("Password size");
        }
        });

}


void UI::Run()
{
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
}

bool UI::chekCheckBox(tgui::CheckBox::Ptr checkBox)
{
    return checkBox->isChecked();
}

int UI::getPassSize(tgui::EditBox::Ptr editBox)
{
    std::string input = editBox->getText().toStdString();
    return std::stoi(input);
}

bool UI::isEmpty(tgui::EditBox::Ptr editBox)
{
    return editBox->getText().toStdString().empty();
}




