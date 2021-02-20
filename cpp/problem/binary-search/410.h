//
// Created by zhengxiaojian on 2021/2/2.
//

#ifndef CPP_410_H
#define CPP_410_H

#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        int left = 0, right = 0;
        for (auto n : nums) {
            right += n;
            if (n > left) left = n;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit2(nums, m, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool canSplit(vector<int> &nums, int m, int maxN) {
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            if (s > maxN) {
                --m;
                --i;
                s = 0;
            }
            if (m < 1) return false;
        }
        return m >= 1;
    }

    bool canSplit2(vector<int> &nums, int m, int maxN) {
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            if (s > maxN) {
                s = nums[i];
                --m;
            }
        }
        return m > 0;
    }
};

#endif //CPP_410_H
