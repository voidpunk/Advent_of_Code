with open("./input.txt", 'r') as buffer:
    problem_input = buffer.readlines()

list_a = sorted([int(el.split()[0]) for el in problem_input])
list_b = sorted([int(el.split()[1].replace('\n', '')) for el in problem_input])

# Pt.1
print(sum([abs(list_a[i] - list_b[i]) for i in range(len(list_a))]))

# Pt.2
print(sum([list_a[i] * list_b.count(list_a[i]) for i in range(len(list_a))]))
