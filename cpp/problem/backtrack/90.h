//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_90_H
#define CPP_90_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<bool> visit;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        visit.assign(nums.size(), false);
        backtrack(0, nums);
        return result;
    }

    void backtrack(int s, vector<int> &nums) {
        if (s == nums.size()) {
            result.push_back(tmp);
            return;
        }

        backtrack(s + 1, nums);
        if (s > 0 && nums[s] == nums[s - 1] && !visit[s - 1]) {
            return;
        } else {
            visit[s] = true;
            tmp.push_back(nums[s]);
            backtrack(s + 1, nums);
            tmp.pop_back();
            visit[s] = false;
        }
    }
};

#endif //CPP_90_H
