
from itertools import permutations
from string import ascii_uppercase

with open('./input.txt', 'r') as file:
    problem_input = [line.split() for line in file.read().splitlines()]

name_map, distances = {}, {}
indexer = (x for x in ascii_uppercase)

for line in problem_input:
    if line[0] not in name_map.keys():
        name_map[line[0]] = next(indexer)
    if line[2] not in name_map.keys():
        name_map[line[2]] = next(indexer)

for line in problem_input:
    distances[name_map[line[0]] + name_map[line[2]]] = int(line[-1])

paths = {''.join(p) : 0 for p in set(permutations(set(''.join(distances.keys()))))}

for key in paths.keys():
    for k in (key[i:i+2] for i in range(0, len(key)-1, 1)):
        try:
            paths[key] += distances[k]
        except KeyError:
            paths[key] += distances[k[::-1]]

print(sorted(list(paths.values()))[0])
print(sorted(list(paths.values()))[-1])

# 176.7 ms ±  46.4 ms (1000 runs, 100 warmup) - Python 3.10.5 (conda-forge)