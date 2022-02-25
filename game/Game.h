#ifndef GAME_H // Don't declare more than once by including the header multiple times.
#define GAME_H
#include "../player/Player.h"
#include <string>

using namespace std;

class Game
{
public:
    bool running;
    void start();
    void stop();
    void play();
    vector<string> actions = {"speak", "stop"};
    vector<Player> ptrPlayers;
    Game(vector<string> players);
    ~Game();
};

#endif