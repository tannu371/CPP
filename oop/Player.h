// Class Specification / Declaration

#include<iostream>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {
    std::string name;
    int health;
    int xp; 
    static int num_players;

public:
    // Overloaded constructors
    Player ();                                                          // User defined no-args constructor
    Player (std::string name_val);                                      
    Player (std::string name_val, int health_val, int xp_val);

    // Declaring Copy Constructor
    Player (const Player &source);

    ~Player ();

    static int get_num_players();
    void talk (std::string text_to_say);
    bool is_dead (int xp);
};

#endif