import arcade
import sys
from fileSave import save_board

SCREEN_WIDTH = 1920
SCREEN_HEIGHT = 1000

class MyGame(arcade.Window):
    """ Main application class. """

    def __init__(self, width, height):
        super().__init__(width, height)
        self.cells = []

    def setup(self, cells):
        self.cells = cells

    def on_draw(self):
        arcade.start_render()
        self.draw_board()

    def update(self, delta_time):
        pass
    
    def on_key_release(self, symbol, modifiers):
        if symbol == arcade.key.ESCAPE:
            arcade.close_window()
        if symbol == arcade.key.ENTER:
            print("Cells: ", self.cells)
            save_board(self.cells)

    def draw_board(self):
        radius = SCREEN_HEIGHT - 10
        x = SCREEN_WIDTH / 2
        y = SCREEN_HEIGHT / 2
        arcade.set_background_color(arcade.color.WHITE)
        arcade.draw_rectangle_filled(x, y, radius, radius, (205, 145, 90))
        line_spacing = radius / (number_of_lines + 1)

        for i in range(number_of_lines):
            start_x = x - (radius / 2) + (i + 1) * line_spacing
            start_y = y - (radius / 2) + line_spacing
            end_x = start_x
            end_y = y + (radius / 2) - line_spacing
            arcade.draw_line(start_x, start_y, end_x, end_y, arcade.color.BLACK, 2)

            start_y = y - (radius / 2) + (i + 1) * line_spacing
            start_x = x - (radius / 2) + line_spacing
            end_y = start_y
            end_x = x + (radius / 2) - line_spacing
            arcade.draw_line(start_x, start_y, end_x, end_y, arcade.color.BLACK, 2)

        for pos in range(len(self.cells)):
            color = arcade.color.WHITE if self.cells[pos] == 1 else arcade.color.BLACK
            if self.cells[pos] in (1, 2):
                cell_x = x - (radius / 2) + (pos % number_of_lines + 1) * line_spacing
                cell_y = y - (radius / 2) + (pos // number_of_lines + 1) * line_spacing
                arcade.draw_circle_filled(cell_x, cell_y, (line_spacing / 2), color)

def separate_four_cells(packed_byte):
    return ((packed_byte >> 6) & 0b11, (packed_byte >> 4) & 0b11, (packed_byte >> 2) & 0b11, packed_byte & 0b11)

def analyse_content(file_content, number_of_lines):
    cells = []
    for char in file_content:
        cells.extend(separate_four_cells(ord(char)))
    
    return cells[:number_of_lines * number_of_lines]  # Limit to the board size

def main():
    global number_of_lines  # Keep it global for simplicity in drawing
    number_of_lines = 20
    file_name = ""

    if len(sys.argv) == 3:
        number_of_lines = int(sys.argv[1])  # Convert to int
        file_name = sys.argv[2]
    elif len(sys.argv) == 2:
        file_name = sys.argv[1]

    with open(file_name, "r") as file:
        file_content = file.read()
        cells = analyse_content(file_content, number_of_lines)

    game = MyGame(SCREEN_WIDTH, SCREEN_HEIGHT)
    game.setup(cells)
    arcade.run()

if __name__ == "__main__":
    main()
