//
// Created by zhengxiaojian on 2020/12/18.
//

#ifndef CPP_491_H
#define CPP_491_H

#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        dfs(0, nums);
        return res;
    }

    void dfs(int s, vector<int> &nums) {
        if (tmp.size() > 1) res.push_back(tmp);
        if (s == nums.size()) return;

        unordered_set<int> visit;
        for (int i = s; i < nums.size(); ++i) {
            if (!tmp.empty() && nums[i] < tmp.back()) continue;
            if (visit.count(nums[i])) continue;
            visit.insert(nums[i]);
            tmp.push_back(nums[i]);
            dfs(i + 1, nums);
            tmp.pop_back();
        }
    }
};

#endif //CPP_491_H
