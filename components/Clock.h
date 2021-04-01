#ifndef CLOCK_H
#define CLOCK_H

#include <string>

#include <ncurses.h>

#include "../classes/Component.h"

using std::string;

// Class Clock inherits from Class Component
class Clock: public Component {
  public:
    // Constructor
    // inputs:
    // title - title of the window
    // height - row height of the window
    // width - column width of the window
    // verticalPos - vertical position of the component window withing the
    // main window
    // horizontalPos - horizontal position of the component window withing the
    // main window
    // outline - a boolean indicating if the component window should be outlined
    Clock(string title, int height, int width, int verticalPos,
        int horizontalPos, bool outline);

    // Virtual from Component class
    // A function responsible for displaying the component on the screen
    void draw();

  private:
    int positionOne;
    int positionTwo;
    int positionThree;
    int positionFour;
    int positionFive;
    int positionSix;
    string _title;

    // Function getPostionValue
    // Gets the value of the digit in a time stamp
    int getPositionValue(int position);

    // Function update
    // Updates the time from the Time class and updates the above
    // positional private data members
    void update();
};

#endif
