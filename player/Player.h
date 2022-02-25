#ifndef PLAYER_H // Don't declare more than once by including the header multiple times.
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
public:
    string name;
    void speak(string speech);
    Player(string pName);
    ~Player();
};

#endif