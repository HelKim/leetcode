//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_34_H
#define CPP_34_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        return {find_first(nums, target), find_last(nums, target)};
    }

    int find_first(vector<int> &nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target)) return mid;
            if (nums[mid] < target) s = s + 1;
            else e = mid - 1;
        }
        return -1;
    }

    int find_last(vector<int> &nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] > target)) return mid;
            if (nums[mid] <= target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
};

#endif //CPP_34_H
