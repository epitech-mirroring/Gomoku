import arcade
import sys

SCREEN_WIDTH = 1920
SCREEN_HEIGHT = 1000

def separate_four_cells(packed_byte):
    c1 = (packed_byte >> 6) & 0b11
    c2 = (packed_byte >> 4) & 0b11
    c3 = (packed_byte >> 2) & 0b11
    c4 = packed_byte & 0b11
    
    return c1, c2, c3, c4

def analyse_content(file_content, number_of_lines):
    pos_x = []
    pos_y = []
    coor_x = []
    colors = []
    cells = []
    
    for (i) in range(file_content.__len__()):
        cells = cells + list(separate_four_cells(ord(file_content[i])))
    for pos in range(cells.__len__()):
        if (cells[pos] == 1):
            pos_x.append(pos % number_of_lines)
            pos_y.append(pos // number_of_lines)
            colors.append(arcade.color.WHITE)
            coor_x.append(0)
        if (cells[pos] == 2):
            pos_x.append(pos % number_of_lines)
            pos_y.append(pos // number_of_lines)
            colors.append(arcade.color.BLACK)
            coor_x.append(0)
    draw(number_of_lines, pos_x, pos_y, coor_x, colors)
    
    

def draw(number_of_lines, pos_x, pos_y, coor_x, colors):
    radius = SCREEN_HEIGHT - 10
    x = SCREEN_WIDTH / 2
    y = SCREEN_HEIGHT / 2

    arcade.open_window(SCREEN_WIDTH, SCREEN_HEIGHT, "Drawing Example")
    arcade.set_background_color(arcade.color.WHITE)
    arcade.start_render()
    arcade.draw_rectangle_filled(x, y, radius, radius, (205, 145, 90))
    line_spacing = radius / (number_of_lines + 1)

    for i in range(number_of_lines):
        start_x = x - (radius / 2) + (i + 1) * line_spacing
        start_y = y - (radius / 2) + line_spacing
        end_x = start_x
        end_y = y + (radius / 2) - line_spacing
        arcade.draw_line(start_x, start_y, end_x, end_y, arcade.color.BLACK, 2)

    for i in range(number_of_lines):
        start_y = y - (radius / 2) + (i + 1) * line_spacing
        start_x = x - (radius / 2) + line_spacing
        end_y = start_y
        end_x = x + (radius / 2) - line_spacing
        arcade.draw_line(start_x, start_y, end_x, end_y, arcade.color.BLACK, 2)
    for i in range(number_of_lines):
        if (i == pos_x):
            coor_x = x - (radius / 2) + (i + 1) * line_spacing
            break
    for num in range(pos_x.__len__()):
        for i in range(number_of_lines):
            if (i == pos_x[num]):
                coor_x[num] = x - (radius / 2) + (i + 1) * line_spacing
                break
        for i in range(number_of_lines):
            if (i == pos_y[num]):
                arcade.draw_circle_filled(coor_x[num], y - (radius / 2) + (i + 1) * line_spacing, (line_spacing / 2), colors[num])
                break
            
    arcade.finish_render()
    arcade.run()

def main():
    number_of_lines = 20
    file_name = ""
    if (sys.argv.__len__() == 3):
        number_of_lines = sys.argv[1]
        file_name = sys.argv[2]
    elif (sys.argv.__len__() == 2):
        file_name = sys.argv[1]
    file_content = open(file_name, "r")
    analyse_content(file_content.read(), int(number_of_lines))
    pass

if __name__ == "__main__":
    main()