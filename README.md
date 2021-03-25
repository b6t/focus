# Focus

## Introduction

Focus is a terminal based time management tool that tracks your days progress.

## To run

First, to compile run: `g++ -std=c++11 *.cpp -o main -lncurses`

Then to execute: `./main`

Once running to quit hit the letter 'q' or standard ctl+c.

## What does it do
There are four primary components to Focus:

1. Current Local Time: This component creates the current time using 'ascii art' for larger print.

2. Today's Progress: This component shows the percentage of time completed within a specified window of time. For example, setting the start time at 0900 and end time at 1800 provides the user with the percentage if time that has passed in the window.

3. Progress Bar: This component is a child of the Progress component. Using the same percentage complete value from the Progress component, the progress bar is a visual representation of the progress window. As the day progresses the bar will be filled with characters.

4. Greeting: The greeting component greets the user with the time of day and their name. This uses the timeOfDay data member from the Time class to determine morning, noon, or evening.

## Contributing

Contributing is fairly straight forward. As shown in the diagram below there are two base classes the are inherited by the Component class. The Component class is responsible for creating the ncurses window based on the provided constructor data. The Component class implements a virtual function called draw(). The draw function is responsible for displaying the component on the users terminal. The Component class should be inherited by a component rather than directly accessing it from main.d

## Credit
- [Momentum](https://momentumdash.com)
- [ncurses](https://invisible-mirror.net/archives/ncurses/)

Compiled using g++ (Apple clang version 12.0.0 (clang-1200.0.32.28))
