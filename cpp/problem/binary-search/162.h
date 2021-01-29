//
// Created by zhengxiaojian on 2021/1/28.
//

#ifndef CPP_162_H
#define CPP_162_H

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() == 1) return 0;

        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isTop(nums, mid)) return mid;
            if (mid == 0 || nums[mid - 1] < nums[mid]) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }

    bool isTop(vector<int> &nums, int mid) {
        if (mid == 0) return nums[0] > nums[1];
        if (mid == nums.size() - 1) return nums[mid] > nums[mid - 1];
        return nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1];
    }
};

#endif //CPP_162_H
