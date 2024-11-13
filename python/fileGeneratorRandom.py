import sys
import random

def main():
    number_of_lines = 20
    line = ""
    four_cells = [0, 0, 0, 0]
    if (sys.argv.__len__() == 2):
        number_of_lines = int(sys.argv[1])
    for (i) in range(number_of_lines * number_of_lines):
        for (j) in range(4):
            four_cells[j] = random.randint(0, 2)
        line += chr(pack_four_cells(four_cells[0], four_cells[1], four_cells[2], four_cells[3]))
    line += "\n"
    with open("file.txt", "w") as file:
        file.write(line)
        
def pack_four_cells(c1, c2, c3, c4):
    return (c1 << 6) | (c2 << 4) | (c3 << 2) | c4

if __name__ == "__main__":
    main()