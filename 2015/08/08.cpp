#include <iostream>
#include <fstream>
#include <array>


int main (void) {

    std::ifstream file("./input.txt");
    std::string line;
    unsigned to_sub {0}, to_add {0};

    while (std::getline(file, line)) {

        for (size_t i {}; i < line.length(); ++i) {
            if (line[i] == '\\' && i+1 != line.length()) {
                if (line[i+1] == '\\') {
                    to_sub += 1;
                    to_add += 2;
                    i++;
                } else if (line[i+1] == 'x') {
                    to_sub += 3;
                    to_add += 1;
                }
            }
            if (line[i] == '"') {
                to_sub += 1;
                to_add += 2;
            }
        }
    }

    std::cout << to_sub << std::endl << to_add << std::endl;

}

// 0.1 ms ± 0.3 ms (10k runs, 1k warmup) - Clang 14.0.6: clang++ -O3 -std=C++20