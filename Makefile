#compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

#output executable name
TARGET = manual_exec

#source files
SRCS = main.cpp

#default build rule
all: $(TARGET)

#to build the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

#clean rule to remove build artifacts
clean:
	rm -f $(TARGET)