//
// Created by zhengxiaojian on 2020/12/18.
//

#ifndef CPP_18_H
#define CPP_18_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        return nSum(4, 0, nums, target);
    }

    vector<vector<int>> nSum(int n, int s, vector<int> &nums, int target) {
        if (n < 2) return {};
        vector<vector<int>> res;

        if (n == 2) {
            int i = s;
            int j = nums.size() - 1;

            while (i < j) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    res.push_back({nums[i], nums[j]});
                    ++i;
                    --j;
                    while (i < j && nums[i] == nums[i - 1]) ++i;
                    while (i < j && nums[j] == nums[j + 1]) --j;
                } else if (sum < target) ++i;
                else --j;
            }
        } else {
            int i = s;
            while (i < nums.size()) {
                int new_target = target - nums[i];
                auto sum = nSum(n - 1, i + 1, nums, new_target);
                for (auto &num : sum) {
                    num.push_back(nums[i]);
                    res.push_back(num);
                }
                ++i;
                while (i < nums.size() && nums[i] == nums[i - 1]) ++i;
            }
        }

        return res;
    }
};

#endif //CPP_18_H
