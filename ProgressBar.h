// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: ProgressBar.h

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <ncurses.h>

#include "Progress.h"

// Class 
class ProgressBar: public Progress {
  public:
    ProgressBar(string title, int height, int width, int verticalPos, int horizontalPos, bool outline);
    void draw();

  private:
    int _height;
    int _width;
};

#endif
