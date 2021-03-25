// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Clock.h

#include <ncurses.h>

#ifndef CLOCK_H
#define CLOCK_H

#include "Component.h"

// Class 
class Clock: public Component {
  public:
    Clock(string title, int height, int width, int verticalPos,
        int horizontalPos, bool outline);
    void draw();

  private:
    int positionOne;
    int positionTwo;
    int positionThree;
    int positionFour;
    int positionFive;
    int positionSix;
    string _title;

    string getAscii(string type, int value, int line);
    int getPositionValue(int position);
    void update();
};

#endif
