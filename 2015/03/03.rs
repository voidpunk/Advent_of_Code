fn main() {

    let problem_input = std::fs::read_to_string("./input.txt").unwrap();

    // Pt. 1
    let mut coordinates = (0, 0);
    let mut coordinates_list = vec![coordinates];
    
    for direction in problem_input.chars() {
        match direction {
            '<' => coordinates.0 -= 1,
            '>' => coordinates.0 += 1,
            'v' => coordinates.1 -= 1,
            '^' => coordinates.1 += 1,
            _   => panic!()
        }
        coordinates_list.push(coordinates);
    }

    coordinates_list.sort();
    coordinates_list.dedup();
    println!("{}", coordinates_list.len());


    // Pt. 2
    let mut coordinates_santa = (0, 0);
    let mut coordinates_robot = (0, 0);
    let mut coordinates_list = vec![coordinates_santa, coordinates_robot];

    for (sorter, direction) in problem_input.char_indices() {
        let mut coordinates = if sorter % 2 == 0 {&mut coordinates_santa} else {&mut coordinates_robot};
        match direction {
            '<' => coordinates.0 -= 1,
            '>' => coordinates.0 += 1,
            'v' => coordinates.1 -= 1,
            '^' => coordinates.1 += 1,
            _   => panic!()
        }
        coordinates_list.push(*coordinates);
    }

    coordinates_list.sort();
    coordinates_list.dedup();
    println!("{}", coordinates_list.len());

}

// 0.5 ms ± 1.0 ms (10k runs, 1k warmup) - Rustc 1.66.0: -opt-level=3