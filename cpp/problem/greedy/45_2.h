//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_45_2_H
#define CPP_45_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return 0;

        int s = 0;
        int pos = 0;
        while (pos < n) {
            int step = nums[pos];
            if (pos + step >= n - 1) {
                ++s;
                break;
            }

            int max_next_pos = pos;
            int next_pos = pos;

            int end = min(pos + step, n - 1);
            for (int i = pos + 1; i <= end; ++i) {
                if (nums[i] + i >= max_next_pos) {
                    max_next_pos = nums[i] + i;
                    next_pos = i;
                }
            }

            pos = next_pos;
            ++s;
        }

        return s;
    }
};

#endif //CPP_45_2_H
