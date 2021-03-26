#ifndef QUIT_H
#define QUIT_H

#include <string>

#include <ncurses.h>

#include "Component.h"

using std::string;

// Class Quit inherits from Class Component
class Quit: public Component {
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
    Quit(string title, int height, int width, int verticalPos,
        int horizontalPos, bool outline);

    // Virtual from Component class
    // A function responsible for displaying the component on the screen
    void draw();
    
    // Function getQuit
    // A getter for the _quit private data member. Function draw listens
    // for the the set quit letter, then sets _quit to true. 
    bool getQuit();

  private:
    int _width;
    bool _quit;
};

#endif
