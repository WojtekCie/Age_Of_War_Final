#ifndef GAME_H
#define GAME_H
#include "MainMenu.h"
#include "UserInterface.h"
#include <SFML/Graphics.hpp>


class Game
{
private:

/*
  #GAME SETUP
*/
sf::RenderWindow *window;
sf::Event *event;
sf::VideoMode video_size;

void InitVariables();
void InitWindow();
void PollEvents();
void LoadTextures();
void LoadFonts();

/*
  #TEXTURES
*/

//background
private:
sf::Texture medieval_back_tex;
sf::Sprite medieval_back_sprite;

void InitBackground();

/*
    #CLASS USER_INTERFACE INCLUDING BUTTONS
*/
UserInterface *interface;
sf::Texture *interface_tex;
sf::Font *digitals;

void initButtons();
void init_player_info();
void drawInterface();



public:

//Constructor / Destructor
Game();
~Game();


//  ! ! ! !  //
// GAME LOOP //
void update();
void render();
bool getWindowIsOpen();
//  ! ! ! !  //



};

#endif // GAME_H
