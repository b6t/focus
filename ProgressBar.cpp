// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: ProgressBar.cpp

#include <iostream>
#include <ncurses.h>

#include "ProgressBar.h"

using namespace std;

ProgressBar::ProgressBar(string title, int height, int width, int verticalPos, int horizontalPos, bool outline) : Progress(title, height, width, verticalPos, horizontalPos, outline) {
  _height = height;
  _width = width;
};

void ProgressBar::draw() {
  WINDOW *compWin = getWin();
  updateProgress();

  float fill = ((float)(_height - 2) * (float)(_width - 2)) * getProgress();
  int fillRounded = round(fill);

  int level = _height - 2;
  int position = 1;

  //mvwprintw(compWin, level, position, "||||||");

  for (int i = 1; i <= fillRounded; i++) {
    mvwprintw(compWin, level, position, "|");

    if (position == _width - 2) {
      position = 1;
      level--;
    } else {
      position++;
    }
  }

  wrefresh(compWin);
}
