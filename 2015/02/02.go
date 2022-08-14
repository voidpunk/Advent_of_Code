package main

import (
	"fmt"
	"os"
	"strings"
	"strconv"
)

func main() {

	raw_data, _ := os.ReadFile("./input.txt")
	problem_input := strings.Split(string(raw_data), "\n")

	total := 0
	for _, e := range problem_input {
		inputs := strings.Split(e, "x")
		total += calculateWrappingPaper(inputs)
	}

	fmt.Println(total)

}

func calculateWrappingPaper(inputs []string) int {
	x, _ := strconv.Atoi(inputs[0])
	y, _ := strconv.Atoi(inputs[1])
	z, _ := strconv.Atoi(inputs[2])
	surfaces := []int{x*y, y*z, z*x}
	return 2*sum(surfaces) + min(surfaces)
}

func sum(arr []int) int {
	res := 0
	for _, e := range arr {
		res += e
	}
	return res
}

func min(arr []int) int {
	res := arr[0]
	for _, e := range arr {
		if e < res {
			res = e
		}
	}
	return res
}

// 0.7 ms ± 0.6 ms (10k runs, 1k warmup) - Go 1.19: build