#include "Game.h"

#include <iostream>

using std::cout;
using std::endl;


void Instructions();


int main()
{
    Instructions();

    do
    {
        Game GameSession(1);

        GameSession.Play();

        cout << "Game Over." << endl;

    }while (GameSession.GameOver == False);


    return 0;
}//



void Instructions()
{
    cout << "Welcome!" << endl;


}//
