TARGET = pbrain-gomoku-ai

all: $(TARGET)

$(TARGET):
	cmake . -B build
	cmake --build build

clean:
	[ ! -d build ] || cmake --build build --target clean

fclean: clean
	rm -rf build

re: fclean all
