#include <iostream>
#include <fstream>
#include <array>
#include <vector>

int main (void) {

    std::array<std::array<int, 3>, 3> keyboard_0 {{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }};
    std::array<std::array<int, 5>, 5> keyboard_1 {{
        {0,  0,  1,  0,  0},
        {0,  2,  3,  4,  0},
        {5,  6,  7,  8,  9},
        {0, 10, 11, 12,  0},
        {0,  0, 13,  0,  0}
    }};
    std::pair<int, int> loc_0 {1, 1};
    std::pair<int, int> loc_1 {2, 0};
    std::vector<int> res_0 {};
    std::vector<int> res_1 {};    

    std::string instruction;
    std::fstream file;
    file.open("./input.txt", std::ios::in);
    if (file.is_open()) {

        while (getline(file, instruction)) {
            for (auto move : instruction) {
            
                auto loc_1_prev {loc_1};
            
                switch (move) {
                    case 'U':
                        loc_0.first--;
                        loc_1.first--;
                        break;
                    case 'D':
                        loc_0.first++;
                        loc_1.first++;
                        break;
                    case 'L':
                        loc_0.second--;
                        loc_1.second--;
                        break;
                    case 'R':
                        loc_0.second++;
                        loc_1.second++;
                        break;
                }
            
                if (loc_0.first  == -1) loc_0.first  = 0;
                if (loc_0.first  ==  3) loc_0.first  = 2;
                if (loc_0.second == -1) loc_0.second = 0;
                if (loc_0.second ==  3) loc_0.second = 2;

                if (loc_1.first  == -1) loc_1.first  = 0;
                if (loc_1.first  ==  5) loc_1.first  = 4;
                if (loc_1.second == -1) loc_1.second = 0;
                if (loc_1.second ==  5) loc_1.second = 4;

                if (keyboard_1[loc_1.first][loc_1.second] == 0) loc_1 = loc_1_prev;
            }
        
        res_0.push_back(keyboard_0[loc_0.first][loc_0.second]);
        res_1.push_back(keyboard_1[loc_1.first][loc_1.second]);
        }

        file.close();
    }

    for (const auto& el : res_0) {
        std::cout << std::hex << std::uppercase << el;
    }
    std::cout << std::endl;
    
    for (const auto& el : res_1) {
        std::cout << std::hex << std::uppercase << el;
    }
    std::cout << std::endl;

}

// 0.4 ms ± 0.6 ms (10k runs, 1k warmups) - Clang 14.0.6: clang++ -O3 -std=C++20