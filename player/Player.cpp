#include <iostream>
#include <string>

using namespace std;

class Player
{

public:
    string name;
    void speak(string speech)
    {
        cout << name << " says: " << endl
             << "- \"" + speech + "\"" << endl;
    }
    Player(string pName)
    {
        name = pName;
        cout << "Player created: " << name << endl;
    }
    ~Player()
    {
    }
};