import numpy

array_pt1 = numpy.zeros((1000, 1000), dtype='bool')
array_pt2 = numpy.zeros((1000, 1000), dtype='int32')

with open('./input.txt', 'r') as file:
    while True:

        line = file.readline().split()
        if not line: break

        if 'on' in line:
            coord_start = [int(x) for x in line[2].split(',')]
            coord_end   = [int(x) for x in line[-1].split(',')]
            array_pt1[
                coord_start[0] : coord_end[0]+1,
                coord_start[1] : coord_end[1]+1
                ] = 1
            array_pt2[
                coord_start[0] : coord_end[0]+1,
                coord_start[1] : coord_end[1]+1
                ] += 1

        if 'off' in line:
            coord_start = [int(x) for x in line[2].split(',')]
            coord_end   = [int(x) for x in line[-1].split(',')]
            array_pt1[
                coord_start[0] : coord_end[0]+1,
                coord_start[1] : coord_end[1]+1
                ] = 0
            array_pt2[
                coord_start[0] : coord_end[0]+1,
                coord_start[1] : coord_end[1]+1
                ] -= 1
            array_pt2[array_pt2 < 0] = 0

        if 'toggle' in line:
            coord_start = [int(x) for x in line[1].split(',')]
            coord_end   = [int(x) for x in line[-1].split(',')]
            array_pt1[
                coord_start[0] : coord_end[0]+1,
                coord_start[1] : coord_end[1]+1
                ] = ~array_pt1[
                    coord_start[0] : coord_end[0]+1,
                    coord_start[1] : coord_end[1]+1
                    ]
            array_pt2[
                coord_start[0] : coord_end[0]+1,
                coord_start[1] : coord_end[1]+1
                ] += 2

print(sum(sum(array_pt1)))
print(sum(sum(array_pt2)))

# 124.2 ms ±  42.3 ms (100 runs, 10 warmup) - Python 3.10.5 (conda-forge)