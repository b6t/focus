// Name: Corey Beaumont
// Course: CIS 544-M401 Object Oriented Programming in C++
// Org: Syracuse University
// Task: Final Project
// Date: 3/1/21
// File: Time.cpp

#include <ctime>
#include <iostream>

#include "Time.h"

using namespace std;

Time::Time () {
  updateTime();
}

void Time::updateTime() {
  time_t unixTimeNow = time(0);
  tm *ltm = localtime(&unixTimeNow);

  unixTime = unixTimeNow;
  hours = ltm->tm_hour;
  minutes = ltm->tm_min;
  seconds = ltm->tm_sec;
}

int Time::getHours() {

  return hours;
}

int Time::getMinutes() {

  return minutes;
}

int Time::getSeconds() {

  return seconds;
}

int Time::getUnixTime() {

  return unixTime;
}
