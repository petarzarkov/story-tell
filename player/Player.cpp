#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

Player::Player(string pName)
{
    name = pName;
    cout << "Player created: " << name << endl;
}

Player::~Player()
{
}

void Player::speak(string speech)
{
    cout << name << " says: " << endl
         << "- \"" + speech + "\"" << endl;
}