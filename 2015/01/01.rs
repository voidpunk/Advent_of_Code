fn main() {

    let contents = std::fs::read_to_string("./input.txt").unwrap();

    let open_parentheses = contents.matches("(").count();
    let closed_parentheses = contents.matches(")").count();
    let difference = open_parentheses - closed_parentheses;

    println!("{}", difference);
}

// 0.3 ms ± 0.4 ms (10k runs, 1k warmup) - Rustc 1.66.0: -opt-level=3