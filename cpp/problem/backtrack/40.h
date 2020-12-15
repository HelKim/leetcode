//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_40_H
#define CPP_40_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(0, 0, candidates, target);
        return result;
    }

    void backtrack(int start, int sum, vector<int> &candidates, int target) {
        if (sum == target) {
            result.push_back(tmp);
            return;
        }
        if (sum > target) return;

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            tmp.push_back(candidates[i]);
            backtrack(i + 1, sum + candidates[i], candidates, target);
            tmp.pop_back();
        }
    }
};

#endif //CPP_40_H
