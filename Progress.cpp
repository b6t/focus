// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Progress.cpp

#include <iostream>

#include "Progress.h"

using namespace std;

Progress::Progress() {
  updateTime();

  tm start;
  tm end;

  start.tm_sec = 0;  
  start.tm_min = 0;  
  start.tm_hour = 0;  
  start.tm_mday = 21;  
  start.tm_mon = 2;  
  start.tm_year = 2021 - 1900;  

  startUnixTime = mktime(&start);

  end.tm_sec = 59;  
  end.tm_min = 59;  
  end.tm_hour = 23;  
  end.tm_mday = 21;  
  end.tm_mon = 2;  
  end.tm_year = 2021 - 1900;  

  endUnixTime = mktime(&end);

};

void Progress::print() {
  updateTime();

  float progress = (float)(getUnixTime() - startUnixTime) / (float)(endUnixTime - startUnixTime);

  cout << "Progress: " << progress * 100 << "%" << endl;
}
