import numpy as np

with open('./input.txt', 'r') as file:
    problem_input = file.read()

coordinates = [0, 0]
coordinates_list = [tuple(coordinates)]

for direction in problem_input:
    
    match direction:
        case 'v':
            coordinates[1] -= 1
        case '^':
            coordinates[1] += 1
        case '<':
            coordinates[0] -= 1
        case '>':
            coordinates[0] += 1
    
    coordinates_list.append(tuple(coordinates))

print(len(set(coordinates_list)))