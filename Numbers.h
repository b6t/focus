// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/21/21
// File: Numbers.h

#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>

using namespace std;

// Class 
class Numbers {
  public:
    Numbers();
    string getAsciiNumber(int value, int line);

  private:
    string asciiZero(int line);
    string asciiOne(int line);
    string asciiTwo(int line);
    string asciiThree(int line);
    string asciiFour(int line);
    string asciiFive(int line);
    string asciiSix(int line);
    string asciiSeven(int line);
    string asciiEight(int line);
    string asciiNine(int line);
    string lineDefault();
};

#endif
