problem_input, new_seq = '1321131112', ''
seq_len, iters = 1, 50

for j in range(1, iters+1):
    problem_input += 'N'
    for i in range(len(problem_input)-1):
        if problem_input[i] == problem_input[i+1]:
            seq_len += 1
        else:
            new_seq += str(seq_len) + problem_input[i]
            seq_len = 1
    if j == 40:
        print(len(new_seq))
    if j != iters:
        problem_input = new_seq
        new_seq = ''
print(len(new_seq))

# 5447 ms ±  85 ms (10 runs, 2    warmup) - Python 3.10.5 (conda-forge)