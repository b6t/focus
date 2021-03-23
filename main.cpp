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

Progress Progress;

int main() {
  initscr();
  noecho();
  curs_set(0); // so cursor doesnt show

  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(7, 55, 2, xMax/3);

  Clock Clock;

  refresh();
  box(win, 0, 0);

  while (true) {
    Clock.update();
    Clock.draw(win);
    wrefresh(win);

    // cout << Clock.getUnixTime() << endl;

    // Clock.print();

    //Progress.print();

//    float ct = ((Time.getHours() * 100) + Time.getMinutes());
//    float st = 1900;
//    float et = 2000;
////1-((1945-1930)/(1945-1800))
//    cout << ct << " " << (((et - ct) /(et-st))) << "%" << endl;

    // sleep
    std::chrono::milliseconds timespan(1000);
    std::this_thread::sleep_for(timespan);

    //clear();
  }

  endwin();
}
