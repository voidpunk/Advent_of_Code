package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {

	raw_data, _ := os.ReadFile("./input.txt")
	problem_input := string(raw_data)

	open_parentheses := strings.Count(problem_input, "(")
	closed_parentheses := strings.Count(problem_input, ")")
	difference := open_parentheses - closed_parentheses
	
	fmt.Println(difference)

}