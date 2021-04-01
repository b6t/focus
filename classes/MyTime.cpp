#include <ctime>
#include <string>

#include "MyTime.h"

using std::string;

MyTime::MyTime () {
  updateTime();
}

void MyTime::updateTime() {
  time_t unixTimeNow = time(0);
  tm *ltm = localtime(&unixTimeNow);

  unixTime = unixTimeNow;
  year = ltm->tm_year;
  month = ltm->tm_mon;
  day = ltm->tm_mday;
  hours = ltm->tm_hour;
  minutes = ltm->tm_min;
  seconds = ltm->tm_sec;

  calculateTimeOfDay();
}

void MyTime::calculateTimeOfDay() {
  if (hours >= 5 && hours < 12) {
    timeOfDay = "Morning";
  } else if (hours >= 12 && hours < 17) {
    timeOfDay = "Afternoon";
  } else if ((hours >= 17 && hours < 24) || (hours >= 0 && hours < 5)) {
    timeOfDay = "Evening";
  } else {
    timeOfDay = "Day";
  }
}

int MyTime::getYear() {

  return year;
}

int MyTime::getMonth() {

  return month;
}

int MyTime::getDay() {

  return day;
}

int MyTime::getHours() {

  return hours;
}

int MyTime::getMinutes() {

  return minutes;
}

int MyTime::getSeconds() {

  return seconds;
}

int MyTime::getUnixTime() {

  return unixTime;
}

string MyTime::getTimeOfDay() {

  return timeOfDay;
}
