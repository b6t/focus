// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Component.h

#ifndef COMPONENT_H
#define COMPONENT_H

#include <ncurses.h>

#include "Time.h"
#include "Numbers.h"

// Class 
class Component: public Time, public Numbers {
  public:
    Component(int height, int width, int verticalPos, int horizontalPos, bool box);
    WINDOW *getWin();
    virtual void draw() = 0;

  private:
    WINDOW *win;
};

#endif
