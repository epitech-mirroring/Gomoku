CXX = g++

CXXFLAGS = -I./communication/include/

SRC = main.cpp			\
	  communication/src/ACommunication.cpp	\

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