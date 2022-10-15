#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <exception>

template <typename Type> bool isValidPiece(Type &p) {
    std::cin >> p;
    if (toupper(p) == 'K') {
        return true;
    } else if (toupper(p) == 'Q') {
        return true;
    } else if (toupper(p) == 'R') {
        return true;
    } else if (toupper(p) == 'B') {
        return true;
    } else if (toupper(p) == 'N') {
        return true;
    } else if (toupper(p) == 'P') {
        return true;
    }

    std::cout << "Invalid piece." << std::endl;
    return false;
}

template <typename Type> bool isValidInput(Type &t) {
    try {
        std::cin >> t;
        return true;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
    return false;
}

#endif
