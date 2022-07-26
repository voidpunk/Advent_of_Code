import std/strutils

let problemInput = readFile("./input.txt")
echo count(problemInput, "(") - count(problemInput, ")")

