// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Clock.cpp

#include <iostream>
#include <ncurses.h>

#include "Component.h"
#include "Clock.h"

using namespace std;

Clock::Clock(int height, int width, int verticalPos, int horizontalPos, bool outline) : Component(height, width, verticalPos, horizontalPos, outline) {};

void Clock::draw() {
  WINDOW *compWin = getWin();
  update();
  const int start = 2;
  int position = start;

  for (int i = 0; i <= 7; i++) {
    if (i == 2 || i == 5) {
      mvwprintw(compWin, 1, position , "    ");
      mvwprintw(compWin, 2, position , " [] ");
      mvwprintw(compWin, 3, position , "    ");
      mvwprintw(compWin, 4, position , " [] ");
      mvwprintw(compWin, 5, position , "    ");

      position = position + 5;
    } else {
      int digit = i + 1;

      if (i > 2 && i < 5) {
       digit-=1;
      } else if (i >=5) {
        digit-=2;
      }

      mvwprintw(compWin, 0, 1, "Current Time");
      mvwprintw(compWin, 1, position , getAscii("number", getPositionValue(digit), 1).c_str());
      mvwprintw(compWin, 2, position , getAscii("number", getPositionValue(digit), 2).c_str());
      mvwprintw(compWin, 3, position , getAscii("number", getPositionValue(digit), 3).c_str());
      mvwprintw(compWin, 4, position , getAscii("number", getPositionValue(digit), 4).c_str());
      mvwprintw(compWin, 5, position , getAscii("number", getPositionValue(digit), 5).c_str());

      position = position + 7;
    }
  }

  wrefresh(compWin);
}

string Clock::getAscii(string type, int value, int line) {
  if (type == "number") {
    return getAsciiNumber(value, line);
  } else {
    return getAsciiNumber(0, 0);
  }
}

int Clock::getPositionValue(int position) {
  if (position == 1) {

    return positionOne;
  } else if (position == 2) {

    return positionTwo;
  } else if (position == 3) {

    return positionThree;
  } else if (position == 4) {

    return positionFour;
  } else if (position == 5) {

    return positionFive;
  } else if (position == 6) {

    return positionSix;
  } else {

    return 0;
  }
}

void Clock::update() {
  updateTime();
  positionOne = getHours()/ 10 %10;
  positionTwo = getHours() %10;
  positionThree = getMinutes()/ 10 %10;
  positionFour = getMinutes() %10;
  positionFive = getSeconds() / 10 %10;
  positionSix = getSeconds() %10;
} 
