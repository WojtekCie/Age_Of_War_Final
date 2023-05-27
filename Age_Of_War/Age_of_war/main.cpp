#include <iostream>
#include "MainMenu.h"

//Same zipki w grupie

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
