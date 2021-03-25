// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Clock.cpp

#include <string>

#include <ncurses.h>

#include "Clock.h"

using std::string;

// Constructor Clock
// A constructor that instantiates a clock object then passes the input on
// to the inherited component class
Clock::Clock(
    string title, int height, int width, int verticalPos, int horizontalPos,
    bool outline):
  Component(title, height, width, verticalPos, horizontalPos, outline) {};

// Function draw
// A virtual function from the Components class that is used to draw the 
// window and its contents to the users terminal
void Clock::draw() {
  WINDOW *compWin = getWin();
  update();

  string font = "rounded";
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
      } else if (i >= 5) {
        digit-=2;
      }
      
      int value = getPositionValue(digit);

      for (int i = 0; i < 5; i++) {
        mvwprintw(compWin, (i + 1), position , format(font, value, i, "")
            .c_str());
      }

      position = position + 7;
    }
  }

  wrefresh(compWin);
}

// Function getPostionValue
// A function that retrieves the value of the digit of a digital clock.
// For example, if the time is 1650 an input of 1 returns 1, 2 returns 6,
// 3 returns 5 and so on
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

// Function update
// A function that uses the updateTime function inherited from the 
// Time class to update the stored time data members. Then parses
// the time into its position
void Clock::update() {
  updateTime();
  positionOne = getHours()/ 10 %10;
  positionTwo = getHours() %10;
  positionThree = getMinutes()/ 10 %10;
  positionFour = getMinutes() %10;
  positionFive = getSeconds() / 10 %10;
  positionSix = getSeconds() %10;
} 
