//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_42_2_H
#define CPP_42_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int res = 0;
        int l_max = height[0];
        int r_max = height[n - 1];

        while (left <= right) {
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);

            if (l_max < r_max) {
                res += l_max - height[left];
                ++left;
            } else {
                res += r_max - height[right];
                --right;
            }
        }

        return res;
    }
};

#endif //CPP_42_2_H
