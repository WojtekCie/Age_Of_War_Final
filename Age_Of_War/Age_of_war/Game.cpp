#include "Game.h"
#include "UserInterface.h"

//VARIABLES
void Game::InitVariables()
{
    this->event=nullptr;
    this->interface_tex=nullptr;
    this->interface = nullptr;
    this->window=nullptr;
    this->digitals=nullptr;
    this->video_size=this->video_size.getDesktopMode();
}

//TEXTURES
void Game::LoadTextures()
{
  //background tex
  if(!medieval_back_tex.loadFromFile("textures/background_medieval.png"))
  {
      std::cout<<"Couldn't load texture 'background'\n";
  }

  //user interface ui
  interface_tex=new sf::Texture;

  if(!interface_tex->loadFromFile("textures/GUI.png"))
  {
      std::cout<<"Coulnd't load texture 'GUI'\n";
  }




}
//FONTS
void Game::LoadFonts()
{
    this->digitals = new sf::Font();
    if(!this->digitals->loadFromFile("fonts/PixelFJVerdana12pt.ttf"))
    {
        std::cout<<"couldn't load font\n";
    }
}

//WINDOW
void Game::InitWindow()
{
    this->window = new sf::RenderWindow(this->video_size,"Age_Of_War");
    this->event = new sf::Event();
    this->window->setFramerateLimit(120);
}
//-----! CONSTRUCTOR !-----//
Game::Game()
{

 this->InitVariables();
 this->LoadTextures();
 this->InitWindow();
 this->LoadFonts();

 this->InitBackground();
 this->initButtons();

}
//-----! DESTRUCTOR !-----//
Game::~Game()
{
 delete this->window;
 delete this->interface_tex;
 delete this->interface;
 delete this->event;
 delete this->digitals;
}


bool Game::getWindowIsOpen()
{
    return this->window->isOpen();
}

//BACKGROUND
void Game::InitBackground()
{
    this->medieval_back_sprite.setTexture(this->medieval_back_tex);
}
//BUTTONS
void Game::initButtons()
{
    this->interface= new UserInterface(this->interface_tex,this->window,this->event,this->digitals);
}

void Game::drawInterface()
{

    this->interface->drawInterface();

}



//UPDATING GAME//
void Game::update()
{
    this->PollEvents();

}

void Game::PollEvents()
{
    while(this->window->pollEvent(*event))
    {
        if(this->event->type==sf::Event::Closed)
        {
            this->window->close();
        }


        //Button update
        this->interface->update();

        //Pressed
        if(this->event->type==sf::Event::KeyPressed)
        {

            if(this->event->key.code==sf::Keyboard::Escape)
            {
                this->window->close();
            }



        }


    }
}





//RENDERING GAME//

void Game::render()
{
    this->window->clear(sf::Color::Cyan);

    //--DRAWINGS--//

    //Background
    this->window->draw(this->medieval_back_sprite);

    //Buttons
    this->drawInterface();



    //-----------//



    this->window->display();
}

//-------------//
