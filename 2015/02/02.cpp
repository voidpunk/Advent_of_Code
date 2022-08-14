#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <numeric>


int calculateWrappingPaper(std::vector<std::string> vector);


int main (void) {

    std::string problem_input;
    std::fstream file;
    file.open("./input.txt", std::ios::in);
    int total = 0;

    if (file.is_open()) {

        while (getline(file, problem_input)) {

            std::stringstream stream_input(problem_input);
            std::string segment;
            std::vector<std::string> segment_list;

            while (getline(stream_input, segment, 'x')) {
                segment_list.push_back(segment);
            }

            int result = calculateWrappingPaper(segment_list);
            total += result;
        }
        file.close();

        std::cout << total << std::endl;
    };

}


int calculateWrappingPaper(std::vector<std::string> stringVector) {

    std::vector<int> intVector;
    std::string* stringArray = stringVector.data();

    int x = std::stoi(stringArray[0]);
    int y = std::stoi(stringArray[1]);
    int z = std::stoi(stringArray[2]);

    int surfaces[3] = {x*y, y*z, z*x};

    int n = sizeof(surfaces) / sizeof(int);

    auto min = std::min_element(surfaces, surfaces + n);
    int surface = std::accumulate(surfaces, surfaces + n, 0);

    int total = 2*surface + *min;

    return total;
}

// 0.7 ms ± 0.9 ms (10k runs, 1k warmup) - Clang 14.0.6: clang++ -O3 -std=C++20