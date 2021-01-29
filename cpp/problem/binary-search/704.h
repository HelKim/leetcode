//
// Created by zhengxiaojian on 2021/1/28.
//

#ifndef CPP_704_H
#define CPP_704_H

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};

#endif //CPP_704_H
