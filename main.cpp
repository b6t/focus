// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: main.cpp

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "Clock.h"
#include "Greeting.h"
#include "Progress.h"
#include "ProgressBar.h"
#include "Quit.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

// Function: main
// There are 3 primary section of main: 1) Window creation,
// 2) component loading, 3) clock refreshing
int main() {
  // Section 1: ncurses initialization
  // Initializes the ncurses screen
  initscr();
  // Blocks input from showing on screen
  noecho();
  // Sets the cursor to be hidden
  curs_set(0);
  // Sets the input timeout to 0ms disallowing the the input listener from
  // blocking the clock loop
  timeout(0);

  // Components vector where components will be pushed into
  vector<Component*> components;

  // An ncurses function that gets the current terminal size. This is used to
  // find the middle of the terminal
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  // Inputs for window component sizes and location. Based on a starting
  // position, additional components can be spaced appropriately
  int loop = true;
  int width = 55;
  int height = 7;
  int start = xMax * .25;
  int verticalPosition = 2;
  int componentPadding = 3;
  // End window creation setup

  // Component loading
  // Input for progress and progress bar classes.
  // unit: hours
  int progressPeriodStart = 9;
  int progressPeriodEnd = 18;

  // Input for greeting component
  string greetingName = "Corey";

  // Invoking the components
  Clock Clock("Current Local Time", height, width, verticalPosition, start, true);
  Greeting Greeting("", greetingName, 3, width + 35, verticalPosition + 7, start, false);
  Progress Progress("Today's Progress", progressPeriodStart, progressPeriodEnd, height, 30, verticalPosition, width + start + componentPadding, true);
  ProgressBar ProgressBar("", progressPeriodStart, progressPeriodEnd, height, 8, verticalPosition, width + start + componentPadding + 29, true);
  Quit Quit("", 3, width + 35, verticalPosition + height + componentPadding, start, false);

  // Pushing the components to the vector
  components.push_back(&Clock);
  components.push_back(&Greeting);
  components.push_back(&Progress);
  components.push_back(&ProgressBar);
  components.push_back(&Quit);
  // End component loading section

  // Clock tick section
  // Here the component vector is drawn to its specified window using the
  // virtual draw method
  while (loop) {
    for (Component* c: components) {
      c->draw();
    }

    // Checking for Quits private data member to signal exit
    if (Quit.getQuit()) {
      loop = false;
    } else {
      // A sleep function that waits 1 second before iterating again
      // That lower the value the faster the iteration
      std::chrono::milliseconds timespan(1000);
      std::this_thread::sleep_for(timespan);
    }
  }

  // Closes the ncurses main window
  endwin();

  cout << "Thanks for focusing! Good Bye!" << endl;
}
