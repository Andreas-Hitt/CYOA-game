# Author: Andreas, Carlos, & Esteban
# Description: Unified Makefile for Castle Escape
# Updated to include all current project modules.

CXX = g++
CXXFLAGS = -std=c++11 -Wall

# The executable name
TARGET = adventure

# ALL source files must be listed here to be compiled
# Ensure any new .cpp files created are added to this list
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

# This automatically creates a list of .o (object) files from the .cpp files
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule: compile the game
all: $(TARGET)

# Linking: Combines object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compilation: Converts individual .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Convenience rule to compile and run in one go
run: $(TARGET)
	./$(TARGET)

# Clean rule to delete compiled files
# Use 'make clean' if you change a .h file or experience weird build errors
clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean