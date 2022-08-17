#include <iostream>
#include <fstream>
#include <cctype>
#include <array>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>


char indexer (void);
unsigned int factorial(unsigned int);
std::vector<std::string> permute (std::string);


int main (void) {

    std::string data;
    std::ifstream infile;

    std::map<std::string, char> name_map;
    std::string to_permute;
    infile.open("./input.txt");
    while (infile.peek() != EOF) {
        infile >> data;
        if (data == "to" || data.length() == 1 || std::isdigit(data[0]))
            continue;
        if (name_map.find(data) == name_map.end()) {
            char idx {indexer()};
            to_permute += idx;
            name_map[data] = idx;
        }
    }
    infile.close();

    std::string key;
    std::map<std::string, unsigned> distances;
    infile.open("./input.txt");
    while (infile.peek() != EOF) {
        infile >> data;
        if (data == "to" || data[0] == '=')
            continue;
        if (!std::isdigit(data[0])) {
            key += name_map[data];
        }
        if (std::isdigit(data[0]) && key.length() == 2) {
            distances.insert({ key, std::stoi(data) });
            key = "";
        }
    }
    infile.close();

    auto permutations {permute(to_permute)};
    std::map<std::string, int> paths {};
    for (auto &el : permutations) {
        paths.insert({ el, 0 });
    }

    for (auto &item : paths) {
        for (int i {}; i <= item.first.length(); i++) {
            std::string k {item.first.substr(i, 2)};
            if (k.length() == 2) {
                if (distances.find(k) != distances.end()) {
                    paths[item.first] += distances[k];
                } else {
                    std::reverse(k.begin(), k.end());
                    paths[item.first] += distances[k];
                }
            }
        }
    }

    int min, max;
    min = max = paths[to_permute];
    for (auto &item : paths) {
        if (item.second < min) {
            min = item.second;
        }
        if (item.second > max) {
            max = item.second;
        }
    }
    std::cout << min << '\n' << max << std::endl;

}


char indexer (void) {
    static int ch {'A'-1};
    if (ch < 'Z') ch++;
    else ch = 'A';
    return static_cast<char>(ch);
}

unsigned factorial(unsigned num) {
    return (num == 1 || num == 0) ? 1: num * factorial(num - 1);
}

std::vector<std::string> permute (std::string str) {
    std::vector<std::string> permutations {};
    unsigned len {factorial(str.length())};
    permutations.reserve(len);
    do {
        permutations.push_back(str);
    } while (std::next_permutation(str.begin(), str.end()));
    return permutations;
}

// 45.2 ms ± 13.4 ms (10k runs, 1k warmup) - G++ 12.1.1: g++ -O3 -std=C++20