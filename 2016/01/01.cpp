#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


int main (void) {

    std::string raw_input;
    std::fstream file;
    file.open("./input.txt", std::ios::in);
    if (file.is_open()) {
        while (getline(file, raw_input))
        file.close();
    };

    raw_input.erase(remove_if(raw_input.begin(), raw_input.end(), isspace), raw_input.end());

    std::stringstream ssinput {raw_input};
    std::string segment;
    std::vector<std::string> problem_input;
    while (std::getline(ssinput, segment, ',')) {
        problem_input.push_back(segment);
    }

    unsigned direction {0}; // 0N, 1E, 2S, 3W
    std::pair<int, int> coordinates {0, 0};
    std::vector<std::pair<int, int>> coordinates_history {coordinates};

    for (auto indication : problem_input) {
        
        if (indication[0] == 'R') direction++;
        if (indication[0] == 'L') direction--;

        if (direction == 4) direction = 0;
        if (direction == -1) direction = 3;

        switch (direction) {
            case 0:
                coordinates.second += std::stoi(indication.substr(1, indication.back()));
                break;
            case 1:
                coordinates.first += std::stoi(indication.substr(1, indication.back()));
                break;
            case 2:
                coordinates.second -= std::stoi(indication.substr(1, indication.back()));
                break;
            case 3:
                coordinates.first -= std::stoi(indication.substr(1, indication.back()));
                break;
        }
        
        std::pair<int, int> last_hist {coordinates_history.back()};
        if (coordinates.first == last_hist.first) {
            if (coordinates.second < last_hist.second) {
                for (int i {coordinates.second+1}; i < last_hist.second; i++) {
                    coordinates_history.push_back(std::pair<int, int> {coordinates.first, i});
                }
            } else {
                for (int i {last_hist.second+1}; i < coordinates.second; i++) {
                    coordinates_history.push_back(std::pair<int, int> {coordinates.first, i});
                }
            }
        }
        if (coordinates.second == last_hist.second) {
            if (coordinates.second == last_hist.second) {
                for (int i {coordinates.first+1}; i < last_hist.first; i++) {
                    coordinates_history.push_back(std::pair<int, int> {i, coordinates.second});
                }
            } else {
                for (int i {last_hist.first+1}; i < coordinates.first; i++) {
                    coordinates_history.push_back(std::pair<int, int> {i, coordinates.second});
                }
            }
        }

        coordinates_history.push_back(coordinates);
    }

    std::cout << std::abs(coordinates.first) + std::abs(coordinates.second) << std::endl;

    for (size_t i {0}; i < coordinates_history.size(); i++) {
        auto found {std::find(
            coordinates_history.begin()+i+1, coordinates_history.end(), coordinates_history[i]
            )};
        if (found != coordinates_history.end()) {
            std::cout << std::abs(found->first) + std::abs(found->second) << std::endl;
            break;
        }
    }
    
}

// 0.5 ms ± 0.8 ms (10k runs, 1k warmups) - Clang 14.0.6: clang++ -O3 -std=C++20