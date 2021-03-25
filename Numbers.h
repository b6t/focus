// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/21/21
// File: Numbers.h

#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>

#include "Fonts.h"

using namespace std;

// Class 
class Numbers: public Fonts {
  public:
    Numbers();
    string format(string type, int value, int line, string replacement);
};

#endif
