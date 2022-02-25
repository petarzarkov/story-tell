#include <iostream>
#include <vector>
#include <string>
#include "../player/Player.h"
#include "Game.h"

using namespace std;

Game::Game(vector<string> players)
{
    cout << "Starting game with players: " << players.size() << endl;
    for (const string &pName : players)
    {
        Player newPlayer(pName);
        ptrPlayers.push_back(newPlayer);
    }
}

Game::~Game()
{
    cout << "Game ended!" << endl;
}

void Game::start()
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

}