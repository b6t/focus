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
#include "ProgressBar.h"
#include "Greeting.h"
#include "Quit.h"

using namespace std;

int main() {
  initscr();
  noecho();
  curs_set(0); // so cursor doesnt show
  timeout(0);

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  int loop = true;
  int width = 55;
  int height = 7;
  int start = xMax * .25;
  int verticalPosition = 2;
  int componentPadding = 3;

  int progressPeriodStart = 0;
  int progressPeriodEnd = 18;

  string greetingName = "Corey";

  Clock Clock("Current Local Time", height, width, verticalPosition, start, true);
  Greeting Greeting("", greetingName, 3, width + 35, verticalPosition + 7, start, false);
  Progress Progress("Today's Progress", progressPeriodStart, progressPeriodEnd, height, 30, verticalPosition, width + start + componentPadding, true);
  ProgressBar ProgressBar("", progressPeriodStart, progressPeriodEnd, height, 8, verticalPosition, width + start + componentPadding + 29, true);
  Quit Quit("", 3, width + 35, verticalPosition + height + componentPadding, start, false);

  while (loop) {
    Clock.draw();
    Progress.draw();
    ProgressBar.draw();
    Greeting.draw();
    Quit.draw();

    if (Quit.getQuit()) {
      loop = false;
    } else {
      // sleep
      std::chrono::milliseconds timespan(1000);
      std::this_thread::sleep_for(timespan);
    }
  }

  endwin();

  cout << "Thanks for focusing! Good Bye!" << endl;
}
