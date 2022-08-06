def string_checker(string):

    vowels = 'aeiou'
    forbidden = ['ab', 'cd', 'pq', 'xy']

    check_1 = sum([string.count(vow) for vow in vowels]) > 2
    check_2 = sum([el in string for el in forbidden]) == 0
    check_3 = sum([a == b for a, b in zip(string, string[1:])]) > 0

    return check_1 and check_2 and check_3

counter = 0
with open('./input.txt', 'r') as file:
    while True:
        line = file.readline()
        if not line: break
        counter += string_checker(line)

print(counter)

