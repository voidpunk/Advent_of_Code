with open('./input.txt', 'r') as file:
    problem_input = file.read()

print(problem_input.count('(') - problem_input.count(')'))