#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

class UserInterface
{
private:
    sf::RenderWindow *window;
    sf::Event *event;
    sf::Texture gui;
    sf::Font font;
    sf::Vector2f mouse_position;

    /*
        #BUTTONS
    */

    //Map of buttons
    std::map<std::string,sf::Sprite> buttons;
    std::map<std::string,sf::IntRect> buttons_animation_rects;
    //Setup of buttons
    void initButtons();
    void init_animation_rects();
    void animate_concave_butt(std::string map_butt, std::string concave_map);
    void animate_convex_butt(std::string map_butt,std::string convex_map);
    void button_blocked_animation();

    bool canAfford(int price_); //checking if you have enough money or xp to click button
    bool canUpgrade(int xp_);

    /*
        #INTERFACE
    */
    sf::Sprite user_info;
    void init_user_info();



    /*
        #MONEY
    */


    void display_player_resources();

    //Setting prices
    int warrior_price=70;
    int archer_price=100;
    int boss_price=200;

    //Prices in shop
    sf::Text gold;
    sf::Sprite coins[3];
    std::map<std::string,sf::Text> prices_in_shop;

    void init_prices();



    /*
        #PLAYER RESOURCES / XP & GOLD AMOUNT & HP
    */

    Player* player;
    sf::Text current_gold;
    int curr_gold;
    int curr_xp;
    int curr_hp;
    bool second_life;



    //xp_bar
    sf::Sprite xp_sprite;

    //hp_double_bar
    sf::Sprite hp_sprite_red;
    sf::Sprite hp_sprite_orange;

    //xp&hp_rects
    sf::IntRect xp_rect;
    sf::IntRect hp_rect_red;
    sf::IntRect hp_rect_orange;

    void initPlayer();
    void updateResources();
    void initResources();

    void init_gold_amount();
    void init_xp_bar();
    void init_hp_bar();

    void update_xp_bar();
    void update_hp_bar();


    /*
      #Class meth
    */

     void pollEvents();


public:
    //constructor & destructor
    UserInterface(sf::Texture *texture, sf::RenderWindow *window_, sf::Event *event_, sf::Font *font_);
    ~UserInterface();

    void drawInterface();

    //Poll events
    void update();

};


#endif // USERINTERFACE_H
