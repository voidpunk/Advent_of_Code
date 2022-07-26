#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


int main (void) {

    std::string problem_input;
    std::fstream file;

    file.open("./input.txt", std::ios::in);

    if (file.is_open()) {
        while (getline(file, problem_input)) {}
        file.close();
    };

    int open_parentheses = std::count(
        problem_input.begin(), problem_input.end(), '('
    );
    int closed_parentheses = std::count(
        problem_input.begin(), problem_input.end(), ')'
    );

    int difference = open_parentheses - closed_parentheses;

    std::cout << difference << std::endl;

}