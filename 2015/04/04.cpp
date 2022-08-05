#include <iostream>
#include <string>
#include "./md5/md5.h"

int main (void) {

    std::string problem_input = "ckczppom";
    std::string string_key, result;
    
    bool run_once = true;
    for (int i = 0; i < 10'000'000; i++) {

        string_key = problem_input + std::to_string(i);
        result = md5(string_key);

        if (run_once && result.substr(0, 5) == "00000") {
            run_once = false;
            std::cout << i << std::endl;
        }

        if (result.substr(0, 6) == "000000") {
            std::cout << i << std::endl;
            break;
        }
    }

}

