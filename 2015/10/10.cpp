#include <iostream>


int main (void) {

    std::string problem_input {"1321131112"}, new_seq {};
    int seq_len {1}, iters {50};

    for (int j {1}; j <= iters; j++) {
        problem_input += 'N';
        for (int i {}; i < problem_input.length()-1; i++){
            if (problem_input[i] == problem_input[i+1]) {
                seq_len++;
            }
            else {
                new_seq += std::to_string(seq_len) + problem_input[i];
                seq_len = 1;
            }
        }
        if (j == 40) {
            std::cout << new_seq.length() << std::endl;
        }
        if (j != iters) {
            problem_input = new_seq;
            new_seq = "";
        }
    }
    std::cout << new_seq.length() << std::endl;

}

// 174.9 ms ± 3.7 ms (100 runs, 10 warmup) - G++ 12.1.1: g++ -O3 -std=C++20