with open('./input.txt', 'r') as file:
    problem_input = [s.strip() for s in file.readlines()]

def calculate_wrapping_paper(x, y, z):
    x, y, z = int(x), int(y), int(z)
    surfaces = [x*y, y*z, z*x]
    return  2*sum(surfaces) + min(surfaces)

print(sum([calculate_wrapping_paper(*el.split('x')) for el in problem_input]))

# 14.1 ms ±  4.9 ms (1000 runs, 100 warmup) - Python 3.10.5 (conda-forge)