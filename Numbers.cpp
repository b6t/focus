// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/21/21
// File: Numbers.cpp

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

// string n[ 10 ][ 5 ] = {
//   { " 0000 ", "00  00", "00  00", "00  00", " 0000 " },
//   { "1111  ", "  11  ", "  11  ", "  11  ", "111111" },
//   { " 2222 ", "22  22", "   22 ", "  22  ", "222222" },
//   { " 3333 ", "33  33", "   333", "33  33", " 3333 " },
//   { "44  44", "44  44", "444444", "    44", "    44" },
//   { "555555", "55    ", "55555 ", "    55", "55555 " },
//   { " 6666 ", "66    ", "66666 ", "66  66", " 6666 " },
//   { "777777", "   77 ", "  77  ", " 77   ", "77    " },
//   { " 8888 ", "88  88", " 8888 ", "88  88", " 8888 " },
//   { " 9999 ", "99  99", " 99999", "    99", " 9999 " }

