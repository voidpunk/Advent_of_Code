with open("./input.txt", "r") as file:
    problem_input = [x.strip() for x in file.read().split(',')]

direction = 0 # 0N, 1E, 2S, 3W
coordinates = [0, 0]
coordinates_history = [str(coordinates)]

for indication in problem_input:

    if indication[0] == 'R':
        direction += 1
    if indication[0] == 'L':
        direction -= 1

    if direction == 4:
        direction = 0
    if direction == -1:
        direction = 3

    match direction:
        case 0:
            coordinates[1] += int(indication[1:])
        case 1:
            coordinates[0] += int(indication[1:])
        case 2:
            coordinates[1] -= int(indication[1:])
        case 3:
            coordinates[0] -= int(indication[1:])

    last_hist = eval(coordinates_history[-1])
    if coordinates[0] == last_hist[0]:
        if coordinates[1] < last_hist[1]:
            for i in range(coordinates[1]+1, last_hist[1]):
                coordinates_history.append(str([coordinates[0], i]))
        else:
            for i in range(last_hist[1]+1, coordinates[1]):
                coordinates_history.append(str([coordinates[0], i]))
    if coordinates[1] == last_hist[1]:
        if coordinates[0] < last_hist[0]:
            for i in range(coordinates[0]+1, last_hist[0]):
                coordinates_history.append(str([i, coordinates[1]]))
        else:
            for i in range(last_hist[0]+1, coordinates[0]):
                coordinates_history.append(str([i, coordinates[1]]))
    
    coordinates_history.append(str(coordinates))

print(abs(coordinates[0]) + abs(coordinates[1]))

for idx, el in enumerate(coordinates_history):
    if el in coordinates_history[idx+1:]:
        print(abs(eval(el)[0]) + abs(eval(el)[1]))
        break

# 12.7 ms ±  1.0 ms (1k runs, 100 warmups) - Python 3.10.6 (conda-forge)