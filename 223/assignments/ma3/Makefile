# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Target Executable
TARGET = priority_queue

# Source files
SRCS = main.cpp PrinterJob.cpp ListPriorityQueue.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
