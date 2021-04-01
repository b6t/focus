# Author: RWP

CC=/usr/bin/gcc 
CXX=/usr/bin/g++
components = $(wildcard components/*.cpp) 

classes = $(wildcard classes/*.cpp)

obj = main.cpp $(components:.cpp=.o) $(classes:.cpp=.o)

LDFLAGS = -lncurses

focus: $(obj)
	$(CXX) -std=c++0x -o $@ $^ $(LDFLAGS) 
	
clean :
	find . -type f -name '*.o' -exec rm {} +
	rm focus
	

