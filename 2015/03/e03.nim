import std/sets
import std/enumerate

let problemInput = readFile("./input.txt")


# Pt. 1
var 
    coordinates = @[0, 0]
    coordinates_list = @[coordinates]

for direction in problem_input:
    case direction:
        of '<':
            coordinates[0] -= 1
        of '>':
            coordinates[0] += 1
        of 'v':
            coordinates[1] -= 1
        of '^':
            coordinates[1] += 1
        else:
            continue
    coordinates_list.add(coordinates)

echo len(coordinates_list.toHashSet())


# Pt. 2
var
    coord_santa = @[0, 0]
    coord_robot = @[0, 0]
coordinates_list = @[coord_santa, coord_robot]

for sorter, direction in enumerate(problem_input):
    var coordinates = if sorter mod 2 != 0: coord_santa.addr else: coord_robot.addr
    case direction:
        of '<':
            coordinates[0] -= 1
        of '>':
            coordinates[0] += 1
        of 'v':
            coordinates[1] -= 1
        of '^':
            coordinates[1] += 1
        else:
            continue
    coordinates_list.add(coordinates[])

echo len(coordinates_list.toHashSet())

# 1.1 ms ± 1.4 ms (10k runs, 1k warmup) - Nim 1.6.6 : -d:release 