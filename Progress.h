// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Progress.h

#ifndef PROGRESS_H
#define PROGRESS_H

#include <ncurses.h>

#include "Component.h"

// Class 
class Progress: public Component {
  public:
    Progress(string title, int height, int width, int verticalPos, int horizontalPos, bool outline);
    void draw();
    float getProgress();
    void updateProgress();

  private:
    string getAscii(string type, int value, int line);
    float _progress;
    time_t _startUnixTime;
    time_t _endUnixTime;
};

#endif
