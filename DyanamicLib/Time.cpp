#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

extern "C" _declspec(dllexport) int CheckTime()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    printf("The local date and time is: %s\n", dt);
    tm* ltm = localtime(&now);
    if (ltm->tm_hour < 9 || ltm->tm_hour > 18) return printf("Turn off the computer! Working time is over, it's time to relax :)\n");
    else
    {
        int wh = 18 - ltm->tm_hour;
        printf("Until the end of the working day left: %d hour(s) :(\n", wh);
    }
    return 1;
}