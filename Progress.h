// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Progress.h

#ifndef PROGRESS_H
#define PROGRESS_H

#include <ncurses.h>

#include "Numbers.h"
#include "Time.h"

// Class 
class Progress: public Time, public Numbers {
  public:
    Progress();
    void draw(WINDOW *win);

  private:

    string getAscii(string type, int value, int line);
    time_t endUnixTime;
    time_t startUnixTime;
};

#endif
