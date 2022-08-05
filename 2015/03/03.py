with open('./input.txt', 'r') as file:
    problem_input = file.read()


# Pt. 1

coordinates = [0, 0]
coordinates_list = [tuple(coordinates)]

for direction in problem_input:

    match direction:
        case '<':
            coordinates[0] -= 1
        case '>':
            coordinates[0] += 1
        case 'v':
            coordinates[1] -= 1
        case '^':
            coordinates[1] += 1
    
    coordinates_list.append(tuple(coordinates))

print(len(set(coordinates_list)))


# Pt. 2

coord_santa, coord_robot = [0, 0], [0, 0]
coordinates_list = [tuple(coord_santa), tuple(coord_robot)]

for sorter, direction in enumerate(problem_input, 1):

    coordinates = coord_santa if sorter % 2 != 0 else coord_robot

    match direction:
        case '<':
            coordinates[0] -= 1
        case '>':
            coordinates[0] += 1
        case 'v':
            coordinates[1] -= 1
        case '^':
            coordinates[1] += 1

    coordinates_list.append(tuple(coordinates))

print(len(set(coordinates_list)))