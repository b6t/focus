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

using std::string;

// Class Numbers inherits from Class Fonts
class Numbers: public Fonts {
  public:
  	// Constructor Numbers
  	// Instantiates an object from which ascii art style numbers are returned
    Numbers();

    // Function format
    // Inputs:
    // type - the type or name of font ex: "rounded"
    // value - the digit requested
    // line - the line of the ascii art version
    // replacement - a string value that can be used to replace the stock "x"s
    // in the font with something else. See Fonts.cpp for an example of the
    // font template structure.
    string format(string type, int value, int line, string replacement);
};

#endif
