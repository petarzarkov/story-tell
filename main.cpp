#include <iostream>
#include <string>
#include <vector>
#include "./game/Game.h"

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

    // Use automatic memory
    Game game(players);
    game.start();

    cout << endl;

    return 0;
}