#include <iostream>
#include "MainMenu.h"


int main()
{

    //RENDERING MAIN MENU WINDOW
    MainMenu menu;

    //MENU LOOP
    while(menu.getWindowIsOpen())
    {
        //Updating menu
        menu.update();

        //Render menu
        menu.render();

    }//PPPPPPP
}
