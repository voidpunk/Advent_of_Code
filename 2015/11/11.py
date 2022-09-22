def check_pass(string, delay=False):
    if delay:
        return False
    doublet_0, doublet_1, sequence = False, False, False
    for i in range(len(string)):
        if i >= 2:
            if ord(string[i-2]) == ord(string[i-1])-1 == ord(string[i])-2:
                sequence = True
            if string[i-2] == string[i-1] and string[i-1] != string[i]:
                doublet_0 = True
                continue
            if doublet_0:
                if (
                    string[i-2] == string[i-1] and string[i-1] != string[i]
                    ) or (
                    string[i-1] == string[i] and i == len(string)-1
                    ):
                        doublet_1 = True
    return doublet_0 and doublet_1 and sequence


def find_pass(password, delay=False):
    i, j = 1, 0
    while not check_pass(password, delay):
        if delay:
            delay = False
        password = list(password)
        if ord(password[-i]) == ord("z"):
            password[-i] = "a"
            password = "".join(password)
            i += 1
            j = True
            continue
        password[-i] = chr(ord(password[-i])+1)
        if j:
            i = 1
            j = False
        password = "".join(password)
    return password


problem_input = 'hepxcrrq'
new_pass_1 = find_pass(problem_input)
new_pass_2 = find_pass(new_pass_1, True)
print(new_pass_1)
print(new_pass_2)

# 2071 ms ±  34 ms (20 runs, 5 warmups) - Python 3.10.6 (conda-forge)