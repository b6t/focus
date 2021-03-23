// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Clock.cpp

#include <iostream>
#include <ncurses.h>

#include "Clock.h"

using namespace std;

Clock::Clock() {
  update();
};

void Clock::draw(WINDOW *win) {
  const int start = 2;
  int position = start;

  for (int i = 0; i <= 7; i++) {
    if (i == 2 || i == 5) {
      mvwprintw(win, 1, position , "    ");
      mvwprintw(win, 2, position , " [] ");
      mvwprintw(win, 3, position , "    ");
      mvwprintw(win, 4, position , " [] ");
      mvwprintw(win, 5, position , "    ");

      position = position + 5;
    } else {
      int digit = i + 1;

      if (i > 2 && i < 5) {
        digit-=1;
      } else if (i >=5) {
        digit-=2;
      }
      mvwprintw(win, 1, position , getAscii("number", getPositionValue(digit), 1).c_str());
      mvwprintw(win, 2, position , getAscii("number", getPositionValue(digit), 2).c_str());
      mvwprintw(win, 3, position , getAscii("number", getPositionValue(digit), 3).c_str());
      mvwprintw(win, 4, position , getAscii("number", getPositionValue(digit), 4).c_str());
      mvwprintw(win, 5, position , getAscii("number", getPositionValue(digit), 5).c_str());

      position = position + 7;
    }
  }

  wrefresh(win);
  //wgetch(win);

}

void Clock::print() {
  cout << getAscii("number", positionOne, 1) << "  " << getAscii("number", positionTwo, 1) << "    " << getAscii("number", positionThree, 1) << "  " << getAscii("number", positionFour, 1) << "    " << getAscii("number", positionFive, 1) << "  " << getAscii("number", positionSix, 1)<< "\n";
  cout << getAscii("number", positionOne, 2) << "  " << getAscii("number", positionTwo, 2) << " [] " << getAscii("number", positionThree, 2) << "  " << getAscii("number", positionFour, 2) << " [] " << getAscii("number", positionFive, 2) << "  " << getAscii("number", positionSix, 2) <<"\n";
  cout << getAscii("number", positionOne, 3) << "  " << getAscii("number", positionTwo, 3) << "    " << getAscii("number", positionThree, 3) << "  " << getAscii("number", positionFour, 3) << "    " << getAscii("number", positionFive, 3) << "  " << getAscii("number", positionSix, 3) <<"\n";
  cout << getAscii("number", positionOne, 4) << "  " << getAscii("number", positionTwo, 4) << " [] " << getAscii("number", positionThree, 4) << "  " << getAscii("number", positionFour, 4) << " [] " << getAscii("number", positionFive, 4) << "  " << getAscii("number", positionSix, 4) <<"\n";
  cout << getAscii("number", positionOne, 5) << "  " << getAscii("number", positionTwo, 5) << "    " << getAscii("number", positionThree, 5) << "  " << getAscii("number", positionFour, 5) << "    " << getAscii("number", positionFive, 5) << "  " << getAscii("number", positionSix, 5) <<"\n";
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
