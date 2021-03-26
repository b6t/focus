// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Fonts.h

#ifndef FONTS_H
#define FONTS_H

#include <string>

using std::string;

// Class 
class Fonts {
  public:
  	// Constructor Fonts
  	// Allows for the use of different fonts by exposing a function for
  	// the font
    Fonts();

    // Function font
    // A function, given the actual number requested and the ascii art line
    // 1-5 that is to be printed, returns a 6 character string of the the 
    // digit. For example, for the number 1 and line 4 "xxxxxx" is returned.
    // For the number 1 and line 0 " xxxx " is returned.
    string roundFont(int value, int line);
};

#endif
