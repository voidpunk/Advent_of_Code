with open("./input.txt", "r") as file:
    problem_input = [x.strip() for x in file.readlines()]

keyboard_0 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
keyboard_1 = [
    [0,  0,  1,  0,  0],
    [0,  2,  3,  4,  0],
    [5,  6,  7,  8,  9],
    [0, 'A','B','C', 0],
    [0,  0, 'D', 0,  0]
]
loc_0 = [1, 1]
loc_1 = [2, 0]
res_0 = []
res_1 = []      

for instruction in problem_input:
    for move in instruction:

        loc_1_prev = loc_1.copy()

        match move:
            case 'U':
                loc_0[0] -= 1
                loc_1[0] -= 1
            case 'D':
                loc_0[0] += 1
                loc_1[0] += 1
            case 'L':
                loc_0[1] -= 1
                loc_1[1] -= 1
            case 'R':
                loc_0[1] += 1
                loc_1[1] += 1

        match loc_0[0]:
            case -1:
                loc_0[0] = 0
            case 3:
                loc_0[0] = 2
        match loc_0[1]:
            case -1:
                loc_0[1] = 0
            case 3:
                loc_0[1] = 2
        
        match loc_1[0]:
            case -1:
                loc_1[0] = 0
            case 5:
                loc_1[0] = 4
        match loc_1[1]:
            case -1:
                loc_1[1] = 0
            case 5:
                loc_1[1] = 4
        
        if keyboard_1[loc_1[0]][loc_1[1]] == 0:
            loc_1 = loc_1_prev

    res_0.append(str(keyboard_0[loc_0[0]][loc_0[1]]))
    res_1.append(str(keyboard_1[loc_1[0]][loc_1[1]]))

print("".join(res_0))
print("".join(res_1))

# 11.8 ms ±  1.1 ms (1k runs, 100 warmups) - Python 3.10.6 (conda-forge)