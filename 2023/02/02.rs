use std::fs::File;
use std::io::{prelude::*, BufReader};

fn main() {
    let reader = BufReader::new(File::open("./input.txt").unwrap());
    let target_cubes = Cubes {
        r: 12,
        g: 13,
        b: 14,
    };
    let (mut power, mut res) = (0, 0);
    for line in reader.lines().flatten() {
        let (id, cubes) = parse_line(&line);
        power += cubes.r * cubes.g * cubes.b;
        if cubes.r <= target_cubes.r && cubes.g <= target_cubes.g && cubes.b <= target_cubes.b {
            res += id;
        }
    }
    println!("{res}");
    println!("{power}");
}

struct Cubes {
    r: i32,
    g: i32,
    b: i32,
}

fn parse_line(line: &str) -> (i32, Cubes) {
    let data: Vec<_> = line.split(':').collect();
    let id: i32 = data[0].split(' ').last().unwrap().parse().unwrap();
    let data: Vec<_> = data[1]
        .split(|c| c == ',' || c == ';')
        .into_iter()
        .map(|s| s.trim())
        .collect();
    let (mut r, mut b, mut g) = (0, 0, 0);
    for val in data.iter() {
        let v: i32 = val.split(' ').next().unwrap().parse().unwrap();
        match val.split(' ').last().unwrap() {
            "red" => {
                if v > r {
                    r = v;
                }
            }
            "blue" => {
                if v > b {
                    b = v;
                }
            }
            "green" => {
                if v > g {
                    g = v;
                }
            }
            _ => panic!(),
        }
    }
    (id, Cubes { r, g, b })
}
