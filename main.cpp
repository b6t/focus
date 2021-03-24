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
#include "Greeting.h"

using namespace std;

int main() {
  initscr();
  noecho();
  curs_set(0); // so cursor doesnt show

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  int width = 55;
  int height = 7;
  int start = xMax * .25;
  int verticalPosition = 2;
  int componentPadding = 5;

  Clock Clock(height, width, verticalPosition, start, true);
  Greeting Greeting("Corey", 3, width + 35, verticalPosition + 7, start, false);
  Progress Progress(height, 30, verticalPosition, width + start + componentPadding, true);

  while (true) {
    Clock.draw();
    Progress.draw();
    Greeting.draw();

    // sleep
    std::chrono::milliseconds timespan(1000);
    std::this_thread::sleep_for(timespan);
  }

  endwin();
}
