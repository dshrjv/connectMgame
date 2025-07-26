CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

TARGET = connectM
OBJS = main.o board.o game.o ai.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)
