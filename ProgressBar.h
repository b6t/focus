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

// Class ProgressBar inherits from Class Progress
class ProgressBar: public Progress {
  public:
    // Constructor
    // inputs:
    // title - title of the window
    // periodStart - hour of day that the progress window begins
    // periodEnd - hour of day that the progress window ends
    // height - row height of the window
    // width - column width of the window
    // verticalPos - vertical position of the component window withing the
    // main window
    // horizontalPos - horizontal position of the component window withing the
    // main window
    // outline - a boolean indicating if the component window should be outlined
    ProgressBar(string title, int periodStart, int periodEnd, int height,
        int width, int verticalPos, int horizontalPos, bool outline);

    // Virtual from Component class
    // A function responsible for displaying the component on the screen
    void draw();

  private:
    int _height;
    int _width;
};

#endif
