#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <vector>


using std::string;

std::pair<int, int> read_cordinates (std::vector<string>, int);


int main (void) {

    std::ifstream file("./input.txt");
    string line;

    std::array<std::array<bool, 1000>, 1000> array_pt1 {};
    std::array<std::array<unsigned short, 1000>, 1000> array_pt2 {};

    while (std::getline(file, line)) {

        std::stringstream stream_data(line);
        std::vector<string> line_vector;
        string stream_string;

        while (std::getline(stream_data, stream_string, ' ')) {
            line_vector.push_back(stream_string);
        }

        if (line_vector[0] == "toggle") {

            std::pair<int, int> coord_start = read_cordinates(line_vector, 1);
            std::pair<int, int> coord_end = read_cordinates(line_vector, 3);
            std::pair<string, string> coord_str_start, coord_str_end;

            for (int i {coord_start.first}; i < coord_end.first+1; i++) {
                for (int j {coord_start.second}; j < coord_end.second+1; j++) {
                    array_pt1[i][j] = (array_pt1[i][j]) ? 0 : 1;
                    array_pt2[i][j] += 2;
                }
            }

        } else {

            std::pair<int, int> coord_start = read_cordinates(line_vector, 2);
            std::pair<int, int> coord_end = read_cordinates(line_vector, 4);
            std::pair<string, string> coord_str_start, coord_str_end;

            bool value {line_vector[1] == "on"};
            for (int i {coord_start.first}; i < coord_end.first+1; i++) {
                for (int j {coord_start.second}; j < coord_end.second+1; j++) {
                    array_pt1[i][j] = value;
                    if (!value && !array_pt2[i][j]) ++array_pt2[i][j];
                    (value) ? ++array_pt2[i][j] : --array_pt2[i][j];
                }
            }
        }
    }

    int sum_pt1 {}, sum_pt2 {};
    for (auto x : array_pt1) {
        for (auto y : x) {
            sum_pt1 += y;
        }
    }
    for (auto x : array_pt2) {
        for (auto y : x) {
            sum_pt2 += y;
        }
    }
    std::cout << sum_pt1 << std::endl;
    std::cout << sum_pt2 << std::endl;
}

std::pair<int, int> read_cordinates (std::vector<string> line, int position) {

    std::pair<string, string> coord_str;

    for (bool next {}; auto ch : line[position]) {
        if (ch == ',') {next = true; continue;}
        (!next) ? coord_str.first += ch : coord_str.second += ch;
    };

    std::pair<int, int> coord_int {
        std::stoi(coord_str.first),
        std::stoi(coord_str.second)
    };

    return coord_int;
}

// 3.2 ms ± 2.1 ms (1k runs, 10 warmup) - Clang 14.0.6: clang++ -O3 -std=C++20