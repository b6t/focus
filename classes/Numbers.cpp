#include <algorithm>
#include <string>

#include "Numbers.h"

using std::string;
using std::to_string;

Numbers::Numbers () {}

string Numbers::format(string type, int value, int line, string replacement) {
  string replaceStr, selection;

  selection = roundFont(value, line);

  if (replacement == "") {
    replaceStr = to_string(value);
  } else {
    replaceStr = replacement;
  }

  size_t pos;
  while ((pos = selection.find("x")) != string::npos) {
    selection.replace(pos, 1, replaceStr);
  }

  return selection;
}
