#ifndef TIME_H
#define TIME_H

#include <string>

#include <ncurses.h>

using std::string;

// Base Class Time
class Time {
  public:
    // Constructor Time
    // Initilizes the current local time and stores each element of the
    // timestamp to private data members
    Time();

    // Function updateTime
    // A function that updates the time and the private data members
    void updateTime();

    // Getters
    int getYear();
    int getMonth();
    int getDay();
    int getHours();
    int getMinutes();
    int getSeconds();
    int getUnixTime();
    string getTimeOfDay();

  private:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
    int unixTime;
    string timeOfDay;

    // Function calculateTimeOfDay
    // A function that uses the private data member, hours, to
    // determin what time of day it is. Then stores it to
    // private data member timeOfDay
    void calculateTimeOfDay();
};

#endif
