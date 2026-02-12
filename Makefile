CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = main
SRCS = main.cpp gamepieces/EightPuzzle.cpp Searches/UniformCostSearch.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
