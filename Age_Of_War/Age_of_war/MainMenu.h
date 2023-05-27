#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>


#define max_buttons 4


class MainMenu{

private:

    int MainMenuSelected;
    sf::VideoMode video_mode_size;
    sf::RenderWindow *window;
    sf::Event event;

    //BUTTONS AND FONT
    sf::Font font;
    sf::Text M_M_Text[max_buttons];


    void pollEvents();
    void initVariables();
    void initWindow();
    void loadButtons();
public:

    //CONSTRUCTOR / DESTRUCTOR
    MainMenu();
    ~MainMenu();

    // NAVIGATIN ON MENU //
    void MoveUp();
    void MoveDown();
    int MainMenuPressed();


    //-----ENTER FROM MENU----//
    //GAME
    void Game_run();
    //
    //OPTIONS
    void Options_run();
    //
    //CREDTIS
    void Credits_run();
    //----------------------//


    //----MAIN MENU LOOP----//
    bool getWindowIsOpen();
    void update();
    void render();
    void draw(sf::RenderWindow &window);
    //---------------------//



};

#endif // MAINMENU_H
