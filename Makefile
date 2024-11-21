
all: $(TARGET)

$(TARGET):
	cmake . -B build
	cmake --build build

clean:
	cmkae --build build --target clean

fclean: clean
	rm -rf build

re: fclean all
