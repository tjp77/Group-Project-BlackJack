#include "Game.h"

#include <iostream>

using std::cout;
using std::endl;


void Instructions();


int main()
{
    Instructions();

    bool playagain = false;

    do
    {
        Game GameSession(2);

        GameSession.Play();

        cout << endl << "All player's left. Game Over." << endl;

    }while (playagain == true);


    return 0;

}//



void Instructions()
{
    cout << "Welcome!" << endl;


}//
