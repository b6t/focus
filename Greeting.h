// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Greeting.h
#ifndef GREETING_H
#define GREETING_H

#include <string>

#include <ncurses.h>

#include "Component.h"

using std::string;

// Class Greeting inherits from Class Component
class Greeting: public Component {
  public:
  	// Constructor
    // inputs:
    // title - title of the window
    // name - the name of the individual to be greeted
    // height - row height of the window
    // width - column width of the window
    // verticalPos - vertical position of the component window withing the
    // main window
    // horizontalPos - horizontal position of the component window withing the
    // main window
    // outline - a boolean indicating if the component window should be outlined
    Greeting(string title, string name, int height, int width, int verticalPos,
        int horizontalPos, bool outline);

    // Virtual from Component class
    // A function responsible for displaying the component on the screen
    void draw();

  private:
    string _name;
    int _width;
};

#endif
