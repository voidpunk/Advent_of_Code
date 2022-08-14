import std/md5
import std/strutils

const problem_input = "ckczppom"

var run_once = true
for i in 0 .. 10_000_000:
    let string_key = problem_input & intToStr(i)
    let result = getMD5(string_key)

    # Pt. 1
    if (run_once and result[0..4] == "00000"):
        run_once = false
        echo i

    # Pt. 2
    if result[0..5] == "000000":
        echo i
        break

# 1257 ms ±  12 ms (20 runs, 10 warmup) - Nim 1.6.6: nim c -d:release