#ifndef PLAYER_H
#define PLAYER_H

#define const_xp 43
#define const_hp 50
class Player
{
private:
    //GOLD & HP & XP
    int gold_amount;
    int hp;
    int xp;


    void initVariables();
public:

    Player();

    void change_xp(int _xp);
    void change_hp(int _hp);

    //Return player gold, xp, hp
    int current_gold();
    int current_xp();
    int current_hp();

};

#endif // PLAYER_H
