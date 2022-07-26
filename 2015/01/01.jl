open("./input.txt", "r") do file

    problem_input = collect(read(file, String))

    open_parentheses = count(c -> c == '(', problem_input)
    closed_parentheses = count(c -> c == ')', problem_input)

    println(open_parentheses - closed_parentheses)

end