#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <set>


int main (void) {

    std::string problem_input;
    std::fstream file;

    file.open("./input.txt", std::ios::in);

    if (file.is_open()) {
        while (getline(file, problem_input)) {}
        file.close();
    };

    std::pair<int, int> coordinates (0, 0);
    std::vector<std::pair<int, int>> coordinates_list;
    coordinates_list.push_back(coordinates);

    for (int i = 0; i < problem_input.length(); i++) {

        switch (problem_input[i]) {
            case '<':
                coordinates.first  -= 1;
                break;
            case '>':
                coordinates.first  += 1;         
                break;
            case 'v':
                coordinates.second -= 1;
                break;
            case '^':
                coordinates.second += 1;
                break;
        }

        coordinates_list.push_back(coordinates);

    }

    std::set<std::pair<int, int>> coordinates_set(coordinates_list.begin(), coordinates_list.end());
    coordinates_list.assign(coordinates_set.begin(), coordinates_set.end());

    std::cout << coordinates_set.size() << std::endl;

}