// rust-crypto = "^0.2"

use crypto::digest::Digest;

fn main() {

    let problem_input = "ckczppom";
    let mut run_once = true;
    let mut hasher = crypto::md5::Md5::new();

    for i in 0..10_000_000 {
        let string_key = problem_input.to_string() + &i.to_string();
        hasher.input(string_key.as_bytes());
        let result = hasher.result_str();
        hasher.reset();

        // Pt. 1
        if run_once && &result[..5] == "00000" {
            run_once = false;
            println!("{i}");
        }

        // Pt. 2
        if &result[..6] == "000000" {
            println!("{i}");
            return;
        }

    }

}

// 837.3 ms ± 19.1 ms (50 runs, 25 warmup) - Rustc 1.66.0: -opt-level=3
