// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Component.cpp

#include <iostream>
#include <ncurses.h>

#include "Component.h"

using namespace std;

Component::Component(string title, int height, int width, int verticalPos, int horizontalPos, bool outline) {
  win = newwin(height, width, verticalPos, horizontalPos);
  refresh();
  if (outline) {
    box(win, 0, 0);
  }

  if (title != "") {
    mvwprintw(win, 0, 1, title.c_str());
  }

  wrefresh(win);
};

WINDOW *Component::getWin() {

  return win;
};
