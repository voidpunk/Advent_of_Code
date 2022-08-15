to_sub, to_add = 0, 0
with open('./input.txt', 'r') as file:
    while True:

        line = file.readline().rstrip()
        if not line: break

        to_sub += len(line) - len(eval(line))
        to_add += line.count('\\') + line.count('"') + 2

print(to_sub)
print(to_add)

# 12.8 ms ±  5.0 ms (1000 runs, 100 warmup) - Python 3.10.5 (conda-forge)