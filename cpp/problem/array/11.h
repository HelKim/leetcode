//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_11_H
#define CPP_11_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int p = 0;
        int q = height.size() - 1;

        int ans = 0;
        while (p < q) {
            ans = max(ans, (q - p) * min(height[p], height[q]));
            if (height[p] < height[q]) ++p;
            else --q;
        }

        return ans;
    }
};

#endif //CPP_11_H
