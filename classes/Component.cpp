#include <ncurses.h>

#include "Component.h"

// Constuctor Component
Component::Component(string title, int height, int width, int verticalPos,
    int horizontalPos, bool outline) {
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

// Function getWin, getter
WINDOW *Component::getWin() {

  return win;
};
