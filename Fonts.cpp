// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Fonts.cpp

#include <iostream>

#include "Fonts.h"

using namespace std;

Fonts::Fonts () {}

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

