USE: you can launch the display with the command:

```commandline
 python3 ./python/visualizer.py [filepath] [number_of_lines]
```

filepath needs to be a valid file, with the board on unique line

number_of_lines is optional, and if not specified, the default value is 20.

When the window is opened, press ENTER to save the board into a "file.txt" file.

You can click on any position where a stone can be placed to place a white one.

Click on a white one to turn it black, then click again to make it disappear.

If you want, this command:

```commandline
python3 ./python/fileGeneratorRandom.py [number_of_lines]
```

allows you to generate a random "file.txt" compatible with the visualizer.
Once again, "number_of_lines" has a default value of 20.