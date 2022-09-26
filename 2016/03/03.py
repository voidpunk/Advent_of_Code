with open("./input.txt", 'r') as file:
    problem_data = [x.split() for x in file.readlines()]

def check_triangle(x, y, z):
    x, y, z = int(x), int(y), int(z)
    return x + y > z and y + z > x and z + x > y

sol_0, sol_1 = 0, 0
for i, row in enumerate(problem_data):
    sol_0 += check_triangle(*[int(x) for x in row])
    if i % 3 == 0:
        sol_1 += (
            check_triangle(problem_data[i][0], problem_data[i+1][0], problem_data[i+2][0]) +
            check_triangle(problem_data[i][1], problem_data[i+1][1], problem_data[i+2][1]) +
            check_triangle(problem_data[i][2], problem_data[i+1][2], problem_data[i+2][2])
        )

print(sol_0)
print(sol_1)

# 13.6 ms ±  0.9 ms (1k runs, 100 warmups) - Python 3.10.6 (conda-forge)