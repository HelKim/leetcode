
#include <iostream>
#include "algorithm"
#include "problem/107.h"

int main() {
    Solution s;
    auto result = s.levelOrderBottom(buildTree({3, 9, 20, null, null, 15, 7}));

    for (const auto &v : result) {
        for (const auto i : v) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
