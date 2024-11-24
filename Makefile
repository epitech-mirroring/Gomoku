TARGET = pbrain-gomoku-ai

all: $(TARGET)

$(TARGET):
	cmake . -B build
	cmake --build build

clean:
	[ ! -d build ] || cmake --build build --target clean

fclean: clean
	rm -rf build
	rm -f $(TARGET)

re: fclean all
