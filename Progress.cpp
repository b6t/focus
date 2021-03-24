// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Progress.cpp

#include <iostream>
#include <ncurses.h>

#include "Progress.h"

using namespace std;


Progress::Progress(int height, int width, int verticalPos, int horizontalPos, bool outline) : Component(height, width, verticalPos, horizontalPos, outline) {
  tm start;
  tm end;

  start.tm_sec = 0;
  start.tm_min = 0;
  start.tm_hour = 9;
  start.tm_mday = getDay();
  start.tm_mon = getMonth();
  start.tm_year = getYear();

  startUnixTime = mktime(&start);

  end.tm_sec = 0;
  end.tm_min = 0;
  end.tm_hour = 18;
  end.tm_mday = getDay();
  end.tm_mon = getMonth();
  end.tm_year = getYear();

  endUnixTime = mktime(&end);
};

void Progress::draw() {
  WINDOW *compWin = getWin();
  updateTime();
  float progress = (float)(getUnixTime() - startUnixTime) / (float)(endUnixTime - startUnixTime);
  // cout << "start " << startUnixTime << endl;
  // cout << "end " << endUnixTime << endl;
  // cout << "current " << getUnixTime() << endl;
  // cout << "get month " << getMonth() << endl;
  // cout << "get year " << getYear() << endl;
  // cout << "get day " << getDay() << endl;
  int rounded = (int)round(progress * 100);
  string progressString = to_string(rounded);
  string decimalString = to_string(progress * 100);

  // mvwprintw(win, 0, 0, decimalString.c_str());
  mvwprintw(compWin, 0, 1, "Today's Progress");
  int position = 2;
  int rise = 0;
  if (rounded / 100 %10 != 0) {
    mvwprintw(compWin, rise + 1, position, getAscii("number", rounded / 100 %10, 1).c_str());
    mvwprintw(compWin, rise + 2, position, getAscii("number", rounded / 100 %10, 2).c_str());
    mvwprintw(compWin, rise + 3, position, getAscii("number", rounded / 100 %10, 3).c_str());
    mvwprintw(compWin, rise + 4, position, getAscii("number", rounded / 100 %10, 4).c_str());
    mvwprintw(compWin, rise + 5, position, getAscii("number", rounded / 100 %10, 5).c_str());

    position += 7;
  }

  mvwprintw(compWin, rise + 1, position, getAscii("number", rounded / 10 %10, 1).c_str());
  mvwprintw(compWin, rise + 2, position, getAscii("number", rounded / 10 %10, 2).c_str());
  mvwprintw(compWin, rise + 3, position, getAscii("number", rounded / 10 %10, 3).c_str());
  mvwprintw(compWin, rise + 4, position, getAscii("number", rounded / 10 %10, 4).c_str());
  mvwprintw(compWin, rise + 5, position, getAscii("number", rounded / 10 %10, 5).c_str());

  position += 7;
  mvwprintw(compWin, rise + 1, position, getAscii("number", rounded %10, 1).c_str());
  mvwprintw(compWin, rise + 2, position, getAscii("number", rounded %10, 2).c_str());
  mvwprintw(compWin, rise + 3, position, getAscii("number", rounded %10, 3).c_str());
  mvwprintw(compWin, rise + 4, position, getAscii("number", rounded %10, 4).c_str());
  mvwprintw(compWin, rise + 5, position, getAscii("number", rounded %10, 5).c_str());

  position += 7;
  mvwprintw(compWin, rise + 2, position, "() /");
  mvwprintw(compWin, rise + 3, position, "  / ");
  mvwprintw(compWin, rise + 4, position, " /  ");
  mvwprintw(compWin, rise + 5, position, "/ ()");


  wrefresh(compWin);
}

string Progress::getAscii(string type, int value, int line) {
  if (type == "number") {
    return getAsciiNumber(value, line);
  } else {
    return getAsciiNumber(0, 0);
  }
}
