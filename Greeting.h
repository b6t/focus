// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Greeting.h
#ifndef GREETING_H
#define GREETING_H

#include <iostream>

#include <ncurses.h>

#include "Component.h"

using namespace std;

// Class 
class Greeting: public Component {
  public:
    Greeting(string title, string name, int height, int width, int verticalPos, int horizontalPos, bool outline);
    void draw();

  private:
    string _name;
    int _width;
};

#endif
