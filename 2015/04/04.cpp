#include <iostream>
#include <string>
#include "./md5/md5.h"

int main (void) {

    std::string problem_input = "ckczppom";
    std::string string_key, result;
    
    bool run_once = true;
    for (unsigned int i = 0; i < 10'000'000; i++) {

        string_key = problem_input + std::to_string(i);
        result = md5(string_key);

        // Pt. 1
        if (run_once && result.substr(0, 5) == "00000") {
            run_once = false;
            std::cout << i << std::endl;
        }

        // Pt. 2
        if (result.substr(0, 6) == "000000") {
            std::cout << i << std::endl;
            break;
        }
    }

}

// 3489 ms ± 584 ms (20 runs, 10 warmup) - Clang 14.0.6: clang++ -Ofast -std=C++20