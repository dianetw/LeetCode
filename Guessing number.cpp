/**
 *  Author: Diane
 *  Create on: 2021/11/8
 *  
 */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int result, guess_num, tries;
    cout << "------GUESSING NUMBER------" << endl;
    srand(time(NULL));  // seed random number generator
    result = rand() % 100 + 1;  // random number is in range 1 to 100
    for(tries = 0;; tries++) {
        cout << "Please enter a guess number between 1 and 100: ";
        cin >> guess_num;
        if (guess_num > result) {
            cout << "Higher! Try again." << endl << endl;
        } else if (guess_num < result) {
            cout << "Lower! Try again." << endl << endl;
        } else {
            cout << "Correct! You got it in " << tries << " guesses." << endl;
            break;
        }
        if (tries == 10) {
            cout << "Game over!" << endl;
            break;
        }
    }
        
    cout << endl; 
    return 0;
}