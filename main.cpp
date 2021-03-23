// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: main.cpp

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>

#include "Clock.h"
#include "Progress.h"

using namespace std;


int main() {
  initscr();
  noecho();
  curs_set(0); // so cursor doesnt show

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  int width = 55;
  int start = xMax * .25;
  WINDOW *clockWin = newwin(7, width, 2, start);
  WINDOW *progressWin = newwin(7, 30, 2, width + start + 5);

  Clock Clock;
  Progress Progress;

  refresh();
  box(clockWin, 0, 0);
  box(progressWin, 0, 0);

  while (true) {
    Clock.update();
    Clock.draw(clockWin);
    Progress.draw(progressWin);

    // sleep
    std::chrono::milliseconds timespan(1000);
    std::this_thread::sleep_for(timespan);
  }

  endwin();
}
