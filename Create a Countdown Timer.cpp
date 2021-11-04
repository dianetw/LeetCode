/******************************************************************************

Arther : Diane
2020/11/3

*******************************************************************************/

#include <iostream>
#include <cstring>
#include <ctime>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

#define ARRSIZE(t) (sizeof(t)/sizeof(t[0]))

typedef struct {
    int hour = (-1);
    int minute = (-1);
    int second = (-1);
} coundowntime_t;

static coundowntime_t timer;

void CountdownTimerSet(int hour, int minute, int second)
{
    timer.hour = hour;
    timer.minute = minute;
    timer.second = second;
}

void CountdownTimer()
{
    for (int hour = timer.hour; hour >= 0; hour--) {
        for (int min = timer.minute; min >= 0; min--) {
            if (min == 0 && timer.hour > 0) {
                timer.minute = 59;
            }
            for (int sec = timer.second; sec >= 0; sec--) {
                if (sec == 0) {
                    timer.second = 59;
                }
                sleep(1);

                cout << hour << " : " << min << " : " << sec << endl;
                if (hour == 0 && min == 0 && sec == 0) {
                    cout << "Time is up!" << endl;
                }
            }
        }
    }
    sleep(1);
}

static int split(int separator, char *string, char **tokens, int maxtokens)
{
    int n_tokens = 0;
    while (string && *string == separator) {  // Skip leading separators
        string++;
    }
    /* Start splitting */
    while (n_tokens < maxtokens && string) {
        tokens[n_tokens++] = string;  // We are pointing at first token
        if (n_tokens < maxtokens) {  // Next delimiter
            if ((string = strchr(string, separator))) {
                *string = '\0';
                string++;
            }
        }
    }
    return n_tokens;
}

int main()
{
    char *temp;
    temp = (char *) malloc(8);
#define ARGCT 3  // hour minute second
    char *time_args[ARGCT];
    int i_hour = 0, i_min = 0, i_sec = 0;
    cout << "------COUNTDOWN TIMER------" << endl;
    cout << "Input time (HH:mm:ss): ";
    cin >> temp;
    cout << "Start timer...\n" << endl;
    if (split(':', temp, time_args, ARRSIZE(time_args)) == ARRSIZE(time_args)) {
        for (int i = 0; i < ARGCT; i++) {
            if (!isdigit(*time_args[i])) {  // only numberic enable
                cout << "% Digital only." << endl;
                return false;
            }
        }

        i_hour = atoi(time_args[0]);
        i_min = atoi(time_args[1]);
        i_sec = atoi(time_args[2]);
        /* check the range of hours, minutes, and seconds */
        if ((i_hour > 23 || i_hour < 0) || (i_min > 59 || i_min < 0) || (i_sec > 59 || i_sec < 0)) {
            cout << "% Invalid values." << endl;
            return false;
        }
        CountdownTimerSet(i_hour, i_min, i_sec);  // set timer
    }
    CountdownTimer();
    
    return (0);
}
