#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;


const char *getInput(int input)
{
    switch (input) {
        case 1 :  return "Rock";    break;
        case 2 :  return "Paper";    break;
        case 3 :  return "Scissor";   break;
        default : return NULL;        break;
    }
    return NULL;
}

int main()
{
    int player, computer, tries;
    char quit;
    cout << "-----ROCK PAPER SCISSOR-----" << endl;
    srand(time(NULL));
    for (tries = 0;; tries++) {
        computer = rand() % 3 + 1;
        cout << "Please enter your input. 1=Rock, 2=Paper, 3=Scissor" << endl;
        cin >> player;
        switch(computer) {
            case 1 :
                if (player == 1) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "Draw!" << endl << endl;
                } else if (player == 2) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "You win!" << endl << endl;
                } else if (player == 3) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "You lose!" << endl << endl;
                } else {
                    cout << "Input error!" << endl << endl;
                }
                break;
            case 2 :
                if (player == 1) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "You lose!" << endl << endl;
                } else if (player == 2) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "Draw!" << endl << endl;
                } else if (player == 3) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "You win!" << endl << endl;
                } else {
                    cout << "Input error!" << endl << endl;
                }
                break;
            case 3 :
                if (player == 1) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "You win!" << endl << endl;
                } else if (player == 2) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "You lose!" << endl << endl;
                } else if (player == 3) {
                    cout << "You choose: " << getInput(player) << endl;
                    cout << "Computer choose: " << getInput(computer) << endl;
                    cout << endl;
                    cout << "Draw!" << endl << endl;
                } else {
                    cout << endl << "Input error!" << endl << endl;
                }
                break;
            default:
                break;
        }
        cout << "Stop the game? [y]";
        cin >> quit;
        if (quit == 'y') {
            break;
        }
        cout << "----------------------------" << endl;
    }
}