//
// Created by zhengxiaojian on 2020/12/13.
//

#ifndef CPP_15_H
#define CPP_15_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int s = nums[l] + nums[r];
                if (s == -nums[i]) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    int lnum = nums[l];
                    int rnum = nums[r];
                    while (l < r && nums[++l] == lnum);
                    while (l < r && nums[--r] == rnum);
                } else if (s > -nums[i]) --r;
                else ++l;
            }
        }
        return result;
    }
};

#endif //CPP_15_H
