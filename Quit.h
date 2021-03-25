// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Quit.h
#ifndef QUIT_H
#define QUIT_H

#include <iostream>

#include <ncurses.h>

#include "Component.h"

using namespace std;

// Class 
class Quit: public Component {
  public:
    Quit(string title, int height, int width, int verticalPos,
        int horizontalPos, bool outline);
    void draw();
    bool getQuit();

  private:
    int _width;
    bool _quit;
};

#endif
