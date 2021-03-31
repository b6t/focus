#ifndef PROGRESS_H
#define PROGRESS_H

#include <ncurses.h>

#include "../classes/Component.h"

// Class Progress inherits from Class Component
class Progress: public Component {
  public:
    // Constructor
    // inputs:
    // title - title of the window
    // periodStart - hour of day that the progress window begins
    // periodEnd - hour of day that the progress window ends
    // height - row height of the window
    // width - column width of the window
    // verticalPos - vertical position of the component window withing the
    // main window
    // horizontalPos - horizontal position of the component window withing the
    // main window
    // outline - a boolean indicating if the component window should be outlined
    Progress(string title, int periodStart, int periodEnd, int height,
        int width, int verticalPos, int horizontalPos, bool outline);

    // Virtual from Component class
    // A function responsible for displaying the component on the screen
    void draw();

    // Function getProgress
    // Retuns a decimal representation of the current progress made within the
    // progress timeframe
    float getProgress();

    // Function updateProgress
    // Uses the inherited updateTime function to refresh the current time the recalculates the 
    // current progress made in the progress timeframe
    void updateProgress();

  private:
    float _progress;
    time_t _startUnixTime;
    time_t _endUnixTime;
};

#endif
