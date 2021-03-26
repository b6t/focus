#include <string>

#include <ncurses.h>

#include "Greeting.h"

using std::string;

Greeting::Greeting(string title, string name, int height, int width,
    int verticalPos, int horizontalPos, bool outline):
  Component(title, height, width, verticalPos, horizontalPos, outline) {
    _name = name;
    _width = width;
  };

void Greeting::draw() {
  WINDOW *compWin = getWin();
  updateTime();

  string message = "Good " + getTimeOfDay() + ", " + _name + "!";
  mvwprintw(compWin, 1, (_width - message.length()) * .5, message.c_str());

  wrefresh(compWin);
}
