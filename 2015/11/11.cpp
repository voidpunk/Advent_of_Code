#include <iostream>


bool check_pass(std::string);
std::string find_pass(std::string);


int main (void) {
    std::string problem_input {"hepxcrrq"};
    std::string new_pass_1 {find_pass(problem_input)};
    std::string new_pass_2 {find_pass(new_pass_1)};
    std::cout << new_pass_1 << std::endl << new_pass_2 << std::endl;
}


bool check_pass(std::string password) {
    bool doublet_0 {}, doublet_1 {}, sequence {};
    for (int i {0}; i < password.length(); i++) {
        if (i >= 2) {
            if (password[i-2] == password[i-1]-1 && password[i-1]-1 == password[i]-2) {
                sequence = true;
            }
            if (password[i-2] == password[i-1] && password[i-1] != password[i]) {
                doublet_0 = true;
                continue;
            }
            if (doublet_0) {
                if (
                    (password[i-2] == password[i-1] && password[i-1] != password[i])
                    ||
                    (password[i-1] == password[i] && i == password.length()-1)
                ) {
                    doublet_1 = true;
                }
            }
        }
    }
    return doublet_0 && doublet_1 && sequence;
}

std::string find_pass(std::string password) {
    int i {1};
    bool j {};
    size_t pass_len {password.length()};
    do {
        if (password[pass_len-i] == 'z') {
            password[pass_len-i] = 'a';
            i++;
            j = true;
            continue;
        }
        password[pass_len-i] = password[pass_len-i]+1;
        if (j) {
            i = 1;
            j = false;
        }
    } while (!check_pass(password));
    return password;
}

// 12.6 ms ± 0.7 ms (1000 runs, 10 warmups) - Clang 14.0.6: clang++ -O3 -std=C++20