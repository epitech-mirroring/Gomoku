CXX = g++

CXXFLAGS = -I./src/ -std=c++17 -Wall -Wextra -Werror

SRC = main.cpp						\
	  src/Communication.cpp 		\
	  src/brains/ABrain.cpp 		\
	  src/brains/DumbBrain.cpp  	\
	  src/board/Board.cpp			\
	  src/brains/DefaultBrain.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = pbrain-gomoku-ai

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
