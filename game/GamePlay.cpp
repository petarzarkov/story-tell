#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../player/Player.h"
#include "Game.h"

using namespace std;

void Game::play()
{
    string chosenAction = "stop";
    string chosenPlayer = "none";
    while (running)
    {
        cout << "What do you want to do? (available actions:";
        for (const string &availableAction : actions)
        {
            cout << "| " << availableAction << " |";
        }
        cout << "): ";
        cin >> chosenAction;

        if (chosenAction == "stop")
        {
            stop();
        }

        if (chosenAction == "speak")
        {
            cout << "Which player wants to speak? (players:";
            for (Player &player : ptrPlayers)
            {
                cout << "| " << player.name << " |";
            }
            cout << "): ";
            cin >> chosenPlayer;
            auto it = find_if(ptrPlayers.begin(), ptrPlayers.end(), [&chosenPlayer](const Player &obj)
                              { return obj.name == chosenPlayer; });
            if (it != ptrPlayers.end())
            {
                int pIndex = it - ptrPlayers.begin();
                ptrPlayers[pIndex].speakPrompt();
            }
            else
            {
                cout << "No such player: " << chosenPlayer << endl;
            }
        }
    }
}