#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <algorithm>


bool string_checker (std::string);


int main (void) {

    std::ifstream file("./input.txt");
    std::string line;
    int counter = 0;

    while (std::getline(file, line)) {
        counter += string_checker(line);
    }

    std::cout << counter << std::endl;

}


bool string_checker (std::string line) {
    
    std::array<char, 5> vowels = {'a', 'e', 'i', 'o', 'u'};
    std::array<std::string, 4> forbidden = {"ab", "cd", "pq", "xy"};

    bool check_vowels = false;
    bool check_forbidden = false;
    bool check_double = false;

    int counter_vowels = 0;
    for (int i = 0; i < vowels.size(); i++) {
        counter_vowels += std::count(line.begin(), line.end(), vowels[i]);
        if (counter_vowels > 2) {
            check_vowels = true;
            break;
        }
    }

    for (int i = 0; i < forbidden.size(); i++) {
        if (line.find(forbidden[i]) != std::string::npos) {
            check_forbidden = true;
            break;
        }
    }

    for (int i = 0; i < line.length()-1; i++) {
        if (line[i] == line[i+1]) {
            check_double = true;
            break;
            }
        }

    return check_vowels && !check_forbidden && check_double;
}