#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;

Player::Player(string pName)
{
    name = pName;
    cout << "Player created: " << name << endl;
    speeches = {};
}

Player::~Player()
{
}

void Player::speak(string speech)
{
    speeches.push_back(speech);
    cout << name << " says: " << endl
         << "- \"" + speech + "\"" << endl;
    
}

void Player::speakPrompt()
{
    string pInput;
    cout << "What do you want to say, " << name << "?" << endl;
    while (pInput.length() == 0)
        getline(cin, pInput);
    speak(pInput);
}