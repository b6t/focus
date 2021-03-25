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

Progress::Progress(string title, int periodStart, int periodEnd, int height,
    int width, int verticalPos, int horizontalPos, bool outline):
  Component(title, height, width, verticalPos, horizontalPos, outline) {
    time_t rawBegin, rawEnd;
    struct tm *begin, *end;

    time(&rawBegin);
    begin = localtime(&rawBegin);

    begin->tm_sec = 0;
    begin->tm_min = 0;
    begin->tm_hour = periodStart;
    begin->tm_mday = getDay();
    begin->tm_mon = getMonth();
    begin->tm_year = getYear();

    _startUnixTime = mktime(begin);

    time(&rawEnd);
    end = localtime(&rawEnd);

    end->tm_sec = 0;
    end->tm_min = 0;
    end->tm_hour = periodEnd;
    end->tm_mday = getDay();
    end->tm_mon = getMonth();
    end->tm_year = getYear();

    _endUnixTime = mktime(end);

    updateProgress();
  };

void Progress::draw() {
  WINDOW *compWin = getWin();
  updateProgress();
 
  int rounded = (round(_progress * 100) < 0) ? 0 :round(_progress * 100);
  string progressString = to_string(rounded);
  string decimalString = to_string(_progress * 100);

  string font = "rounded";
  int position = 2;
  int rise = 0;
  if (rounded / 100 %10 != 0) {
    int hundreds = rounded / 100 %10; 

    for (int i = 0; i < 5; i++) {
      mvwprintw(compWin, rise + (i + 1), position, format(font, hundreds, i, "")
          .c_str());
    }

    position += 7;
  }

  int tens = rounded / 10 %10;

  for (int i = 0; i < 5; i++) {
    mvwprintw(compWin, rise + (i + 1), position, format(font, tens, i, "")
        .c_str());
  }

  int ones = rounded %10;
  position += 7;

  for (int i = 0; i < 5; i++) {
    mvwprintw(compWin, rise + (i + 1), position, format(font, ones, i, "")
        .c_str());
  }

  position += 7;
  mvwprintw(compWin, rise + 2, position, "() /");
  mvwprintw(compWin, rise + 3, position, "  / ");
  mvwprintw(compWin, rise + 4, position, " /  ");
  mvwprintw(compWin, rise + 5, position, "/ ()");

  wrefresh(compWin);
}

void Progress::updateProgress() {
  updateTime();
  _progress = (float)(getUnixTime() - _startUnixTime)/
    (float)(_endUnixTime - _startUnixTime);
}

float Progress::getProgress() {

  return _progress;
}
