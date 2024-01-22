#include "Player.h"

#include <iostream>
#include <string>

// iostream is asserted to be in a standard include directory, while Player.h is asserted to be in the current working directory

using namespace std;

// Initialize static data
int Player::num_players = 0;

// Implement static method
int Player::get_num_players () {return num_players;}

// No-arg Constructor
Player::Player() {                                                
    name = "None";                                              // Assignment not initialization
    health = 0;
    xp = 0;
}

// Overloaded Constructor
Player::Player(std::string name_val) {
    name = name_val;
    health = 0;
    xp = 0;
    ++num_players;
}

// Initializer list (delegating constructor)
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
        ++num_players;
    }         
// Implementing Copy Constructor
Player::Player (const Player &source)
    : name{source.name}, health{source.health}, xp{source.xp} {}

//Destructor
Player::~Player() {
    --num_players;
}

// talk Method
void Player :: talk (std::string text_to_say) {
    cout << text_to_say << endl;              
}

// is_dead Method
bool Player :: is_dead (int xp) {
    if (xp == 0)
        return true;
    else
        return false;
}

