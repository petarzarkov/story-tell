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
    cout << "Game ended, summary:" << endl;
    for (Player &player : ptrPlayers)
    {
        cout << player.name << " said the following:"<< endl;
        for (const string &speech : player.speeches) {
            cout << speech << endl;
        }
    }
}

void Game::start()
{
    running = true;
    string introduce = "n";
    string pInput = "n";
    for (Player &player : ptrPlayers)
    {
        cout << player.name + ", would you like to introduce yourself? (y|n): ";
        cin >> introduce;
        if (introduce == "y")
        {
            cout << "Do you want to say something custom? (if not, we will display a basic welcome message from your name) (y|n): ";
            cin >> pInput;
            if (pInput == "y") {
                cout << "Alright, type your message: ";
                cin >> pInput;
                player.speak(pInput);
                continue;
            }
            player.speak("Hi, my name is " + player.name);
        }
    }

    play();
}

void Game::stop() {
    running = false;
}