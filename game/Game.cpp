#include <iostream>
#include <vector>
#include <string>
#include "../player/Player.cpp"

using namespace std;

class Game
{

public:
    int start();
    vector<Player> ptrPlayers;

    Game(vector<string> players)
    {
        cout << "Starting game with players: " << players.size() << endl;
        for (const string &pName : players)
        {
            Player newPlayer(pName);
            ptrPlayers.push_back(newPlayer);
        }
    }
    ~Game()
    {
        cout << "Game ended!" << endl;
    }
};

Game::start()
{
    string introduce = "n";
    for (Player &player : ptrPlayers)
    {
        cout << player.name + ", would you like to introduce yourself? (y|n): ";
        cin >> introduce;
        if (introduce == "y")
        {
            player.speak("Hi, my name is " + player.name);
        }
    }

    return 0;
}