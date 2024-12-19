use std::fs::File;
use std::io::{prelude::*, BufReader};

fn main() {
    let reader = BufReader::new(File::open("./input.txt").unwrap());

    let (mut result_p1, mut result_p2) = (0, 0);
    for line in reader.lines().flatten() {
        result_p1 += line_to_number(&line, false);
        result_p2 += line_to_number(&line, true);
    }
    println!("{result_p1}");
    println!("{result_p2}");
}

fn line_to_number(line: &str, pt_2: bool) -> u32 {
    let written_numbers = [
        "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    ];
    let mut string_buffer = String::new();
    let (mut first, mut second): (char, char) = ('0', '0');
    for char in line.chars() {
        if char.is_numeric() {
            first = char;
            break;
        } else if pt_2 {
            string_buffer.push(char);
            let index = written_numbers
                .iter()
                .position(|&r| string_buffer.contains(r));
            if let Some(index) = index {
                first = ((index + 1) as u8 + b'0') as char;
                string_buffer.clear();
                break;
            }
        }
    }
    for char in line.chars().rev() {
        if char.is_numeric() {
            second = char;
            break;
        } else if pt_2 {
            string_buffer.push(char);
            let index = written_numbers
                .iter()
                .position(|&r| string_buffer.chars().rev().collect::<String>().contains(r));
            if let Some(index) = index {
                second = ((index + 1) as u8 + b'0') as char;
                string_buffer.clear();
                break;
            }
        }
    }
    let res: u32 = format!("{first}{second}").parse().unwrap();
    res
}
