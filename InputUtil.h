#ifndef INPUT_UTIL_H
#define INPUT_UTIL_H

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

inline int getValidInt(const std::string& prompt) {
    int val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val) {
            // Consume the remaining characters on the line including newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return val;
        } else {
            std::cout << "Invalid input! Please enter a valid number.\n";
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
        }
    }
}

inline std::string getValidString(const std::string& prompt) {
    std::string val;
    std::cout << prompt;
    std::cin >> std::ws; // Consume leading whitespace/newlines
    std::getline(std::cin, val);
    return val;
}

#endif
