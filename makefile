CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
SOURCES := $(wildcard src/*.cpp)
TARGET := bin/main.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(wildcard include/*.hpp)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)