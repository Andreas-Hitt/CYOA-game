CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = adventure
SOURCES = main.cpp LinkedList.cpp Room.cpp Player.cpp Inventory.cpp RandomEvent.cpp Shop.cpp Combat.cpp SaveSystem.cpp Item.cpp Enemy.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean