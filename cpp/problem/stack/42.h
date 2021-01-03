//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_42_H
#define CPP_42_H

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> lmax(n), rmax(n);
        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];

        for (int i = 1; i < height.size(); ++i) lmax[i] = max(lmax[i - 1], height[i]);
        for (int i = n - 2; i >= 0; --i) rmax[i] = max(rmax[i + 1], height[i]);

        int res = 0;

        for (int i = 1; i < n - 1; ++i) {
            res += min(lmax[i], rmax[i]) - height[i];
        }

        return res;
    }
};

#endif //CPP_42_H
