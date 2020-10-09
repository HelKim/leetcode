
#include <iostream>
#include "algorithm"
#include "problem/94.h"

int main() {
    Solution s;
    auto res = s.inorderTraversal(buildTree({1, null, 2, 3}));
    std::for_each(res.cbegin(), res.cend(), [](int x) { std::cout << x << ","; });

    return 0;
}
