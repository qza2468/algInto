//
// Created by qza2468 on 2025/12/22.
//

#include "utils.h"

#include <iostream>

void printVector(const std::vector<int> &v) {
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
