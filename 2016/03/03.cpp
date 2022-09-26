#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>


bool check_triangle (int, int, int);
std::array<int, 3> make_array (std::string string);


int main (void) {

    std::vector<std::array<int, 3>> problem_data;
    std::string temp_string;
    std::fstream file;

    file.open("./input.txt", std::ios::in);
    if (file.is_open()) {
        while (getline(file, temp_string)) {
            problem_data.push_back(make_array(temp_string));
        }
        file.close();
    }

    int sol_0 {}, sol_1 {};
    for (int i {}; i < problem_data.size(); i++) {
        sol_0 += check_triangle(problem_data[i][0], problem_data[i][1], problem_data[i][2]);
        if (i % 3 == 0) {
            sol_1 += 
                check_triangle(problem_data[i][0], problem_data[i+1][0], problem_data[i+2][0]) +
                check_triangle(problem_data[i][1], problem_data[i+1][1], problem_data[i+2][1]) +
                check_triangle(problem_data[i][2], problem_data[i+1][2], problem_data[i+2][2])
                ;
        }
    }

    std::cout << sol_0 << std::endl << sol_1 << std::endl;
}


bool check_triangle (int x, int y, int z) {
    return (x + y > z && y + z > x && z + x > y);
}


std::array<int, 3> make_array (std::string temp_string) {

    std::array<int, 3> array {};
    std::stringstream ssinput {temp_string};
    std::string segment {};

    for (int i {}; std::getline(ssinput, segment, ' ');) {
        if (segment != "") {
            array[i] = std::stoi(segment);
            i++;
        }
    }

    return array;
}

// 1.0 ms ± 0.6 ms (10k runs, 1k warmups) - Clang 14.0.6: clang++ -O3 -std=C++20