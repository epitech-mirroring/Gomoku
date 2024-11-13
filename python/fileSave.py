import sys

def save_board(lines):
    line = ""
    four_cells = [0, 0, 0, 0]
    i = 0
    while (i < lines.__len__()):
        for (j) in range(4):
            if (i < lines.__len__()):
                four_cells[j] = lines[i]
            i += 1
        line += chr(pack_four_cells(four_cells[0], four_cells[1], four_cells[2], four_cells[3]))
        four_cells = [0, 0, 0, 0]
    line += "\n"
    with open("file.txt", "w") as file:
        file.write(line)
        
def pack_four_cells(c1, c2, c3, c4):
    return (c1 << 6) | (c2 << 4) | (c3 << 2) | c4
