CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude -Iinclude/estruturas -Iinclude/entidades -Iinclude/core
SOURCES := $(wildcard src/*.cpp src/*/*.cpp)
HEADERS := $(wildcard include/*.hpp include/*/*.hpp)
TARGET := bin/main.exe

.PHONY: all run clean

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)