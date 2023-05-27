#include "MainMenu.h"
#include "Game.h"


MainMenu::MainMenu()
{
    this->initVariables();
    this->initWindow();
    this->loadButtons();
}


void MainMenu::initVariables()
{

    this->window = nullptr;
    this->video_mode_size.width=800;
    this->video_mode_size.height=800;

}


void MainMenu::initWindow()
{
    this->window = new sf::RenderWindow(this->video_mode_size,"MainMenu");
}


void MainMenu::loadButtons()
{
    if(!this->font.loadFromFile("fonts/fontmenu.ttf"))
    {
        std::cout<<"Couldn't load font \n";
    }

    //PLAY
    this->M_M_Text[0].setFont(this->font);
    this->M_M_Text[0].setFillColor(sf::Color::White);
    this->M_M_Text[0].setString("PLAY");
    this->M_M_Text[0].setCharacterSize(70);
    this->M_M_Text[0].setPosition(this->video_mode_size.width/3,this->video_mode_size.height/4);

    //OPTIONS
    this->M_M_Text[1].setFont(this->font);
    this->M_M_Text[1].setFillColor(sf::Color::White);
    this->M_M_Text[1].setString("OPTIONS");
    this->M_M_Text[1].setCharacterSize(70);
    this->M_M_Text[1].setPosition(this->video_mode_size.width/3,(this->video_mode_size.height/4+100));

    //ABOUT
    this->M_M_Text[2].setFont(this->font);
    this->M_M_Text[2].setFillColor(sf::Color::White);
    this->M_M_Text[2].setString("ABOUT");
    this->M_M_Text[2].setCharacterSize(70);
    this->M_M_Text[2].setPosition(this->video_mode_size.width/3,(this->video_mode_size.height/4+200));

    //EXIT
    this->M_M_Text[3].setFont(this->font);
    this->M_M_Text[3].setFillColor(sf::Color::White);
    this->M_M_Text[3].setString("EXIT");
    this->M_M_Text[3].setCharacterSize(70);
    this->M_M_Text[3].setPosition(this->video_mode_size.width/3,(this->video_mode_size.height/4+300));

    MainMenuSelected=0;
    this->M_M_Text[this->MainMenuSelected].setFillColor(sf::Color::Red);

}

void MainMenu::pollEvents()
{
    while(this->window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            this->window->close();
        }

        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code==sf::Keyboard::Up)
            {
                MoveUp();
                break;
            }

            if(event.key.code==sf::Keyboard::Down)
            {
                MoveDown();
                break;
            }

            if(event.key.code==sf::Keyboard::Return)
            {
                int x = MainMenuPressed();

                //......GAME LOOP.....
                if(x==0)
                {
                   this->Game_run();
                }
                //......................














                //==================TRASH TO DO ===================================

                //OPTIONS LOOP
                if(x==1)
                {
                    sf::RenderWindow Options(sf::VideoMode(960,720),"Options");
                    this->window->setVisible(0);


                    while(Options.isOpen())
                    {

                        sf::Event optionsEvent;
                        while(Options.pollEvent(optionsEvent))
                        {
                            if(optionsEvent.type==sf::Event::Closed)
                            {
                                Options.close();
                                this->window->setVisible(1);
                            }

                            //KEYBOARD EVENT
                            if(optionsEvent.type==sf::Event::KeyPressed)
                            {

                                if(optionsEvent.key.code==sf::Keyboard::Escape)
                                {
                                   Options.close();
                                   this->window->setVisible(1);
                                }

                            }

                        }
                        //Rendering options


                        Options.clear();
                        Options.display();
                    }
                }

                //ABOUT LOOP
                if(x==2)
                {
                    this->window->setVisible(0);
                    sf::RenderWindow About(sf::VideoMode(960,720),"About");
                    while(About.isOpen())
                    {
                        sf::Event aboutEvent;
                        while(About.pollEvent(aboutEvent))
                        {
                            if(aboutEvent.type==sf::Event::Closed)
                            {
                                About.close();
                                this->window->setVisible(1);
                            }

                            //KEYBOARD EVENT
                            if(aboutEvent.type==sf::Event::KeyPressed)
                            {

                                if(aboutEvent.key.code==sf::Keyboard::Escape)
                                {
                                    About.close();
                                    this->window->setVisible(1);
                                }

                            }


                        }
                        //Rendering about

                        About.clear();
                        About.display();
                    }
                }
                if(x==3)
                {
                    this->window->close();

                }

            }

        }
    }
}








MainMenu::~MainMenu()
{
    delete this->window;
}

void MainMenu::Game_run()
{
    Game game;
    this->window->setVisible(0);
    while(game.getWindowIsOpen())
    {
        //Update
        game.update();

        //Render
        game.render();



    }
    this->window->setVisible(1);
}


bool MainMenu::getWindowIsOpen()
{
    return this->window->isOpen();
}

void MainMenu::update()
{
    this->pollEvents();


}

void MainMenu::render()
{
    this->window->clear();
    this->draw(*this->window);
    this->window->display();
}

void MainMenu::draw(sf::RenderWindow &window)
{
    for(int i=0; i<max_buttons;i++)
    {
        window.draw(this->M_M_Text[i]);
    }
}

void MainMenu::MoveUp()
{

    if(this->MainMenuSelected >= -1)
    {
        this->M_M_Text[MainMenuSelected].setFillColor(sf::Color::White);
        MainMenuSelected--;


        if(MainMenuSelected == -1)
        {
            MainMenuSelected = 3;
        }
        std::cout<<this->MainMenuSelected<<"\n";
        this->M_M_Text[MainMenuSelected].setFillColor(sf::Color::Red);

    }
}

void MainMenu::MoveDown()
{
    if(MainMenuSelected <= max_buttons-1)
    {
        this->M_M_Text[MainMenuSelected].setFillColor(sf::Color::White);
        MainMenuSelected++;


        if(MainMenuSelected==4)
        {
            MainMenuSelected=0;
        }
        std::cout<<this->MainMenuSelected<<"\n";
        this->M_M_Text[MainMenuSelected].setFillColor(sf::Color::Red);
    }
}

int MainMenu::MainMenuPressed()
{
    return MainMenuSelected;
}




