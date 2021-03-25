// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Component.h

#ifndef COMPONENT_H
#define COMPONENT_H

#include <ncurses.h>

#include "Numbers.h"
#include "Time.h"

// Class Component inherits from Class Time and Class Numbers
class Component: public Time, public Numbers {
  public:
    // Constructor
    // inputs:
    // title - title of the window
    // height - row height of the window
    // width - column width of the window
    // verticalPos - vertical position of the component window withing the
    // main window
    // horizontalPos - horizontal position of the component window withing the
    // main window
    // outline - a boolean indicating if the component window should be outlined
    Component(string title, int height, int width, int verticalPos,
        int horizontalPos, bool outline);

    // Virtual function draw
    // A required function implementation for child classes
	virtual void draw() = 0;

    // Function getWin
    // An ncurses function that fetches the created component window
    WINDOW *getWin();

  private:
  	// Data member WINDOW
    // An ncurses type that hold a window object. This is the component window.
    WINDOW *win;
};

#endif
