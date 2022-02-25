#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <cctype>
#include <locale>
#include "Player.h"

using namespace std;

int main()
{
    int maxPlayers = 5;
    int playerCount = 0;
    while (playerCount == 0 || playerCount > maxPlayers)
    {
        cout << "Please input player count, maximum " << maxPlayers << " players: ";
        cin >> playerCount;

        if (cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Please enter numbers only." << endl;
        }
    }

    vector<string> players;
    string playerName;
    int playerNumber = 1;
    while (players.size() != playerCount)
    {
        cout << "Please input name for player" << playerNumber << ": ";
        cin >> playerName;
        if (cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Please enter proper names only." << endl;
            continue;
        }
        players.push_back(playerName);
        playerNumber += 1;
    }

    for (const string &pName : players)
    {
        unique_ptr<Player> ptrNewPlayer(new Player(pName));
        string introduce = "n";
        cout << ptrNewPlayer->name + ", would you like to introduce yourself? (y|n): ";
        cin >> introduce;
        if (introduce == "y")
        {
            ptrNewPlayer->speak("Hi, my name is " + ptrNewPlayer->name);
        }
    }

    cout << endl;

    return 0;
}