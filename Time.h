// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Time.h

#ifndef TIME_H
#define TIME_H

#include <ncurses.h>

// Class 
class Time {
  public:
    Time();
    virtual void draw(WINDOW *win) = 0;
    void updateTime();
    int getYear();
    int getMonth();
    int getDay();
    int getHours();
    int getMinutes();
    int getSeconds();
    int getUnixTime();

  private:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
    int unixTime;
};

#endif
