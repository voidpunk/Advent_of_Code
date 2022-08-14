#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <numeric>
#include <cctype>
#include <functional>


bool string_is_digit (std::string string);
void solver (void);

std::map<std::string, unsigned short> variables {};


int main (void) {
    solver();
    unsigned short a {variables["a"]};
    variables.clear();
    variables.insert({"b", a});
    solver();
}


bool string_is_digit (std::string string) {
    return std::all_of(string.begin(), string.end(), ::isdigit);
}

void solver (void) {
    std::ifstream file("./input.txt");
    std::string line;
    std::vector<std::vector<std::string>> problem_input;

    while (std::getline(file, line)) {
        std::stringstream stream_data(line);
        std::vector<std::string> line_vector;
        std::string stream_string;
        while (std::getline(stream_data, stream_string, ' ')) {
            line_vector.push_back(stream_string);
        }
        problem_input.push_back(line_vector);
    }

    std::vector<std::vector<std::string>> to_delete;
    for (size_t i {}; i < problem_input.size(); ++i) {
        auto line {problem_input[i]};
        if (string_is_digit(line[0]) && line[1] == "->") {
            if (variables.find(line.back()) == variables.end()) {
                variables.insert({line.back(), std::stoi(line[0])});
            }
            to_delete.push_back(problem_input[i]);
        }
    }
    for (auto el : to_delete) {
        problem_input.erase(
            std::remove(problem_input.begin(), problem_input.end(), el),
            problem_input.end()
            );
    }

    while (problem_input.size() > 0) {
        to_delete.clear();

        for (size_t i {}; i < problem_input.size(); ++i) {
            auto line {problem_input[i]};

            if ((
                string_is_digit(line.at(0)) || variables.find(line.at(0)) != variables.end()
                ) && (
                string_is_digit(line.at(2)) || variables.find(line.at(2)) != variables.end()
                ))
                {
                    unsigned short var_l {
                        string_is_digit(line.at(0)) ?
                        static_cast<unsigned short>(std::stoi(line.at(0))) : 
                        variables[line.at(0)]
                        };
                    unsigned short var_r {
                        string_is_digit(line.at(2)) ? 
                        static_cast<unsigned short>(std::stoi(line.at(2))) : 
                        variables[line.at(2)]
                        };
                    switch (line[1][0])
                    {
                    case 'A':
                        variables[line.back()] = var_l & var_r;
                        to_delete.push_back(problem_input.at(i));
                        break;
                    case 'O':
                        variables[line.back()] = var_l | var_r;
                        to_delete.push_back(problem_input.at(i));
                        break;
                    case 'R':
                        variables[line.back()] = var_l >> var_r;
                        to_delete.push_back(problem_input.at(i));
                        break;
                    case 'L':
                        variables[line.back()] = var_l << var_r;
                        to_delete.push_back(problem_input.at(i));
                        break;
                    }
                }
            
            if (
                line.at(0) == "NOT"
                &&
                (string_is_digit(line.at(1)) || variables.find(line.at(1)) != variables.end())
                )
                {
                    unsigned short var {
                        string_is_digit(line[1]) ?
                        static_cast<unsigned short>(std::stoi(line.at(1))) :
                        variables[line.at(1)]
                        };
                    variables[line.back()] = ~var;
                    to_delete.push_back(problem_input.at(i));
                }
            
            if (
                line.size() == 3
                && 
                variables.find(line.at(0)) != variables.end()
                ) {
                variables[line.back()] = variables[line.at(0)];
                to_delete.push_back(problem_input.at(i));
            }
        }

        for (auto el : to_delete) {
            problem_input.erase(
                std::remove(problem_input.begin(), problem_input.end(), el),
                problem_input.end()
            );
        }
    }
    std::cout << "a: " << variables["a"] << std::endl;
}

// 4.2 ms ± 0.4 ms (1k runs, 100 warmup) - G++ 12.1.1: g++ -O3 -std=C++20