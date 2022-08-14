use std::fs;

fn main() {

    let contents = fs::read_to_string("./input.txt")
        .expect("Something went wrong reading the file");
    let vec_inputs = contents.split("\n").collect::<Vec<&str>>();

    let mut acc = 0;
    for el in vec_inputs {

        let vec_row = el.split("x").collect::<Vec<&str>>();
        let a: i32 = vec_row[0].parse().unwrap();
        let b: i32 = vec_row[1].parse().unwrap();
        let c: i32 = vec_row[2].parse().unwrap();

        let res = calculate_wrapping_paper(a, b, c);
        acc += res;
    }
    println!("{}", acc);
}

fn calculate_wrapping_paper(a: i32, b: i32, c: i32) -> i32 {
    let surfaces = [a*b, b*c, c*a];
    let min = surfaces.iter().min().unwrap();
    let sum: i32 = surfaces.iter().sum();
    return 2*sum + min
}

// 0.5 ms ± 0.6 ms (10k runs, 1k warmup) - Rustc 1.61.0: -opt-level=3