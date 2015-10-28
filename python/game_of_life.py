#!/usr/bin/python
#game of life

#GLOBAL DEFINITIONS
rows = 40
cols = 40
grid = []

#create the grid
for i in range(0, rows):
    grid.append([])
    for j in range(0, cols):
        grid[i].extend(". ");

#first make a grid
def print_grid():
    for i in range(0, rows):
        print grid[i]

