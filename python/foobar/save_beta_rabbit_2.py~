#!/usr/bin/python

def answer(food, grid):
    opt_max = []
    opt_min = []
    opt = []
    n = len(grid)
    for i in range(0, n):
        row = [-1] * n
        opt_max.append(row)
    for i in range(0, n):
        row = [-1] * n
        opt_min.append(row)
    for i in range(0, n):
        row = [-2] * n
        opt.append(row)

    opt_max[0][0] = 0
    opt_min[n-1][n-1] = 0
    opt[0][0] = grid[0][0]

#    print "opt_min initially"
#    print opt_min
#    print "opt_max initially"
#    print opt_max

    val =0
    #calculate opt_min
    #opt_min = minimum food that should be remaining after feeding zombin
    # in the current cell to still make it to grid[n][n]
    for i in range(n-1, -1,-1):
        for j in range(n-1, -1,-1):
            if opt_min[i][j] != -1:
                continue
            else:
                if i == n-1:
                    opt_min[i][j] = grid[i][j+1] + opt_min[i][j+1]
                elif j == n-1:
                    opt_min[i][j] = grid[i+1][j] + opt_min[i+1][j]
                else:
                    value_1 = opt_min[i+1][j] + grid[i+1][j]
                    value_2 = opt_min[i][j+1] + grid[i][j+1]
                    if value_1 < value_2:
                        opt_min[i][j] = value_1
                    else:
                        opt_min[i][j] = value_2
    #calculate opt_max
    for i in range(0, n):
        for j in range(0, n):
            if opt_max[i][j] != -1:
                continue
            else:
                if i == 0:
                    opt_max[i][j] = grid[i][j] + opt_max[i][j-1]
                elif j == 0:
                    opt_max[i][j] = grid[i][j] + opt_max[i-1][j]
                else:
                    value_1 = opt_max[i-1][j]
                    value_2 = opt_max[i][j-1]
                    if value_1 > value_2:
                        opt_max[i][j] = value_1 + grid[i][j]
                    else:
                        opt_max[i][j] = value_2 + grid[i][j]
    #calculate opt
    #opt = max food that can be used up and still make it to grid[n][n]
    for i in range(0, n):
        for j in range(0, n):
            if i ==0 and j ==0:
                if opt_min[i][j] > food:
                    opt[i][j] = -1
                else:
                    opt[i][j] = 0
            elif i == 0:
                   if opt[i][j-1] == -1:
                       opt[i][j] = -1
                   else:
                       value_1 = grid[i][j] + opt[i][j-1] + opt_min[i][j]
                       if value_1 <= food:
                           opt[i][j] = grid[i][j] + opt[i][j-1]
                       else:
                           opt[i][j] = -1
            elif j == 0:
                if opt[i-1][j] == -1:
                    opt[i][j] = -1
                else:
                    value_1 = grid[i][j] + opt[i-1][j] + opt_min[i][j]
                    if value_1 <= food:
                        opt[i][j] = grid[i][j] + opt[i-1][j]
                    else:
                        opt[i][j] = -1
            else:
                if opt[i][j-1] == -1 and opt[i-1][j] == -1:
                    opt[i][j] = -1
                elif opt[i][j-1] == -1:
                    value_1 = grid[i][j] + opt[i-1][j] + opt_min[i][j]
                    if value_1 <= food:
                        opt[i][j] = grid[i][j] + opt[i-1][j]
                    else:
                        opt[i][j] = -1
                elif opt[i-1][j] == -1:
                    value_1 = grid[i][j] + opt[i][j-1] + opt_min[i][j]
                    if value_1 <= food:
                        opt[i][j] = grid[i][j] + opt[i][j-1]
                    else:
                        opt[i][j] = -1
                else:
                    value_1 = grid[i][j] + opt[i][j-1] + opt_min[i][j]
                    value_2 = grid[i][j] + opt[i-1][j] + opt_min[i][j]
                    if value_1 > value_2 and value_1 <= food:
                        opt[i][j] = grid[i][j] + opt[i][j-1]
                    elif value_2 >= value_1 and value_2 <= food:
                        opt[i][j] = grid[i][j] + opt[i-1][j]
                    else:
                        opt[i][j] = -1
                    
    '''    print "opt_min"
    print opt_min
    print "opt_max"
    print opt_max
    print "opt"
    print opt
    '''
    print opt_min
    print opt
    if opt[n-1][n-1] == -1:
        return -1
    else:
        return food - opt[n-1][n-1]
print answer(7,[[0, 2, 5], [1, 1, 3], [2, 1, 1]])
print answer(12, [[0, 2, 5], [1, 1, 3], [2, 1, 1]])
print answer(3,[[0, 2, 5], [1, 1, 3], [2, 1, 1]])
