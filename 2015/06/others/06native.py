# an exact parallel of the C++ implementation just for benchmark the language

array_pt1 = [list(False for _ in range(1000)) for _ in range(1000)]
array_pt2 = [list(0 for _ in range(1000)) for _ in range(1000)]

with open('./input.txt', 'r') as file:
    while True:

        line = file.readline().split()
        if not line: break

        if 'on' in line:
            coord_start = [int(x) for x in line[2].split(',')]
            coord_end   = [int(x) for x in line[-1].split(',')]
            for i in range(coord_start[0], coord_end[0]+1):
                for j in range(coord_start[1], coord_end[1]+1):
                    array_pt1[i][j] = True
                    array_pt2[i][j] += 1
        if 'off' in line:
            coord_start = [int(x) for x in line[2].split(',')]
            coord_end   = [int(x) for x in line[-1].split(',')]
            for i in range(coord_start[0], coord_end[0]+1):
                for j in range(coord_start[1], coord_end[1]+1):
                    array_pt1[i][j] = False
                    if array_pt2[i][j] != 0:
                        array_pt2[i][j] -= 1
        if 'toggle' in line:
            coord_start = [int(x) for x in line[1].split(',')]
            coord_end   = [int(x) for x in line[-1].split(',')]
            for i in range(coord_start[0], coord_end[0]+1):
                for j in range(coord_start[1], coord_end[1]+1):
                    array_pt1[i][j] = not array_pt1[i][j]
                    array_pt2[i][j] += 2

print(sum([sum(sl) for sl in array_pt1]))
print(sum([sum(sl) for sl in array_pt2]))

# 2964 ms ±  335 ms (20 runs, 2 warmups) - Python 3.10.5 (conda-forge)