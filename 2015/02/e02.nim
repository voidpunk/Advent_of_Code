import std/strutils
import std/sequtils
import std/math

let problemInputRaw = readFile("./input.txt")
let problemInput = problemInputRaw.split("\n")

proc calculateWrappingPaper(sequence: seq[string]): int =
    let newSeq = sequence.mapIt(it.parseInt)
    let (x, y, z) = (newSeq[0], newSeq[1], newSeq[2])
    let surfaces = [x*y, y*z, z*x]
    return 2*sum(surfaces) + surfaces[minIndex(surfaces)]

var total = 0
for el in problemInput:
    total += calculateWrappingPaper(el.split("x"))
echo total

