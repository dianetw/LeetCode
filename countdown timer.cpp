/**
 *  Author: Diane
 *  Create on: 2021/11/2
 *  
 */
#include <iostream>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define HOUR2MIN(x) (x * 60)
#define MIN2SEC(x) (x * 60)

static int countdown_time = (-1);

void CountdownTimerSet(int second)
{
    countdown_time = second;
}

void CountdownTimer()
{
    while (1) {
        if (countdown_time > 0) {
            cout << "Current Second: " << countdown_time << endl;
            countdown_time--;
            if (countdown_time == 0) {
                cout << "Time is up!" << endl;
            }
        }
        sleep(1);
    }
}

int main()
{
    char *temp;
    temp = (char *) malloc(7);
    int i_hour = 0, i_min = 0, t_min = 0, t_sec = 0;
    cout << "------COUNTDOWN TIMER------" << endl;
    cout << "Input time (hh:mm or mm): ";
    cin >> temp;
    cout << "Start timer...\n" << endl;
    if(strpbrk(temp, ":")) {  // hh:mm
        char *c_hour, *c_min;
        char *saveptr;  // Local strtok_r() context

        c_hour = strtok_r(temp, ":", &saveptr);  // get first token
        c_min = strtok_r(NULL, ":", &saveptr);

        i_hour = atoi(c_hour);
        i_min = atoi(c_min);

        if ((i_hour > 999 || i_hour < 1) || (i_min > 999 || i_min < 0)) {
            cout << "% Invalid values." << endl;
            return false;
        }

        t_min = HOUR2MIN(i_hour) + i_min;
        t_sec = MIN2SEC(t_min);
    } else  {  // mm
        i_min = atoi(temp);
        if (i_min > 999 || i_min <= 0) {
            cout << "% Invalid values." << endl;
            return false;
        }
        t_sec = MIN2SEC(i_min);
    }
    CountdownTimerSet(t_sec);
    CountdownTimer();

    return (0);
}