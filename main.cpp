#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

 #include "components/Clock.h"
 #include "components/Greeting.h"
 #include "components/Progress.h"
 #include "components/ProgressBar.h"
 #include "components/Quit.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


// Function prompt
// Prompt for string input
string prompt(string type) {
  string input;
  bool cont = true;

  while (cont) {
    cout << "Please enter your " << type << ": ";
    cin >> input;

    if (cin.fail()) {
      cin.clear();
      cout << "Try again...\n\n";
    } else {
      cont = false;
    }
  }

  return input;
}

// Function promt
// Overloaded fucntion that promts for ints with allowance for accepting a
// range. This is primarily suited for accepting hours.
int prompt(string type, int prior) {
  int input;
  bool cont = true;
  int bottom = (prior == -1) ? 0 : prior + 1;

  while (cont) {
    cout << "Please enter the " << type << " hour (" << bottom << " - 24): ";
    cin >> input;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (cin.fail() || input < bottom || input > 24) {
      cin.clear();
      cout << "Try again...\n\n";
    } else {
      cont = false;
    }
  }

  return input;
}

// Function: main
// There are 4 primary section of main: 1) Initial input, 2) Window creation,
// 3) component loading, 4) clock refreshing
int main() {
  // Section 1: Initial input
  cout << "Hi, welcome to Focus!\n"; 
  // Input for greeting component
  string greetingName = prompt("name");

  cout << "Select a period of time by providing a beginning and end hour\n";
  // Component loading
  // Input for progress and progress bar classes.
  // unit: hours
  int progressPeriodStart = prompt("beginning", -1);
  int progressPeriodEnd = prompt("ending", progressPeriodStart);

  // Section 2: ncurses initialization
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

  // Section 3: Invoking the components
  // Clock Clock("Current Local Time", height, width, verticalPosition, start, true);
  // Greeting Greeting("", greetingName, 3, width + 35, verticalPosition + 7, start, false);
  // Progress Progress("Today's Progress", progressPeriodStart, progressPeriodEnd, height, 30, verticalPosition, width + start + componentPadding, true);
  // ProgressBar ProgressBar("", progressPeriodStart, progressPeriodEnd, height, 8, verticalPosition, width + start + componentPadding + 29, true);
  Quit Quit("", 3, width + 35, verticalPosition + height + componentPadding, start, false);

  // Pushing the components to the vector
  // components.push_back(&Clock);
  // components.push_back(&Greeting);
  // components.push_back(&Progress);
  // components.push_back(&ProgressBar);
  components.push_back(&Quit);
  // End component loading section

  // Section 4: Clock tick
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
