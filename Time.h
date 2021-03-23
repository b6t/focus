// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Time.h

#ifndef TIME_H
#define TIME_H

// Class 
class Time {
  public:
    Time();
    virtual void print() = 0;
    void updateTime();
    int getHours();
    int getMinutes();
    int getSeconds();
    int getUnixTime();

  private:
    int hours;
    int minutes;
    int seconds;
    int unixTime;
};

#endif
