//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_35_H
#define CPP_35_H

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                s = mid + 1;
            } else {
                if (mid > 0 && nums[mid - 1] >= target) e = mid - 1;
                else return mid;
            }
        }
        return s;
    }
};

#endif //CPP_35_H
