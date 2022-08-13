variables = {}

def solver():

    global variables
    with open('./input.txt', 'r') as file:
        problem_input = [line.split() for line in file.read().split('\n')]

    to_delete = []
    for line in problem_input:
        if line[0].isdigit() and line[1] == '->':
            if line[-1] not in variables.keys():
                variables[line[-1]] = int(line[0])
            to_delete.append(line)
    for el in to_delete:
        problem_input.remove(el)

    while len(problem_input) > 0:
        to_delete = []
        for line in problem_input:
            if ((line[0].isdigit() or line[0] in variables.keys()) and 
                (line[2].isdigit() or line[2] in variables.keys())
                ):
                var_l = int(line[0]) if line[0].isdigit() else variables[line[0]]
                var_r = int(line[2]) if line[2].isdigit() else variables[line[2]]
                match line[1]:
                    case 'AND':
                        variables[line[-1]] = var_l & var_r
                        to_delete.append(line)
                    case 'OR':
                        variables[line[-1]] = var_l | var_r
                        to_delete.append(line)
                    case 'RSHIFT':
                        variables[line[-1]] = var_l >> var_r
                        to_delete.append(line)
                    case 'LSHIFT':
                        variables[line[-1]] = var_l << var_r
                        to_delete.append(line)
            if (line[0] == 'NOT' and (line[1].isdigit() or line[1] in variables.keys())):
                    var = int(line[1]) if line[1].isdigit() else variables[line[1]]
                    variables[line[-1]] = ~var
                    to_delete.append(line)
            if len(line) == 3 and line[0] in variables.keys():
                variables[line[-1]] = variables[line[0]]
                to_delete.append(line)
        for el in to_delete:
            problem_input.remove(el)

    print('a:', variables['a'] & 0xFFFF)

solver()
variables = {'b': variables['a']}
solver()

# 19.1 ms ±  6.1 ms (1000 runs, 100 warmup) - Python 3.10.5 (conda-forge)