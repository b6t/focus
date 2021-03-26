#include <ctime>
#include <string>

#include "Time.h"

using std::string;

Time::Time () {
  updateTime();
}

void Time::updateTime() {
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

void Time::calculateTimeOfDay() {
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

int Time::getYear() {

  return year;
}

int Time::getMonth() {

  return month;
}

int Time::getDay() {

  return day;
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

string Time::getTimeOfDay() {

  return timeOfDay;
}
