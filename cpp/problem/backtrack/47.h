//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_47_H
#define CPP_47_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<bool> visit;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        visit.assign(nums.size(), false);
        backtrack(nums);
        return result;
    }

    void backtrack(vector<int> &nums) {
        if (tmp.size() == nums.size()) {
            result.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visit[i]) continue;
            if (i > 0 && !visit[i - 1] && nums[i] == nums[i - 1]) continue;
            visit[i] = true;
            tmp.push_back(nums[i]);
            backtrack(nums);
            visit[i] = false;
            tmp.pop_back();
        }
    }
};

#endif //CPP_47_H
