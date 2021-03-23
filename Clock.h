// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Clock.h

#include <ncurses.h>

#ifndef CLOCK_H
#define CLOCK_H

#include "Time.h"
#include "Numbers.h"

// Class 
class Clock: public Time, public Numbers {
  public:
    Clock();
    void draw(WINDOW *win);
    void update();

  private:
    int positionOne;
    int positionTwo;
    int positionThree;
    int positionFour;
    int positionFive;
    int positionSix;

    string getAscii(string type, int value, int line);
    int getPositionValue(int position);
};

#endif
