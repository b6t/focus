#include <string>
#include <ncurses.h>

#include "ProgressBar.h"

using std::string;

ProgressBar::ProgressBar(string title, int periodStart, int periodEnd,
    int height, int width, int verticalPos, int horizontalPos, bool outline):
  Progress(title, periodStart, periodEnd, height, width, verticalPos,
      horizontalPos, outline) {
    _height = height;
    _width = width;
  };

void ProgressBar::draw() {
  WINDOW *compWin = getWin();
  updateProgress();

  float fill = ((float)(_height - 2) * (float)(_width - 2)) * getProgress();
  int fillRounded = round(fill);
  int level = _height - 2;
  int position = 1;

  for (int i = 1; i <= fillRounded; i++) {
    if (level > 0) {
      mvwprintw(compWin, level, position, "|");
    }

    if (position == _width - 2) {
      position = 1;
      level--;
    } else {
      position++;
    }
  }

  wrefresh(compWin);
}
