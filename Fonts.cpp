// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Fonts.cpp

#include <string>

#include "Fonts.h"

using std::string;

Fonts::Fonts () {}

// Function roundFont
// A 2d array representation of a 0-9 in ascii art style font
// For example see: https://gist.github.com/b6t/f47ae240f98b3cdc4da56b00963a61c1
string Fonts::roundFont(int value, int line) {
  string n[ 10 ][ 5 ] = {
    { " xxxx ", "xx  xx", "xx  xx", "xx  xx", " xxxx " },
    { "xxxx  ", "  xx  ", "  xx  ", "  xx  ", "xxxxxx" },
    { " xxxx ", "xx  xx", "   xx ", "  xx  ", "xxxxxx" },
    { " xxxx ", "xx  xx", "   xxx", "xx  xx", " xxxx " },
    { "xx  xx", "xx  xx", "xxxxxx", "    xx", "    xx" },
    { "xxxxxx", "xx    ", "xxxxx ", "    xx", "xxxxx " },
    { " xxxx ", "xx    ", "xxxxx ", "xx  xx", " xxxx " },
    { "xxxxxx", "   xx ", "  xx  ", " xx   ", "xx    " },
    { " xxxx ", "xx  xx", " xxxx ", "xx  xx", " xxxx " },
    { " xxxx ", "xx  xx", " xxxxx", "    xx", " xxxx " }
  };

  return n[ value ][ line ];
}

