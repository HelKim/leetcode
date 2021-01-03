//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_239_H
#define CPP_239_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        unordered_map<int, int> window;
        int left = 0, right = 0;
        int max_val = INT_MIN;

        while (right < nums.size()) {
            window[nums[right]]++;
            max_val = max(max_val, nums[right++]);

            if (right - left == k) {
                res.push_back(max_val);
                window[nums[left]]--;
                if (nums[left] == max_val && window[nums[left]] == 0) {
                    max_val = find(left + 1, right - 1, nums);
                }
                ++left;
            }
        }

        return res;
    }

    int find(int s, int e, vector<int> &nums) {
        if (s > e) return INT_MIN;

        int max_val = nums[s];
        for (int i = s + 1; i <= e; ++i) max_val = max(max_val, nums[i]);
        return max_val;
    }
};

#endif //CPP_239_H
