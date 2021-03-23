// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Numbers.cpp

#include <iostream>

#include "Numbers.h"

using namespace std;

Numbers::Numbers () {}

string Numbers::lineDefault () {
  return "xxxxxx";
}

string Numbers::asciiZero(int line) {
  if (line == 1) {
    return " 0000 ";
  } else if (line == 2 || line == 3 || line == 4) {
    return "00  00";
  } else if (line == 5) {
    return " 0000 ";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiOne (int line) {
  if (line == 1) {
    return "1111  ";
  } else if (line == 2 || line == 3 || line == 4) {
    return "  11  ";
  } else if (line == 5) {
    return "111111";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiTwo (int line) {
  if (line == 1) {
    return " 2222 ";
  } else if (line == 2) {
    return "22  22";
  } else if (line == 3) {
    return "   22 ";
  } else if (line == 4) {
    return "  22  ";
  } else if (line == 5) {
    return "222222";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiThree(int line) {
  if (line == 1 || line == 5) {
    return " 3333 ";
  } else if (line == 2 || line == 4) {
    return "33  33";
  } else if (line == 3) {
    return "   333";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiFour(int line) {
  if (line == 1 || line == 2) {
    return "44  44";
  } else if (line == 3) {
    return "444444";
  } else if (line == 4 || line == 5) {
    return "    44";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiFive(int line) {
  if (line == 1) {
    return "555555";
  } else if (line == 2) {
    return "55    ";
  } else if (line == 3 || line == 5) {
    return "55555 ";
  } else if (line == 4) {
    return "    55";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiSix(int line) {
  if (line == 1 || line == 5) {
    return " 6666 ";
  } else if (line == 2) {
    return "66    ";
  } else if (line == 3) {
    return "66666 ";
  } else if (line == 4) {
    return "66  66";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiSeven(int line) {
  if (line == 1) {
    return "777777";
  } else if (line == 2) {
    return "   77 ";
  } else if (line == 3) {
    return "  77  ";
  } else if (line == 4) {
    return " 77   ";
  } else if (line == 5) {
    return "77    ";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiEight(int line) {
  if (line == 1 || line == 3 || line == 5) {
    return " 8888 ";
  } else if (line == 2 || line == 4) {
    return "88  88";
  } else { 
    return lineDefault();
  }
}

string Numbers::asciiNine(int line) {
  if (line == 1 || line == 5) {
    return " 9999 ";
  } else if (line == 2) {
    return "99  99";
  } else if (line == 3) {
    return " 99999";
  } else if (line == 4) {
    return "    99";
  } else { 
    return lineDefault();
  }
}

string Numbers::getAsciiNumber(int value, int line) {
  if (value == 0) {
    return asciiZero(line);
  } else if (value == 1) {
    return asciiOne(line);
   } else if (value == 2) {
    return asciiTwo(line);
  } else if (value == 3) { 
    return asciiThree(line);
  } else if (value == 4) {
    return asciiFour(line);
  } else if (value == 5) {
    return asciiFive(line);
  } else if (value == 6) {
    return asciiSix(line);
  } else if (value == 7) {
    return asciiSeven(line);
  } else if (value == 8) {
    return asciiEight(line);
  } else if (value == 9) {
    return asciiNine(line);
   } else {
    return asciiZero(0);
  }
}

