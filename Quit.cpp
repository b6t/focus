// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Quit.cpp

#include <iostream>
#include <ncurses.h>

#include "Quit.h"

using namespace std;

Quit::Quit(string title, int height, int width,
    int verticalPos, int horizontalPos, bool outline):
  Component(title, height, width, verticalPos, horizontalPos, outline) {
    _width = width;
    _quit = false;
  };

void Quit::draw() {
  WINDOW *compWin = getWin();
  updateTime();

  string message = "Press q to quit.";
  mvwprintw(compWin, 1, (_width - message.length()) * .5, message.c_str());

  char ans = getch();

  if (ans == 'q') {
    _quit = true;
  }

  wrefresh(compWin);
}

bool Quit::getQuit() {

  return _quit;
}
