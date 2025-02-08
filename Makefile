CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic

TARGET = wordscanner

SOURCES = wordscanner.cpp

HEADERS = wordscanner.h 

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f  $(TARGET) $(OBJECTS)

run: $(TARGET)
	./$(TARGET) < wordscanner.refin



.PHONY:
