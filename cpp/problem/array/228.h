//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_228_H
#define CPP_228_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return {to_string(nums[0])};

        vector<string> res;
        int s = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                res.push_back(i - 1 == s ? to_string(nums[s])
                                         : to_string(nums[s]) + "->" + to_string(nums[i - 1]));
                s = i;
            }
        }

        res.push_back(s == n - 1 ? to_string(nums[n - 1])
                                 : to_string(nums[s]) + "->" + to_string(nums[n - 1]));

        return res;
    }
};

#endif //CPP_228_H
