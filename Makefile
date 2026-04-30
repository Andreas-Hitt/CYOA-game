# Author: Andreas, Carlos, & Esteban
# Description: Unified Makefile for Castle Escape

CXX = g++
CXXFLAGS = -std=c++11 -Wall

# The executable name
TARGET = adventure

# ALL source files must be listed here to be compiled
SOURCES = main.cpp \
          LinkedList.cpp \
          Room.cpp \
          Player.cpp \
          Inventory.cpp \
          RandomEvent.cpp \
          Shop.cpp \
          Combat.cpp \
          SaveSystem.cpp \
          Item.cpp \
          Enemy.cpp

# This automatically creates a list of .o files from the .cpp files
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule: compile the game
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule for individual object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Convenience rule to compile and run in one go
run: $(TARGET)
	./$(TARGET)

# Clean rule to delete compiled files (run 'make clean' if you get weird errors)
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean