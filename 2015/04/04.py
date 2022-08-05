import hashlib

problem_input='ckczppom'

run_once = True
for i in range(10_000_000):
    string_key = problem_input + str(i)
    result = hashlib.md5(string_key.encode()).hexdigest()

    # --------------------------------------------------------------------------
    # Pt. 1
    if run_once and result[:5] == '00000':
        run_once = False
        print(i)

    # --------------------------------------------------------------------------
    # Pt. 2
    if result[:6] == '000000':
        print(i)
        break