use std::fs;

fn main() {

    let contents = fs::read_to_string("./input.txt")
        .expect("Something went wrong reading the file");

    let open_parentheses = contents.matches("(").count();
    let closed_parentheses = contents.matches(")").count();
    let difference = open_parentheses - closed_parentheses;

    println!("{}", difference);
}